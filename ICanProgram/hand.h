#pragma once
#include "card.h"
#include <array>
class hand
{
public:
	card* getHand();
	void addCard(card cardToAdd);

	hand(card cardToAdd);
	~hand();

	int handTotal();
private:
	card hand2[11];
};

