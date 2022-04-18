#pragma once
#include "Card.h"
#include "CardDeck.h"
#include "std_lib_facilities.h"

const map<Rank, int> rankValue{
    {Rank::two, 2},
    {Rank::three, 3},
    {Rank::four, 4},
    {Rank::five, 5},
    {Rank::six, 6},
    {Rank::seven, 7},
    {Rank::eight, 8},
    {Rank::nine, 9},
    {Rank::ten, 10},
    {Rank::jack, 10},
    {Rank::queen, 10},
    {Rank::king, 10},
    {Rank::ace, 1 },

};

int rankToInt(Rank value);

class BlackJack{

    public:
    void firstRound();
    void playGame();
    void initialGame();


    void question();
    void printHand(vector<Card> vec);
    void printHandDealer(vector<Card> vec);

    void valueOneCard(vector<Card> vec);

    bool isAce(vector<Card> vec);
    void changeAce(vector<Card> vec);

    int valuePlayer(vector<Card> vec);
    int valueDealer(vector<Card> vec);

    void drawPlayer();
    void drawDealer();



    private:
    
    vector<Card> handPlayer;
    vector<Card> handDealer;
    CardDeck cards;
    

};