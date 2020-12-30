#include "hand.h"

hand::hand()
{
}

hand::hand(card cardToAdd)
{
	handVector.push_back(cardToAdd);
}

hand::~hand()
{
	handVector.erase(handVector.begin(), handVector.end());
}

void hand::addCard(card cardToAdd) 
{ 
	handVector.push_back(cardToAdd);
	//necessary to add scenario if we breach max card size?
}


int hand::handTotal()
{
	int tempTotal = 0;

	for (int i = 0; i < handVector.size(); i++)
	{
		tempTotal += handVector[i].getValue();
		if ((handVector[i].getValue() == 1) && ((tempTotal + 10) < 21))
		{
			tempTotal += 10;
		}
	}
	return tempTotal;
}

int hand::handSize()
{
	return(handVector.size());
}

card hand::cardAtPos(int pos)
{
	return(handVector[pos]);
}

card hand::remove()
{
	card removedCard = handVector.back();
	handVector.pop_back();
	return(removedCard);
}
