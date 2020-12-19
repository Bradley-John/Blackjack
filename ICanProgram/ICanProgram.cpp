// ICanProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>        //std::shuffle
#include <random>           //std::default_random_engine
#include <chrono>           //std::chrono::system_clock

#include "card.h"

using std::cout;
using std::cin;             //I just don't like typing std:: on these, no reason for it

int main()
{
    std::vector<card> deck;

    for (int suit = 0; suit < 4; suit++)
    {
        for (int value = 0; value < 13; value++)
        {
            card cardTest(value, suit);
            deck.push_back(cardTest);
        }
    }


    for (int i = 0; i < 52; i++)
    {
        cout << deck[i].translateValue() << " " << deck[i].translateSuit() << "\n";
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //seed for rng

    shuffle(deck.begin(), deck.end(), std::default_random_engine(seed)); //shuffling deck


    cout << "\n" << deck.size() << "\n\n";
    for (int i = 0; i < 52; i++)
    {
        cout << deck[i].translateValue() << " " << deck[i].translateSuit() << "\n";
    }

    card testcard = deck.back();
    deck.pop_back();
    card testcard2 = deck[1];
    deck.pop_back();
    //TODO make hand class
    //seed = std::chrono::system_clock::now().time_since_epoch().count(); //seed for rng

    //shuffle(deck.begin(), deck.end(), std::default_random_engine(seed)); //shuffling deck


    cout << "\n" << deck.size() << "\n\n";
    for (int i = 0; i < deck.size(); i++)
    {
        cout << deck[i].translateValue() << " " << deck[i].translateSuit() << "\n";
    }

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