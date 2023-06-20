#ifndef ISSTRIGHTFLUSH_H
#define ISSTRIGHTFLUSH_H

#include "cards2.h"

int isStraightFlush(PlayerDECK P, HouseDECK H);

int isStraightFlush(PlayerDECK P, HouseDECK H)
{
    // Check if there is a flush
    if (!isFlush(P, H))
        return 0; // Not a straight flush
    
    // Check if there is a straight within the flush cards
    int suit = -1;
    int values[5];
    int acesCount = 0;
    
    // Check player's hand
    for (int i = 0; i < 2; i++)
    {
        if (P[i]->CC == suit || suit == -1)
        {
            suit = P[i]->CC;
            values[i] = P[i]->Value;
            if (P[i]->Value == 1)
                acesCount++;
        }
        else
            return 0; // Not a straight flush
    }
    
    // Check house cards
    for (int i = 0; i < 5; i++)
    {
        if (H[i] != NULL && (H[i]->CC == suit || suit == -1))
        {
            suit = H[i]->CC;
            values[2 + i] = H[i]->Value;
            if (H[i]->Value == 1)
                acesCount++;
        }
        else
            return 0; // Not a straight flush
    }
    
    // Sort the values array in ascending order
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (values[j] > values[j + 1])
            {
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
    
    // Check if the values form a straight
    for (int i = 0; i < 4; i++)
    {
        if (values[i] + 1 != values[i + 1])
        {
            if (acesCount > 0 && values[i] == 13 && values[i + 1] == 1)
                continue; // Handle Ace (A) as both lowest and highest
            else
                return 0; // Not a straight flush
        }
    }
    
    return 1; // Straight flush detected
}


#endif