#ifndef ISSTRAIGHT_H
#define ISSTRAIGHT_H

#include "cards2.h"

int isStraight(PlayerDECK P, HouseDECK H);

int isStraight(PlayerDECK P, HouseDECK H)
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

    // Sort the values in ascending order
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 7; j++)
        {
            if (values[j] < values[i])
            {
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }

    // Check for a straight
    int count = 1;
    for (int i = 0; i < 6; i++)
    {
        if (values[i] + 1 == values[i + 1])
        {
            count++;
        }
        else if (values[i] != values[i + 1])
        {
            count = 1;
        }

        if (count == 5)
        {
            return 1; // Straight detected
        }
    }

    return 0; // No straight
}

#endif
