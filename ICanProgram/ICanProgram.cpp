// ICanProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "card.h"
#include "hand.h"
#include "deck.h"
#include "blackjack.h"

using std::cout;
using std::cin;             //I just don't like typing std:: on these, no reason for it

int main()
{
    deck currentDeck;
    hand dealerHand;
    hand playerHand;

    currentDeck.shuffle();

    playerHand.addCard(currentDeck.remove());
    dealerHand.addCard(currentDeck.remove());
    playerHand.addCard(currentDeck.remove());
    dealerHand.addCard(currentDeck.remove());

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


    /*
    for (int i = 0; i < 52; i++)
    {
        cout << currentDeck.cardAtPos(i).translateValue() << " " << currentDeck.cardAtPos(i).translateSuit() << "\n";
    }

    cout << "\n";
    currentDeck.shuffle();

    for (int i = 0; i < 52; i++)
    {
        cout << currentDeck.cardAtPos(i).translateValue() << " " << currentDeck.cardAtPos(i).translateSuit() << "\n";
    }

    hand currentHand;
    currentHand.addCard(currentDeck.remove());
    currentHand.addCard(currentDeck.remove());

    for (int i = 0; i < 2; i++)
    {
        cout << "\n" << currentHand.cardAtPos(i).translateValue() << " " << currentHand.cardAtPos(i).translateSuit() << " " << currentHand.cardAtPos(i).getValue() << "\n";
    }

    cout << "\n";

    for (int i = 0; i <50; i++)
    {
        cout << currentDeck.cardAtPos(i).translateValue() << " " << currentDeck.cardAtPos(i).translateSuit() << "\n";
    }

    cout << "\n";
    currentDeck.insert(currentHand.remove());
    currentDeck.insert(currentHand.remove());

    for (int i = 0; i < 52; i++)
    {
        cout << currentDeck.cardAtPos(i).translateValue() << " " << currentDeck.cardAtPos(i).translateSuit() << "\n";
    }*/

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