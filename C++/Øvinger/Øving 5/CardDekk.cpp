#include "std_lib_facilities.h"
#include "CardDeck.h"
#include "Card.h"

CardDeck::CardDeck(){

for (auto i:suitStrings){
    for (auto j:rankStrings){
    Card c(i.first, j.first);
    cards.push_back(c);
    }
}
}

void CardDeck::swap(int int1, int int2){
    Card a = cards[int2];
    cards[int2] = cards[int1];
    cards[int1] = a;
}

void CardDeck::print(){
    for (unsigned int i = 0; i < cards.size(); i++){
        cout << cards[i].toString() << endl;
    }
}

void CardDeck::printShort(){
    for (unsigned int i = 0; i < cards.size(); i++){
        cout << cards[i].toStringShort() << endl;
    }
}

void CardDeck::shuffle(){
    for (unsigned int i = 0; i < cards.size(); i++)
    {
        swap(i, (rand()%(cards.size())));
    }
}

Card CardDeck::drawCard(){
    Card c = cards.back();
    //cout << cards.back().toString() << endl;
    cards.pop_back();
    return c;
}
