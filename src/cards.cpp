/* *************************************
Brian Oceguera
File: cards.cpp
Description: Implementation of Card, Hand, Player classes.
************************************* */

#include "cards.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

/* *************************************************
Card class
************************************************* */

/*
Default constructor for the Card class.
It could give repeated cards. This is OK.
Most variations of Blackjack are played with
several decks of cards at the same time.

Note: Makes use of random number generator.
*/
Card::Card(){

	int r = 1 + rand() % 4;
	switch (r) {
	case 1: suit = OROS; break;
	case 2: suit = COPAS; break;
	case 3: suit = ESPADAS; break;
	case 4: suit = BASTOS; break;
	default: break;
	}

	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = AS; break;
	case  2: rank = DOS; break;
	case  3: rank = TRES; break;
	case  4: rank = CUATRO; break;
	case  5: rank = CINCO; break;
	case  6: rank = SEIS; break;
	case  7: rank = SIETE; break;
	case  8: rank = SOTA; break;
	case  9: rank = CABALLO; break;
	case 10: rank = REY; break;
	default: break;
	}
}


/**
get_spanish_suit()
	Description: Determines the suit of a Card object.
	@param: None.
	@return: String of Spanish suit.

*/
string Card::get_spanish_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "oros";
		break;
	case COPAS:
		suitName = "copas";
		break;
	case ESPADAS:
		suitName = "espadas";
		break;
	case BASTOS:
		suitName = "bastos";
		break;
	default: break;
	}
	return suitName;
}


/**
get_spanish_rank()
	Description: Determines the rank of a Card object.
	@param: None.
	@return: String of Spanish rank.

*/
string Card::get_spanish_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "As";
		break;
	case DOS:
		rankName = "Dos";
		break;
	case TRES:
		rankName = "Tres";
		break;
	case CUATRO:
		rankName = "Cuatro";
		break;
	case CINCO:
		rankName = "Cinco";
		break;
	case SEIS:
		rankName = "Seis";
		break;
	case SIETE:
		rankName = "Siete";
		break;
	case SOTA:
		rankName = "Sota";
		break;
	case CABALLO:
		rankName = "Caballo";
		break;
	case REY:
		rankName = "Rey";
		break;
	default: break;
	}
	return rankName;
}



/**
get_english_suit()
	Description: Determines the suit of a Card object.
	@param: None.
	@return: String of English suit.

*/
string Card::get_english_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "diamonds";
		break;
	case COPAS:
		suitName = "hearts";
		break;
	case ESPADAS:
		suitName = "spades";
		break;
	case BASTOS:
		suitName = "clubs";
		break;
	default: break;
	}
	return suitName;
}


/**
get_english_rank()
	Description: Determines the rank of a Card object.
	@param: None.
	@return: String of English rank.

*/
string Card::get_english_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "Ace";
		break;
	case DOS:
		rankName = "Two";
		break;
	case TRES:
		rankName = "Three";
		break;
	case CUATRO:
		rankName = "Four";
		break;
	case CINCO:
		rankName = "Five";
		break;
	case SEIS:
		rankName = "Six";
		break;
	case SIETE:
		rankName = "Seven";
		break;
	case SOTA:
		rankName = "Jack";
		break;
	case CABALLO:
		rankName = "Knight";
		break;
	case REY:
		rankName = "King";
		break;
	default: break;
	}
	return rankName;
}



/**
get_rank()
	Description: Assigns a numerical value to card based on rank. 
		AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
	@param: None.
	@return: Integer specifying the rank of a Card.
*/
int Card::get_rank() const {
	return static_cast<int>(rank)+1;
}


/**
bool operator < (Card card2)
	Description: Overloads operator '<' to compare two Card objects.
	@param: A second Card object.
	@return: True if card < card2. False otherwise.
*/
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}



/* *************************************************
Hand class
************************************************* */


/**
Hand()
	Description: Default constructor. 
		Initializes an empty vector of type Card. 
		Initializes an empty string s, used for writing to log.
	@param: None.
*/
Hand::Hand(){

	vector<Card> hand;
	string s = "";

}


/**
sum()
	Description: Returns the total value of cards in Hand. 
		Face cards are worth 1/2. Ace is 1. Other cards are worth their numerical value.
	@param: None.
	@return: hand_value of type double 
*/
double Hand::sum() const{

	double hand_value = 0;
	const double FACE_VALUE = 0.5;

	//Go through each Card in vector and updates hand_value accordingly.
	for (int i = 0; i < hand.size(); i++){

		switch (hand[i].get_rank()) {
		case 1:
			hand_value += 1;
			break;
		case 2:
			hand_value += 2;
			break;
		case 3:
			hand_value += 3;
			break;
		case 4:
			hand_value += 4;
			break;
		case 5:
			hand_value += 5;
			break;
		case 6:
			hand_value += 6;
			break;
		case 7:
			hand_value += 7;
			break;
		case 8:
		case 9:
		case 10:
			hand_value += FACE_VALUE;
			break;
		case 11:
			hand_value += FACE_VALUE;
			break;
		case 12:
			hand_value += FACE_VALUE;
			break;
		default:
			break;
		}
	}

	return hand_value;
}


/**
reset_hand()
	Description: Resizes vector<Card> hand to the empty vector
	@param: None.
*/
void Hand::reset_hand(){

	hand.resize(0);

	return;
}


/**
draw_card()
	Description: Adds a new randomly generated Card object to end of vector<Card> hand.
	@param: None.
	@return: None.
*/
void Hand::draw_card(){

	hand.push_back(Card());

	return;
}


/**
print()
	Description: Prints the names of each card in a player's hand, both Spanish and English to the console. Formatted output.
	@param: None.
	@return: None.
*/
void Hand::print() const{

	string d = " de ";
	for (int i = 0; i < hand.size(); i++){

		cout << "\t" << hand[i].get_spanish_rank() << d << hand[i].get_spanish_suit();

		cout << setw(25 - (hand[i].get_spanish_rank().length() + hand[i].get_spanish_suit().length() + d.length())) 
			 << "{ " << hand[i].get_english_rank() << " of " << hand[i].get_english_suit() << " } \n";
	}

	return;
}


/**
stream(int n)
	Description: Creates a string of the same contents as print(). English name appears below spanish name.
	@param: int n. This is the round number.
	@return: String of all cards in vector<Card> hand.
*/
string Hand::stream(int n){
	
	//If begin a new round, update the round number and clear the previous string.
	if (n > gameNumber){
		gameNumber = n;
		s = "";
	}

	for (int i = 0; i < hand.size(); i++){

		s += "\t" + hand[i].get_spanish_rank() + " de " + hand[i].get_spanish_suit();

		s += "\n\t  { " +  hand[i].get_english_rank() + " of " + hand[i].get_english_suit() + " } \n";
	}

	return s;
}


/* *************************************************
Player class
************************************************* */


/**
Player()
	Description: Default constructor. Sets a player's money to 100.
	@param: None.
*/
Player::Player(){

	money = 100;
}


/**
Player(double m)
	Description: Constructor. Assigns m to money.
	@param: double m.

*/
Player::Player(double m){

	money = m;
}


/**
get_money()
Description: Accesses money from the private field
	@param: None.
	@return: (double) money
*/
double Player::get_money() const{

	return money;
}


/**
update_money(double a)
	Description: Changes money in the private field
	@param: double a.
	@return: none
*/
void Player::update_money(double a){

	money += a;
	return;
}
