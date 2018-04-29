#include "cards.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

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
	default: break;
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
	default: break;
	}
	return rankName;
}



// Accessor: returns a string with the suit of the card in English 
string Card::get_english_suit() const {
	string suitName_english;
	switch (suit) {
	case OROS:
		suitName_english = "golden coins";
		break;
	case COPAS:
		suitName_english = "cups";
		break;
	case ESPADAS:
		suitName_english = "swords";
		break;
	case BASTOS:
		suitName_english = "clubs";
		break;
	default: break;
	}
	return suitName_english;
}

// Accessor: returns a string with the rank of the card in English 
string Card::get_english_rank() const {
	string rankName_english;
	switch (rank) {
	case AS:
		rankName_english = "Ace";
		break;
	case DOS:
		rankName_english = "Two";
		break;
	case TRES:
		rankName_english = "Three";
		break;
	case CUATRO:
		rankName_english = "Four";
		break;
	case CINCO:
		rankName_english = "Five";
		break;
	case SEIS:
		rankName_english = "Six";
		break;
	case SIETE:
		rankName_english = "Seven";
		break;
	case SOTA:
		rankName_english = "Squire";
		break;
	case CABALLO:
		rankName_english = "Knight";
		break;
	case REY:
		rankName_english = "King";
		break;
	default: break;
	}
	return rankName_english;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
	return static_cast<int>(rank) + 1;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}
 
// Cout the contents of a card
void Card::print_card() const
{
	cout << swtw(10) << get_spanish_rank << " de " << get_spanish_suit << setw(10) << "( " << get_english_rank << " of " << get_english_suit " )\n";
}


/* *************************************************
Hand class
************************************************* */

/* Default constructor for Hand Class. Initializes private variables.
No need to initialize vector again. */
Hand::Hand()
{
	total = 0;
}

// Adds new card to the player's hand and add card value to total.
void Hand::add_card(Card new_card)
{
	player_hand.push_back(new_card);
	total += new_card.get_rank;
}

// Accessor. Returns total of hand.
int Hand::get_total() const
{
	return total;
}

void Hand::print_hand() const
{
	for (int i = 0; i < player_hand.size(); i++)
	{
		print_card();
	}
}


/* *************************************************
Player class
************************************************* */

/* Default constructor for Player Class.
Initializes private variables.*/
Player::Player(int m)
{
	money = m;			//starting value
}

// Adds bet value to player's total money if they win a hand.
void Player::win(int bet)
{
	money += bet;		
}

// Subtracts bet value from player's total money if they loose a hand.
void Player::loss(int bet)
{
	money -= bet;
}

int Player::get_money() const
{
	return money;
}