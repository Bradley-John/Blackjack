#include "blackjack.h"

//Shuffle the deck and deal cards in proper order
void blackjack::shuffleDeal()
{
	currentDeck.shuffle();

	playerHand.addCard(currentDeck.remove());
	dealerHand.addCard(currentDeck.remove());
	playerHand.addCard(currentDeck.remove());
	dealerHand.addCard(currentDeck.remove());
}

//Starts game of blackjack. Returns int value to specify if game should be continued or not
//Does not necessarily need to be int, but figured this could be used to determine if user wants to switch to other
//possible games
int blackjack::play()
{
	char continueChar = 'o';

	shuffleDeal();

	displayHand();
	dealer21 = checkFor21(dealerHand);
	player21 = checkFor21(playerHand);

	//While player isn't standing, player doesnt have 21, dealer doesnt have 21, player hasn't busted
	while (!playerStand && !player21 && !dealer21 && !playerBust)
	{
		hitOrStand();
		system("CLS");
		displayHand();
	}

	dealerHit();
	dealer21 = checkFor21(dealerHand);

	system("CLS");
	displayHand();

	//If player and dealer have equal hand totals or if both player and dealer bust, game ends in draw
	if (playerHand.handTotal() == dealerHand.handTotal() || (dealerBust && playerBust))
	{
		cout << "\nYou tied!\n";
	}

	//otherwise, if player total is greater than dealer total (and <=21) or if the dealer busts, game ends in a win
	else if ((playerHand.handTotal() > dealerHand.handTotal()) && (playerHand.handTotal() <= 21)|| (dealerBust))
	{
		cout << "\nYou win!\n";
	}
	//otherwise, game ends in loss
	else
	{
		cout << "\nYou lose!\n";
	}

	returnCards();
	resetFlags();
	
	cout << "Continue? (y/n)";

	while ((continueChar != 'y') && (continueChar != 'n'))
	{
		cin >> continueChar;
		continueChar = tolower(continueChar);
	}

	if (continueChar == 'y')
	{
		system("CLS");
		return 1;
	}
	else if (continueChar == 'n')
	{
		return 0;
	}
}

//Checks given hand to see if total = 21
bool blackjack::checkFor21(hand handToCheck)
{
	if (handToCheck.handTotal() == 21)
	{
		return true;
	}

	else
	{
		return false;
	}
}

//Checks given hand to see if they went bust from hits
bool blackjack::checkForBust(hand handToCheck)
{
	if (handToCheck.handTotal() > 21)
	{
		return true;
	}

	else
	{
		return false;
	}
}

//Will display hand to console. Just value/suit for player/dealer
//Additionally displays largest possible value player can have with the current cards in hand
void blackjack::displayHand()
{
	cout << "\n";
	//If we're on the player's turn still (dealerReveal == false), hide the second dealer card 
	if (!dealerReveal)
	{
		cout << "The dealer has:\n" << dealerHand.cardAtPos(0).translateValue() << " of " << dealerHand.cardAtPos(0).translateSuit() << "\n";
		cout << "One unknown card\n\n";
	}
	//Otherwise, reveal every dealer card
	else if (dealerReveal)
	{
		cout << "The dealer has:\n";
		for (int i = 0; i < dealerHand.handSize(); i++)
		{
			cout << dealerHand.cardAtPos(i).translateValue() << " of " << dealerHand.cardAtPos(i).translateSuit() << "\n";
		}
		cout << dealerHand.handTotal() << "\n";
	}

	cout << "You have:\n";
	for (int i = 0; i < playerHand.handSize(); i++)
	{
		cout << playerHand.cardAtPos(i).translateValue() << " of " << playerHand.cardAtPos(i).translateSuit() << "\n";
	}
	cout << playerHand.handTotal() << "\n";
}

//Function that allows player to interact with their hand (hit/stand)
void blackjack::hitOrStand()
{
	cout << "Hit - H\nStand - S\n";

	while (option != 'h' && option != 's')
	{
		cin >> option;
		option = tolower(option);
	}

	if (option == 'h')
	{
		playerHand.addCard(currentDeck.remove());
		player21 = checkFor21(playerHand);
		playerBust = checkForBust(playerHand);
	}

	else if (option == 's')
	{
		playerStand = true;
	}
	option = 'a';
}

//Dealer hit process. Will continue to hit until the dealer busts or if the dealer if at or above their current limit (dealerLimit)
void blackjack::dealerHit()
{
	dealerReveal = true;

	while ((dealerHand.handTotal() < dealerLimit) && (dealerHand.handTotal() < playerHand.handTotal()))
	{
		dealerHand.addCard(currentDeck.remove());
		dealerBust = checkForBust(dealerHand);
	}
}

//Returns cards from both player and dealer hands to the deck
void blackjack::returnCards()
{
	int tempSizeDealer = dealerHand.handSize();
	int tempSizePlayer = playerHand.handSize();

	for (int i = 0; i < tempSizeDealer; i++)
	{
		currentDeck.insert(dealerHand.remove());
	}

	for (int i = 0; i < tempSizePlayer; i++)
	{
		currentDeck.insert(playerHand.remove());
	}
}

//Resets all flags so the next game can continue as normal
void blackjack::resetFlags()
{
	option = 'a';
	dealerReveal = false;
	player21 = false;
	dealer21 = false;
	playerStand = false;
	playerBust = false;
	dealerBust = false;
	dealerLimit = 17;
}