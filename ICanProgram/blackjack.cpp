#include "blackjack.h"

blackjack::blackjack()
{
	currentDeck.shuffle();

	playerHand.addCard(currentDeck.remove());
	dealerHand.addCard(currentDeck.remove());
	playerHand.addCard(currentDeck.remove());
	dealerHand.addCard(currentDeck.remove());
}

int blackjack::play()
{
	displayHand();
	dealer21 = checkFor21(dealerHand);
	player21 = checkFor21(playerHand);

	while (!playerStand && !player21 && !dealer21 && !playerBust)
	{
		hitOrStand();
		displayHand();
	}

	dealerHit();
	dealer21 = checkFor21(dealerHand);

	if (playerHand.handTotal() > dealerHand.handTotal())
	{
		cout << "\nYou win!\n";
	}
	else
	{
		cout << "\nYou lose!\n";
	}

	returnCards(playerHand);
	returnCards(dealerHand);
	resetFlags();
	return 0;
}

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

void blackjack::displayHand()
{
	cout << "\n";
	if (!dealerReveal)
	{
		cout << "The dealer has:\n" << dealerHand.cardAtPos(0).translateValue() << " of " << dealerHand.cardAtPos(0).translateSuit() << "\n";
		cout << "One unknown card\n\n";
	}
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

void blackjack::dealerHit()
{
	dealerReveal = true;
	displayHand();

	while (dealerHand.handTotal() < dealerLimit)
	{
		dealerHand.addCard(currentDeck.remove());
		displayHand();
	}
}

void blackjack::returnCards(hand handToReturn)
{
	int tempSize = handToReturn.handSize();
	for (int i = 0; i < tempSize; i++)
	{
		currentDeck.insert(handToReturn.remove());
	}
}

void blackjack::resetFlags()
{
	char option = 'a';
	bool dealerReveal = false;
	bool player21 = false;
	bool dealer21 = false;
	bool playerStand = false;
	bool playerBust = false;
	bool dealerBust = false;
	int dealerLimit = 17;
}