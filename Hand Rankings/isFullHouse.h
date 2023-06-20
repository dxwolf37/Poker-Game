#ifndef ISFULLHOUSE_H
#define ISFULLHOUSE_H

#include "cards2.h"

int isFullHouse(PlayerDECK P, HouseDECK H);

int isFullHouse(PlayerDECK P, HouseDECK H)
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
    
    int threeCount = 0;
    int twoCount = 0;
    
    // Check if there is a three of a kind and a pair
    for (int i = 0; i < 13; i++)
    {
        if (values[i] == 3)
            threeCount++;
        else if (values[i] == 2)
            twoCount++;
    }
    
    // Check if a full house is present
    if (threeCount >= 1 && twoCount >= 1)
        return 1; // Full house 
    
    return 0; // No full house
}

#endif
