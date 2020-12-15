// ICanProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
#include "card.h"

using std::cout;
using std::cin;

int main()
{

    //cout << "Type\n";
    //cin >> input;
    //cout << "\n" << input;

    //value tester;

    std::stack<card> deck;

    for (int suit = 0; suit < 4; suit++)
    {
        for (int value = 0; value < 13; value++)
        {
            card cardTest(value, suit);
            deck.push(cardTest);
            //cout << value << " " << suit << "\n";
            //cout << cardTest.translateValue() << " " << cardTest.translateSuit() << "\n";
        }
    }

    for (int i = 0; i < 52; i++)
    {
        cout << deck.top().translateValue() << " " << deck.top().translateSuit() << "\n";
        deck.pop();
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