#pragma once
#include "card.h"
#include <vector>

class hand
{
public:
	hand();
	hand(card cardToAdd);
	~hand();

	void addCard(card cardToAdd);
	int handTotal();
	int handSize();

	card remove();
	card cardAtPos(int pos);

private:
	std::vector<card> handVector;
	const int maxSize = 11;
};

