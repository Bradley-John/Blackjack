#include "deck.h"

//Initializes with a full sized/4 suit,52 card deck
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
    deckVector.erase(deckVector.begin(), deckVector.end());
}

//Uses std::shuffle to shuffle the deck vector. New seed each time it is called since we use epoch time for the seed
void deck::shuffle()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //seed for rng
    std::shuffle(deckVector.begin(), deckVector.end(), std::default_random_engine(seed)); //shuffling deck

}

void deck::insert(card cardToInsert)
{
    deckVector.push_back(cardToInsert);
}

//Remove and return the card from back of the vector
card deck::remove()
{
    card removedCard = deckVector.back();
    deckVector.pop_back();
    return(removedCard);
}

//Returns specific card in deck at given position
card deck::cardAtPos(int pos)
{
    return(deckVector[pos]);
}