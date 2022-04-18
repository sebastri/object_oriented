#include "Card.h"

string suitToString(Suit insuit){
    string suit = suitStrings.at(insuit);
    return suit;
}

string rankToString(Rank inrank){
    string rank = rankStrings.at(inrank);
    return rank;
}

Card::Card(Suit suit, Rank rank): s{suit}, r{rank}
{
}

Suit Card::getSuit(){
    return s;
}

Rank Card::getRank(){
    return r;
}


string Card::toString(){
    string streng = suitToString(s) + " of " + rankToString(r);
    
    return streng;
}

string Card::toStringShort(){
    string str = suitToString(s)[0] + to_string(static_cast<int>(r));
    
    return str;
}



