#pragma once
#include <iostream>
#include <string>

#include "card.h"
#include "hand.h"
#include "deck.h"
#include "blackjack.h"

using std::cout;
using std::cin;             //I just don't like typing std:: on these, no reason for it

class blackjack
{
public:
	blackjack();

	int play();

	bool checkFor21(hand handToCheck);

	void displayHand();

	void hitOrStand();


private:
	deck currentDeck;
	hand dealerHand;
	hand playerHand;
	char option = 'a';
	bool dealerReveal = false;
	bool player21 = false;
	bool dealer21 = false;
};

