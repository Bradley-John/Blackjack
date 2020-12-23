#include "hand.h"

hand::hand()
{
}

hand::hand(card cardToAdd)
{
	handArray[0] = cardToAdd;
	size = 1;
}

card* hand::getHand() 
{ 
	return handArray;
}

void hand::addCard(card cardToAdd) 
{ 
	handArray[size] = cardToAdd;
	size++;
	//necessary to add scenario if we breach max card size?
}


int hand::handTotal()
{
	int tempTotal = 0;

	for (int i = 0; i < size; i++)
	{
		tempTotal += handArray[size].getValue();
	}
	return tempTotal;
}

card hand::cardAtPos(int pos)
{
	return(handArray[pos]);
}

