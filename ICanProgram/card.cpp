#include "card.h"

card::card(int inValue, int inSuit)
{
    value = static_cast<enum value>(inValue);
    suit = static_cast<enum suit>(inSuit);
}

std::string card::translateValue()
{
    std::string cardValue;

    switch (value) {
    case 0: cardValue = "Ace";
        break;
    case 1: cardValue = "Two";
        break;
    case 2: cardValue = "Three";
        break;
    case 3: cardValue = "Four";
        break;
    case 4: cardValue = "Five";
        break;
    case 5: cardValue = "Six";
        break;
    case 6: cardValue = "Seven";
        break;
    case 7: cardValue = "Eight";
        break;
    case 8: cardValue = "Nine";
        break;
    case 9: cardValue = "Ten";
        break;
    case 10: cardValue = "Jack";
        break;
    case 11: cardValue = "Queen";
        break;
    case 12: cardValue = "King";
        break;
    default: cardValue = "ERROR";
        break;
    }
    return cardValue;
}

std::string card::translateSuit()
{
    std::string cardValue;

    switch (suit) {
    case 0: cardValue = "Club";
        break;
    case 1: cardValue = "Diamond";
        break;
    case 2: cardValue = "Heart";
        break;
    case 3: cardValue = "Spade";
        break;
    default: cardValue = "ERROR";
        break;
    }
    return cardValue;
}