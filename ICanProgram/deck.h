#pragma once
#include "card.h"
#include <algorithm>        //std::shuffle
#include <random>           //std::default_random_engine
#include <chrono>           //std::chrono::system_clock
#include <vector>

class deck
{
public:


	deck();
	~deck();

	void shuffle();
	void insert(card cardToInsert);
	card remove();
	card cardAtPos(int pos);

private:
	std::vector<card> deckVector;
};

