#include "hand.h"

hand::hand()
{
}

//If we wanted to initialize with a single card. Not used
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
}


//Loops through hand to collect total of values
int hand::handTotal()
{
	int tempTotal = 0;
	bool aceTen = false;

	for (int i = 0; i < handVector.size(); i++)
	{
		tempTotal += handVector[i].getValue();
		//Logic for aces, if we have room to add the 10, assume the highest value of the ace (11)
		//Will work with multiple aces properly 
		if ((handVector[i].getValue() == 1) && ((tempTotal + 10) < 21))
		{
			tempTotal += 10;
			aceTen = true;
		}
		if ((tempTotal > 21) && aceTen)
		{
			tempTotal -= 10;
		}
	}
	return tempTotal;
}

int hand::handSize()
{
	return(handVector.size());
}

//Returns specific card in hand at given position
card hand::cardAtPos(int pos)
{
	return(handVector[pos]);
}

//Removes a card from the back, returns that exact card
card hand::remove()
{
	card removedCard = handVector.back();
	handVector.pop_back();
	return(removedCard);
}
