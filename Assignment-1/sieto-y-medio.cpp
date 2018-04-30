#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "cards.h"
using namespace std;

// Global variables
int starting_amount = 100;		// User starts with $100
int counter = 1;				// Counts number of games
int dealer_bet = 50;

/* This function plays a full game of 7 1/2.
It couts various messages to the console and prompts user input of whether they would like additional cards. 
It also displays the hands and totals of each player, and let's the user know if they won or lost, and how much money they have left.
*/
void run_game(Player p1, Player p2)
{
	Hand h1;			//player's hand
	Hand h2;			//dealer's hand
	int bet;			//bet amount
	Card p1_c1;			//new card
	Card p2_c1;			
	string answer;		//whether player wants another card

	cout << "You have " << p1.get_money << ". Enter bet: ";
	cin >> bet;
	
	h1.add_card(p1_c1);
	cout << "Your cards: \n";
	p1_c1.print_card();
	cout << "Your total is " << h1.get_total() << ". Do you want another card (y/n)?";
	cin >> answer;

	while (answer == "y")
	{
		Card new_card;
		h1.add_card(new_card);
		cout << "New card: \n";
		new_card.print_card();
		cout << "Your cards: \n";
		h1.print_hand();

		cout << "Your total is " << h1.get_total() << ". Do you want another card (y/n)?";
		cin >> answer;
	}


	h2.add_card(p2_c1);
	cout << "Dealer's cards: \n";
	p2_c1.print_card();
	cout << "The dealer's total is " << h2.get_total() << ".\n";

	while (h2.get_total() < 5.5)
	{
		Card new_card;
		h2.add_card(new_card);
		cout << "New card: \n";
		new_card.print_card();
		cout << "Dealer's cards: \n";
		h2.print_hand();
		cout << "The dealer's total is " << h2.get_total() << " .\n";
	}

	if (h1.get_total() > 7.5 && h2.get_total() <= 7.5)
	{
		p1.loss(bet);
		cout << "Too bad you lose.\n";
	}
	else if (h2.get_total() > 7.5 && h1.get_total() <= 7.5)
	{
		p1.win(bet);
		p2.loss(dealer_bet);
		cout << "You win " << bet << ".\n";
	} 
	else if (h1.get_total() <= 7.5 && h2.get_total() <= 7.5)
	{
		if (h1.get_total() > h2.get_total())
		{
			p1.win(bet);
			p2.loss(dealer_bet);
			cout << "You win " << bet << ".\n";
		}
		else if (h1.get_total() < h2.get_total())
		{
			p1.loss(bet);
			cout << "Too bad you lose.\n";
		}
		else if (h1.get_total() == h2.get_total())
		{
			cout << "Nobody wins! \n";
		}
	}

	game_log(p1, h1, h2, bet);
}

void game_log(Player p1, Hand h1, Hand h2, int bet)
{
	ofstream fout;
	fout.open("GameLog.txt");
	fout << "\n" << setw(10) << "Game number: " << counter << setw(10) << "Money left: " << p1.get_money() << "\n\n";
	fout << "Bet: " << bet << "\n\n";
	
	fout << "Your cards:\n";
	h1.print_hand();
	fout << "Your total is " << h1.get_total() << ". \n\n";

	fout << "Dealer's cards: \n";
	h2.print_hand();
	fout << "The dealer's total is " << h2.get_total() << ". \n\n";
	
	fout "-----------------------------------------------------------\n";

	fout.close();
}

int main() 
{

	Player player1(starting_amount);
	Player dealer(0);			//dealer has no money, only keep track of loss

	while (player1.get_money > 0 || dealer.get_money <= -900)
	{
		run_game(player1, dealer);
		counter++;
	}

	return 0;
}