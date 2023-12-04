// Copyright A.T. Chamillard. All Rights Reserved.

#include <iostream>
#include <string>

#include "Deck.h"
#include "Card.h"
#include "Player.h"

using namespace consoleCards;

// IMPORTANT: Only add code in the section
// indicated below. The code I've provided
// makes your solution work with the 
// automated grader on Coursera

/**
 * Programming Assignment 3
 * @return exit status
*/
int main()
{
    // loop while there's more input
    std::string Input;
    std::getline(std::cin, Input);
    while (Input[0] != 'q')
    {
        // Add your code between this comment
        // and the comment below. You can of
        // course add more space between the
        // comments as needed

        // declare a deck variable
        // DON'T SHUFFLE THE DECK
        Deck deck;
       

        // deal 2 cards each to 4 players (deal properly, dealing
        // the first card to each player before dealing the
        // second card to each player)
        std::vector<Player> players;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == 0) players.push_back(Player());
                players[j].AddCard(deck.TakeTopCard());
            }
        }


        // deal 1 more card to players 2 and 3
        players[1].AddCard(deck.TakeTopCard());
        players[2].AddCard(deck.TakeTopCard());


        // flip all the cards over
        for (int i = 0; i < 4; i++) {
            players[i].FlipCards();
        }

        // Print the cards for player 1
        players[0].Print();

        // Print the cards for player 2
        players[1].Print();


        // Print the cards for player 3
        players[2].Print();


        // Print the cards for player 4
        players[3].Print();


        // Don't add or modify any code below
        // this comment
        std::getline(std::cin, Input);
    }
}