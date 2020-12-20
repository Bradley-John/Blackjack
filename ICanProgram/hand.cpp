#include "hand.h"

hand::hand(card cardToAdd)
{
	hand2[0] = cardToAdd;
}

hand::~hand() 
{ 
	delete[] hand2; 
}


card* hand::getHand() 
{ 
	return hand2; 
}

void hand::addCard(card cardToAdd) 
{ 
	//hand2[hand2.end()] = cardToAdd; 
}


int hand::handTotal()
{
	/*for (int i = 0; i < hand.size(); i++)
	{

	}*/
}


