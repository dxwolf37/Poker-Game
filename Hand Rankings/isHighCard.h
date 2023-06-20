#ifndef ISHIGHCARD_H
#define ISHIGHCARD_H

#include "cards2.h"

int isHighCard(PlayerDECK P, HouseDECK H);

int isHighCard(PlayerDECK P, HouseDECK H)
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

    // Find the highest card value
    int highestCard = values[0];

    for (int i = 1; i < 7; i++)
    {
        if (values[i] > highestCard)
        {
            highestCard = values[i];
        }
    }

    // Check if the highest card is an Ace (Value = 1)
    if (highestCard == 1)
    {
        return 1; // High card is Ace
    }

    return 0; // High card is not Ace
}

#endif
