#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

const int USER_MONEY = 100;
const int DEALER_MONEY = 900;


// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main() {
	Player Dealer(DEALER_MONEY);
	Player User(USER_MONEY);
	cout << "Let's begin our game of Siete y Medio.\nYour current wallet is " << USER_MONEY << "\n";
	int betAmount = 0;
	do {
		cout << "   Enter bet amount: ";
		cin >> betAmount;
		if (betAmount > USER_MONEY)
		{
			cout << "You're trying to cheat, aren't you?\nYou can only bet as much as you have!\n   Enter bet amount: ";
			cin >> betAmount;
		}
		bool keepDealing = true;
		do {
			Dealer.getHand().addCard(new Card());
			User.getHand().addCard(new Card());
			cout << "Your cards:\n";
			for (int handSize = 0; handSize < User.getHand().getCards().size(); handSize++)
			{
				cout << "/t" << User.getHand().getCards().(at(handSize).nameOfSpanishCard() << "\t\t("
					<< User.getHand().getCards().at(handSize).nameOfEnglishCard() << ")\n";
			}
		} while (false);

	} while (false);
}
