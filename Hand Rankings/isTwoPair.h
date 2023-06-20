#ifndef ISTWOPAIR_H
#define ISTWOPAIR_H

#include "cards2.h"

// Function prototype
int isTwoPair(PlayerDECK P, HouseDECK H);

// Function implementation
int isTwoPair(PlayerDECK P, HouseDECK H)
{
    int values[7] = {0}; // Array to store the values of cards

    // Store the values of the player's hand
    for (int i = 0; i < 2; i++)
    {
        values[i] = P[i]->Value;
    }

    // Store the values of the house cards
    for (int i = 0; i < 5; i++)
    {
        if (H[i] != NULL)
        {
            values[i + 2] = H[i]->Value;
        }
    }

    // Count the occurrences of each value
    int count[14] = {0}; // Array to store the count of each value

    for (int i = 0; i < 7; i++)
    {
        count[values[i]]++;
    }

    // Check for two pairs
    int pairCount = 0;

    for (int i = 1; i <= 13; i++)
    {
        if (count[i] >= 2)
        {
            pairCount++;
        }
    }

    if (pairCount >= 2)
    {
        return 1; // Two pairs detected
    }

    return 0; // No two pairs
}

#endif
