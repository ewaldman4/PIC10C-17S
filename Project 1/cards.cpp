#include "cards.h"
#include <cstdlib>
#include <iostream>

/*
You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
Card class
************************************************* */

/*
Default constructor for the Card class.
It could give repeated cards. This is OK.
Most variations of Blackjack are played with
several decks of cards at the same time.
*/
Card::Card() {
	int r = 1 + rand() % 4;
	switch (r) {
	case 1: suit = OROS; 
		break;
	case 2: suit = COPAS;
		break;
	case 3: suit = ESPADAS;
		break;
	case 4: suit = BASTOS; 
		break;
	default: break;
	}

	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = AS; 
		break;
	case  2: rank = DOS; 
		break;
	case  3: rank = TRES; 
		break;
	case  4: rank = CUATRO; 
		break;
	case  5: rank = CINCO; 
		break;
	case  6: rank = SEIS; 
		break;
	case  7: rank = SIETE; 
		break;
	case  8: rank = SOTA; 
		break;
	case  9: rank = CABALLO;
		break;
	case 10: rank = REY; 
		break;
	default: break;
	}
}

// Accessor: returns a string with the suit of the card in Spanish 
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
	default: 
		break;
	}
	return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
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
	default: 
		break;
	}
	return rankName;
}

string Card::nameOfSpanishCard() const {
	string spanishCard = get_spanish_rank() + " de " + get_spanish_suit();
	return spanishCard;
}

string Card::get_english_suit() const {
	string englishSuitName = "";
	switch (suit) {
	case OROS:
		englishSuitName = "golds";
		break;
	case COPAS:
		englishSuitName = "cups";
		break;
	case ESPADAS:
		englishSuitName = "swords";
		break;
	case BASTOS:
		englishSuitName = "clubs";
		break;
	default:
		break;
	}
	return englishSuitName;
}

string Card::get_english_rank() const {
	string englishRankName;
	switch (rank) {
	case AS:
		englishRankName = "Ace";
		break;
	case DOS:
		englishRankName = "Two";
		break;
	case TRES:
		englishRankName = "Three";
		break;
	case CUATRO:
		englishRankName = "Four";
		break;
	case CINCO:
		englishRankName = "Five";
		break;
	case SEIS:
		englishRankName = "Six";
		break;
	case SIETE:
		englishRankName = "Seven";
		break;
	case SOTA:
		englishRankName = "Jack";
		break;
	case CABALLO:
		englishRankName = "Knight";
		break;
	case REY:
		englishRankName = "King";
		break;
	default:
		break;
	}
	return englishRankName;
}


string Card::nameOfEnglishCard() const {
	string englishCard = get_english_rank() + " of " + get_english_suit();
	return englishCard;
}

// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
	return static_cast<int>(rank) + 1;
}

double Card::rankToValue() const {
	int rank = get_rank();
	double sieteValue = 0;
	if (rank >= 10)
		sieteValue = .5;
	else
		sieteValue = rank;
	return sieteValue;

}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}



/* *************************************************
Hand class
************************************************* */
// Implemente the member functions of the Hand class here.
Hand::Hand()
{
	handSum = 0;
	handSize = 0;
}

void Hand::addCard(Card* card) {
	hand.push_back(card);
	handSum += card->rankToValue();
	handSize++;
}

double Hand::getSum() const {
	return handSum;
}

Card* Hand::getCurrentCard(int index) const {
	return hand[index];
}

int Hand::getHandSize() const {
	return handSize;
}

/* *************************************************
Player class
************************************************* */
Player::Player(int m)
{
	hand;
	money = m;
}
/*
int Player::getCurrentMoney() const {
	return money;
}

void Player::changeCurrentMoney(int m) {
	money += m;
}
*/
void Player::addCard(Card* card) {
	hand.addCard(card);
}

int Player::handSize() const{
	return hand.getHandSize();
}

Card* Player::getCurrentCard(int index) const {
	return hand.getCurrentCard(index);
}

double Player::getHandSum() const {
	return hand.getSum();
}