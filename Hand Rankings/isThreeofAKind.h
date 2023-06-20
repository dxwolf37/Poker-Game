#ifndef ISTHREEOFAKIND_H
#define ISTHREEOFAKIND_H

#include "cards2.h"

int isThreeofAKind(PlayerDECK P, HouseDECK H);

int isThreeofAKind(PlayerDECK P, HouseDECK H)
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

    // Check for three of a kind
    for (int i = 1; i <= 13; i++)
    {
        if (count[i] >= 3)
        {
            return 1; // Three of a kind detected
        }
    }

    return 0; // No three of a kind
}

#endif
