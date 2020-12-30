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
	hitOrStand();

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

void blackjack::displayHand()
{
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
	}

	cout << "You have:\n";
	for (int i = 0; i < playerHand.handSize(); i++)
	{
		cout << playerHand.cardAtPos(i).translateValue() << " of " << playerHand.cardAtPos(i).translateSuit() << "\n";
	}
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
	}
}
