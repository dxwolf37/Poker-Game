#ifndef ISFLUSH_H
#define ISFLUSH_H

#include "cards2.h"

// Function prototype
int isFlush(PlayerDECK P, HouseDECK H);

int isFlush(PlayerDECK P, HouseDECK H)
{
    // count the number of cards of each suit
    int suits[4] = {0}; // 0: Clubs, 1: Spades, 2: Hearts, 3: Diamonds

    // Count suits in player's hand
    for (int i = 0; i < 2; i++)
    {
        int suit = P[i]->CC;
        suits[suit]++;
    }

    // count suits in house cards
    for (int i = 0; i < 5; i++)
    {
        if (H[i] != NULL)
        {
            int suit = H[i]->CC;
            suits[suit]++;
        }
    }

    // check if any suit has 5 or more cards
    for (int i = 0; i < 4; i++)
    {
        if (suits[i] >= 5)
        {
            return 1; // flush 
        }
    }

    return 0; // No flush
}

#endif
