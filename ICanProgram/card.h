#pragma once
#include <string>

class card
{
public:
    enum value { Ace = 0, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
    enum suit { Club = 0, Diamond, Heart, Spade };

    card(int inValue, int inSuit);
    std::string translateValue();
    std::string translateSuit();

private:
    value value;
    suit suit;
};