/* *************************************
Brian Oceguera
File: cards.h
Description: Interfaces for Card, Hand, and Player classes.
************************************* */

#include <string>
#include <vector>
#include <fstream>

#ifndef CARDS_H
#define CARDS_H

using namespace std;

enum suit_t { OROS, COPAS, ESPADAS, BASTOS };

/*
The values for this type start at 0 and increase by one
afterwards until they get to SIETE.
The rank reported by the function Card::get_rank() below is
the value listed here plus one.
E.g:
The rank of AS is reported as    static_cast<int>(AS) + 1   = 0 + 1 =  1
The rank of SOTA is reported as  static_cast<int>(SOTA) + 1 = 9 + 1 = 10
*/
enum rank_t { AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA = 9, CABALLO = 10, REY = 11 };

class Card {

public:

	// Constructor assigns random rank & suit to card.
	Card();

	// Accessors return the spanish card name and rank
	string get_spanish_suit() const;
	string get_spanish_rank() const;

	//Accessors return the english card name and rank
	string get_english_suit() const;
	string get_english_rank() const;

	// Converts card rank to number.
	// The possible returns are: 1, 2, 3, 4, 5, 6, 7, 10, 11 and 12
	int get_rank() const;

	// Compare rank of two cards. E.g: Eight<Jack is true.
	// Assume Ace is always 1. 
	bool operator < (Card card2) const;

private:
	suit_t suit;
	rank_t rank;
};


class Hand {

public:

	// Default Constructor creates a vector of type Card
	Hand();

	//Accessor. Sum returns the sum of the card values on Hand.
	double sum() const;

	//Mutator. Stream used to write to game log.
	string stream(int n);

	//Accessor. Prints all elements of vector<card> hand to console.
	void print() const;

	//Mutator. Adds a new card element to vector<card hand.
	void draw_card();

	//Mutator. Resets vector<card> hand to the empty vector.
	void reset_hand();


private:
	vector<Card> hand;
	string s;
	int gameNumber = 0;
};


class Player {
public:

	// Default Constructor. Sets initial amount of money to 100.
	Player();

	//Constructor. Sets money equal to the value of parameter 'm'.
	Player(double m);

	//Accessor. Retrieves the player's money.
	double get_money() const;

	//Mutator. Updates the amount of money after a round.
	void update_money(double a);




private:
	double money;

};

#endif
