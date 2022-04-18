#pragma once
#include "Card.h"

class CardDeck{
    private:
    
    vector<Card> cards;
    void swap(int int1, int int2);
    
    public:
    CardDeck();
    void print();
    void printShort();
    void shuffle();
    Card drawCard();
    

};