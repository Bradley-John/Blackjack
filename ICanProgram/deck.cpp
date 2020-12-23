#include "deck.h"

deck::deck()
{
    for (int suit = 0; suit < 4; suit++)
    {
        for (int value = 0; value < 13; value++)
        {
            card cardTest(value, suit);
            deckVector.push_back(cardTest);
        }
    }
}


deck::~deck()
{
	delete[] &deckArray;
}


void deck::shuffle()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //seed for rng
    std::shuffle(deckVector.begin(), deckVector.end(), std::default_random_engine(seed)); //shuffling deck

}

void deck::insert(card cardToInsert)
{
    deckVector.push_back(cardToInsert);
}

card deck::remove()
{
    card removedCard = deckVector.back();
    deckVector.pop_back();
    return(removedCard);
}