#pragma once
#include "card.h"
#include <algorithm>        //std::shuffle
#include <random>           //std::default_random_engine
#include <chrono>           //std::chrono::system_clock
#include <array>

class deck
{
public:


	deck();
	~deck();

	void shuffle();
	void insert();
	void remove();

private:
	int size = 0;
	std::array<card,52> deckArray;
};

