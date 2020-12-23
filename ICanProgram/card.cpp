#include "card.h"

card::card()
{
    value = static_cast<enum value>(-1);
    suit = static_cast<enum suit>(-1);
}

card::card(int inValue, int inSuit)
{
    value = static_cast<enum value>(inValue);
    suit = static_cast<enum suit>(inSuit);
}

std::string card::translateValue()
{
    switch (value) {
    case 0: return("Ace");
        break;
    case 1: return("Two");
        break;
    case 2: return("Three");
        break;
    case 3: return("Four");
        break;
    case 4: return("Five");
        break;
    case 5: return("Six");
        break;
    case 6: return("Seven");
        break;
    case 7: return("Eight");
        break;
    case 8: return("Nine");
        break;
    case 9: return("Ten");
        break;
    case 10: return("Jack");
        break;
    case 11: return("Queen");
        break;
    case 12: return("King");
        break;
    default: return("ERROR");
        break;
    }
}

std::string card::translateSuit()
{
    switch (suit) {
    case 0: return("Club");
        break;
    case 1: return("Diamond");
        break;
    case 2: return("Heart");
        break;
    case 3: return("Spade");
        break;
    default: return("ERROR");
        break;
    }
}

int card::getValue()
{
    if (static_cast<int>(value) < 10)
    {
        return (static_cast<int>(value) + 1);
    }

    else
    {
        return 10;
    }
    //add another elseif for errors?
}