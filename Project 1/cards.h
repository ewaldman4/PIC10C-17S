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

	// Accessors 
	string get_spanish_suit() const;
	string get_spanish_rank() const;
	string nameOfSpanishCard() const;

	/*
	These are the only functions you'll need to code
	for this class. See the implementations of the two
	functions above to get an idea of how to proceed.
	*/
	string get_english_suit() const;
	string get_english_rank() const;
	string nameOfEnglishCard() const;

	// Converts card rank to number.
	// The possible returns are: 1, 2, 3, 4, 5, 6, 7, 10, 11 and 12
	int get_rank() const;
	//changes rank to value in game
	double rankToValue() const;

	// Compare rank of two cards. E.g: Eight<Jack is true.
	// Assume Ace is always 1. 
	// Useful if you want to sort the cards.
	bool operator < (Card card2) const;

private:
	suit_t suit;
	rank_t rank;
};


class Hand {
public:
	Hand();
	~Hand();
	//adds a card to our hand
	void addCard(Card* card);
	//gets the sum of all cards in the hand
	double getSum() const;
	//returns card at index 
	Card* getCurrentCard(int index) const;
	//returns hand size
	int getHandSize() const;

private:
	std::vector<Card*> hand;
	double handSum;
	int handSize;
};


class Player {
public:
	Player(int m);

	//use hand methods with player
	void addCard(Card* card);
	int handSize() const;
	Card* getCurrentCard(int index) const;
	double getHandSum() const;

private:
	int money;
	Hand hand;
	
};

#endif
