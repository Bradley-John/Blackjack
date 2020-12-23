#pragma once
#include "card.h"

class hand
{
public:
	card* getHand();
	void addCard(card cardToAdd);

	hand(card cardToAdd);
	~hand();

	int handTotal();
private:
	card handArray[11];
	int size = 0;
};

