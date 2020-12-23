#pragma once
#include "card.h"

class hand
{
public:
	hand();
	hand(card cardToAdd);
	~hand();

	card* getHand();
	void addCard(card cardToAdd);
	int handTotal();

	card cardAtPos(int pos);

private:
	card handArray[11];
	int size = 0;
};

