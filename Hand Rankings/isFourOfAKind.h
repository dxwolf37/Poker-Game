#ifndef ISFOUROFAKIND_H
#define ISFOUROFAKIND_H

#include "cards2.h"

int isFourOfAKind(PlayerDECK P, HouseDECK H);

int isFourOfAKind(PlayerDECK P, HouseDECK H)
{
    int values[13] = {0}; // Array to store the count of each card value
    
    // Count the occurrences of each card value in the player's hand
    for (int i = 0; i < 2; i++)
    {
        int value = P[i]->Value;
        values[value - 1]++;
    }
    
    // Count the occurrences of each card value in the house cards
    for (int i = 0; i < 5; i++)
    {
        if (H[i] != NULL)
        {
            int value = H[i]->Value;
            values[value - 1]++;
        }
    }
    
    // Check if there is a four of a kind
    for (int i = 0; i < 13; i++)
    {
        if (values[i] >= 4)
            return 1; // Four of a kind 
    }
    
    return 0; // No four of a kind
}

#endif 
