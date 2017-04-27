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
	srand(time(0));
	int gameNumber = 1;
	ofstream fileStream;
	fileStream.open("GameLog.txt");
	int currentUserMoney = USER_MONEY;
	int currentDealerMoney = DEALER_MONEY;
	cout << "Let's begin our game of Siete y Medio.\n";
	int betAmount = 0;

	do {
		Player Dealer(currentDealerMoney);
		Player User(currentUserMoney);
		cout << "Your current wallet is " << currentUserMoney << "\n\tEnter bet amount: ";
		cin >> betAmount;
		fileStream << "-----------------------------------------------\n\nGame number: " << gameNumber
			<< "\tMoney left: " << currentUserMoney << "\nBet: " << betAmount <<"\n\n";
		if (betAmount > currentUserMoney)
		{
			cout << "You're trying to cheat, aren't you?\nYou can only bet as much as you have!\n   Enter bet amount: ";
			cin >> betAmount;
		}
		bool keepDealing = true;
		string yesOrNo = "";
		do {
			User.addCard(new Card());
			cout << "Your cards:\n";
			for (int x = 0; x < User.handSize(); x++)
			{
				cout << "\t" << User.getCurrentCard(x)->get_spanish_rank() << " de " << User.getCurrentCard(x)->get_spanish_suit()
					<< "\t(" << User.getCurrentCard(x)->get_english_rank() << " of "
					<< User.getCurrentCard(x)->get_english_suit() << ")\n";
			}
			cout << "Your total is " << User.getHandSum() << ". ";
			if (User.getHandSum() > 7.5)
			{
				cout << "\nYou've lost!\n";
				keepDealing = false;
				yesOrNo = "n";
			}
			else if (User.getHandSum() == 7.5) {
				cout << "\nYou can't take anymore cards!\n";
				keepDealing = false;
				yesOrNo = "n";
			}
			else {
				cout << "Do you want to continue? y/n ";
				cin >> yesOrNo;
				if (yesOrNo == "n")
				{
					keepDealing = false;
				}
			}
		} while (keepDealing);

		fileStream << "Your cards:\n";
		for (int x = 0; x < User.handSize(); x++){
			fileStream << "\t" << User.getCurrentCard(x)->get_spanish_rank() << " de " << User.getCurrentCard(x)->get_spanish_suit()
				<< "\t(" << User.getCurrentCard(x)->get_english_rank() << " of "
				<< User.getCurrentCard(x)->get_english_suit() << ").\n";
		}
		fileStream << "Your total: " << User.getHandSum() << ".\n\n";

		bool dealerKeepsAccepting = true;
		if (User.getHandSum() > 7.5) {
			dealerKeepsAccepting = false;
		}

		do {
			Dealer.addCard(new Card());
			cout << "Dealer's cards:\n";
			for (int x = 0; x < Dealer.handSize(); x++)
			{
				cout << "\t" << Dealer.getCurrentCard(x)->get_spanish_rank() << " de " << Dealer.getCurrentCard(x)->get_spanish_suit()
					<< "\t(" << Dealer.getCurrentCard(x)->get_english_rank() << " of "
					<< Dealer.getCurrentCard(x)->get_english_suit() << ")\n";
			}
			cout << "The dealer's total is " << Dealer.getHandSum() << "\n";
			if (Dealer.getHandSum() >= 5.5) {
				dealerKeepsAccepting = false;
			}
		} while (dealerKeepsAccepting);

		fileStream << "Dealer's cards:\n";
		for (int x = 0; x < Dealer.handSize(); x++)
		{
			fileStream << "\t" << Dealer.getCurrentCard(x)->get_spanish_rank() << " de " << Dealer.getCurrentCard(x)->get_spanish_suit()
				<< "\t(" << Dealer.getCurrentCard(x)->get_english_rank() << " of "
				<< Dealer.getCurrentCard(x)->get_english_suit() << ").\n";
		}
		fileStream << "Dealer's total is " << Dealer.getHandSum() << "\n\n";

		if (User.getHandSum() > 7.5 || User.getHandSum() < Dealer.getHandSum() && Dealer.getHandSum() <= 7.5) {
			currentUserMoney -= betAmount;
			cout << "\nToo bad. You lose " << betAmount << "\n\n";
		}
		else if (Dealer.getHandSum() > 7.5 || Dealer.getHandSum() < User.getHandSum() && User.getHandSum() <= 7.5){
			currentUserMoney += betAmount;
			currentDealerMoney -= betAmount;
			cout << "\nYou win " << betAmount << "\n\n";
		}
		else if (Dealer.getHandSum() == User.getHandSum()) {
			cout << "\nNobody wins!\n\n";
		}
		gameNumber++;
	} while (currentUserMoney > 0 && currentDealerMoney > 0);
	if (currentUserMoney > 0)
	{
		cout << "Thanks for playing!\n";
	}
	else
	{
		cout << "Better luck next time!\n";
	}
}
