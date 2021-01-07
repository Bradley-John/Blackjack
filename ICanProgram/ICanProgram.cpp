// ICanProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "card.h"
#include "hand.h"
#include "deck.h"
#include "blackjack.h"

int main()
{
    //Current TODO:
    //Standardize comments
    //Add actual bet/gamble system

    blackjack game;
    int continueInt = 1;

    while (continueInt == 1)
    {
        continueInt = game.play();
    }

    //check if either has blackjack
        ////win for player/dealer if so, tie if both
    //display one card of dealer
    //display both for player
    //give player option to hit/stand
        ////if stand, dealer reveal second card
            //////dealer hit until X amount, reveal 1 card at time per hit. hit until bust or hit X amount
        ////if hit, player draws and reveals another card for themselves, add new total and determine if blackjack or bust
            //////player gets hit/stand option again until either bust or stand
    //compare values and determine winner
    //add points bet
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file