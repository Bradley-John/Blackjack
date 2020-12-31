#include "blackjack.h"

void blackjack::shuffleDeal()
{
	currentDeck.shuffle();

	playerHand.addCard(currentDeck.remove());
	dealerHand.addCard(currentDeck.remove());
	playerHand.addCard(currentDeck.remove());
	dealerHand.addCard(currentDeck.remove());
}

int blackjack::play()
{
	char continueChar = 'o';

	shuffleDeal();

	displayHand();
	dealer21 = checkFor21(dealerHand);
	player21 = checkFor21(playerHand);

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

	if (playerHand.handTotal() == dealerHand.handTotal() || (dealerBust && playerBust))
	{
		cout << "\nYou tied!\n";
	}

	else if ((playerHand.handTotal() > dealerHand.handTotal()) && (playerHand.handTotal() <= 21)|| (dealerBust))
	{
		cout << "\nYou win!\n";
	}
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

	while ((dealerHand.handTotal() < dealerLimit) && (dealerHand.handTotal() < playerHand.handTotal()))
	{
		dealerHand.addCard(currentDeck.remove());
		dealerBust = checkForBust(dealerHand);
	}
}

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