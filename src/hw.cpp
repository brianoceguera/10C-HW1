/* *************************************
Brian Oceguera
File: hw.cpp
Description: A program that simulates a game of Siete y Medio for the user. User plays against a dealer.
	Makes use of the Card, Hand, Player classes.
************************************* */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include "cards.h"

using namespace std;

enum outcome_t { WIN, LOSE, HOUSE_ADVANTAGE, TIE };

//******* Global constants *******//
const double SIETE_Y_MEDIO = 7.5;
const double DEALER_DRAWS_UNDER = 5.5;


//******* Non member function declarations *******//
bool programRun(double player_money, double dealer_money);
bool bust(Hand a);
bool validInput(double i, Player p);
void playerDraw(Hand& a);
void writeToGameLog(ofstream& file, Player p, Player d, const Hand& player1, const Hand& dealer, int n, double b);
void updatePlayerMoney(Player& p, double bet);
double distanceFromSieteYMedio(Hand a);
outcome_t declareWinner(Hand player1, Hand dealer);


//******* Non member function implementations *******//

/**
	programRun()
		Description: Checks conditions for the simulation to run.
		@param1: The player's money.
		@param2: The dealer's money.
		@return: boolean

*/
bool programRun(double player_money, double dealer_money){

	if (player_money <= 0 || dealer_money <= 0)
		return false;
	else
		return true;
}


/**
	bust()
		Description: Checks if a player busts. This means his total card value is > 7.5
		@param1: A Hand. (Either player or dealer)
		@return: boolean

*/
bool bust(Hand a){

	if (a.sum() > SIETE_Y_MEDIO)
		return true;
	else
		return false;
}


/**
validInput()
	Description: Checks if a player entered a impossible bet.
		@param1: A bet.
		@param2: Player p.
		@return: boolean

*/
bool validInput(double i, Player p){

	if (i <= 0 || i > p.get_money())
		return false;

	else
		return true;
}


/**
playerDraw()
	Description: Draws a card for the player.
		@param1: A Hand. Passed by reference.
		@return: boolean

*/
void playerDraw(Hand& a){

	a.draw_card();

	return;
}


/**
updatePlayerMoney()
	Description: Updates the money held by a player.
		@param1: A Player. Passed by reference.
		@param2: Money.
		@return: None.

*/
void updatePlayerMoney(Player& p, double bet){

	p.update_money(bet);

	return;
}


/**
distanceFromSieteYMedio()
	Description: Calculates how close a player's hand is from SIETE Y MEDIO.
		@param1: A Hand.
		@return: Absolute value of distance away from 7.5.

*/
double distanceFromSieteYMedio(Hand a){

	return abs(a.sum() - SIETE_Y_MEDIO); //removed abs
}


/**
declareWinner()
	Description: Checks conditions and declares a winner of the round.
		@param1: A Player's Hand.
		@param2: The dealer's Hand.
		@return: enumerated type

*/
outcome_t declareWinner(Hand player1, Hand dealer){
	
	if (bust(player1) == true && bust(dealer) == true)
		return HOUSE_ADVANTAGE;

	else if (bust(player1) == true)
		return LOSE;

	else if (bust(dealer) == true)
		return WIN;

	else if (distanceFromSieteYMedio(player1) > distanceFromSieteYMedio(dealer))
		return LOSE;

	else if (distanceFromSieteYMedio(player1) < distanceFromSieteYMedio(dealer))
		return WIN;

	else
		return TIE;

}


/**
	writeToGameLog()
		Description: Opens a file for writing and records the final hands of each player at the end of a round.
			Also records the game number, the player's money, and the bet.
		@param1: ofstream fout.
		@param2: Player.
		@param3: Dealer.
		@param4: Player's Hand.
		@param5: Dealer's Hand.
		@param6: Roud number.
		@param7: Player's bet.
		@return: None.
*/
void writeToGameLog(ofstream& fout, Player p, Player d, Hand& player1, Hand& dealer, int gameNum, double b){


	if (fout.is_open() == false)
		fout.open("gamelog.txt");

	fout << "-----------------------------------" << endl;
	fout << "Game number: " << gameNum << "\t" << "Money Left: $" << p.get_money() << "\n";
	fout << "Bet: " << b << "\n\n";
	fout << "Your cards: \n";

	fout << player1.stream(gameNum);

	fout << "Your total: " << player1.sum() << "\n\n";
	fout << "Dealer's cards: \n";

	fout << dealer.stream(gameNum);

	fout << "Dealer's total: " << dealer.sum() << "\n\n";
	fout << "-----------------------------------" << endl;

	if (programRun(p.get_money(),d.get_money()) == false)
		fout.close();

	return;
}

//********* Driver *********//
int main(){

	//Seed RNG & create fout stream
	srand(static_cast<int>(time(0)));
	ofstream fout;

	//Initialize data values
	int gCount = 0;
	double bet = 0;
	double dealerFunds = 900;
	string pResponse = "y";

	//Create a Player, a Dealer, and their respective Hands.
	Player Player1;
	Player Dealer(dealerFunds);
	Hand hPlayer1;
	Hand hDealer;


	while (programRun(Player1.get_money(), Dealer.get_money()) == true){

		gCount++;

		//Reset hands
		hPlayer1.reset_hand();
		hDealer.reset_hand();

		//Display cash on hand
		cout << "You have $" << Player1.get_money() << "." << endl;

		//Ask to place bet
		cout << "Place your bet: ";
		cin >> bet;

		//Perform input validation
		while (validInput(bet, Player1) == false){
			cout << "Nice try! Enter a reasonable amount. ";
			cin >> bet;
		}

		cout << "\n \n";

		//Have Player draw cards until he wishes to stop or until his total card value >= SIETE Y MEDIO
		do{
			playerDraw(hPlayer1);

			cout << "You draw a card. \n";
			hPlayer1.print();

			cout << " \n  Your total is: ";
			cout << hPlayer1.sum() << endl;

			if (hPlayer1.sum() < SIETE_Y_MEDIO){

				cout << "Do you wish to draw another card? (y/n) ";
				cin >> pResponse;
			}

			cout << "\n \n";

		} while (pResponse == "y" && hPlayer1.sum() < SIETE_Y_MEDIO);


		//Have Dealer draw cards while his total card value < 5.5
		do{
			playerDraw(hDealer);

			cout << "The Dealer draws a card. \n";
			hDealer.print();

			cout << " \n  Dealer's total is: ";
			cout << hDealer.sum() << endl;
			cout << " \n \n";

		} while (hDealer.sum() < DEALER_DRAWS_UNDER);


		//Write results to log.
		writeToGameLog(fout, Player1, Dealer, hPlayer1, hDealer, gCount, bet);

		//Depending on the game outcome, update Player and Dealer money
		switch (declareWinner(hPlayer1, hDealer)){

		case WIN:

			cout << "You win $" << bet << "." << endl;

			updatePlayerMoney(Player1, bet);
			updatePlayerMoney(Dealer, -bet);

			break;

		case LOSE:

			cout << "Too bad. You lose $" << bet << "." << endl;

			updatePlayerMoney(Player1, -bet);
			updatePlayerMoney(Dealer, bet);

			break;

		case HOUSE_ADVANTAGE:

			cout << "House advantage. You lose $" << bet << "." << endl;

			updatePlayerMoney(Player1, -bet);
			updatePlayerMoney(Dealer, bet);

			break;

		case TIE:

			cout << "You tie. Nobody Wins!" << endl;

			break;

		default:
			break;

		} //End round loop


	} //End game loop


	//If player runs out of money.
	if (Player1.get_money() <= 0)

		cout << "You're out of cash! GAME OVER." << "\n" << "Come back when you have more money. \n";

	//Or if dealer runs out of money.
	else

		cout << "The house is out of funds for now! You're a master at this! Come back later. \n";

	
	return 0;
}
