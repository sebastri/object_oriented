#include "Card.h"
#include "CardDeck.h"
#include "BlackJack.h"
#include "std_lib_facilities.h"

//trekke to kort drawcard()


void BlackJack::question(){
    
    
    cout << "Din verdi: " << valuePlayer(handPlayer) << endl;;
    //cout << "Dealers verdi: " << valueDealer(handDealer) << endl;;
    string x = "";
    
    while (x != "s"){
    cout << "Vil du trekke et nytt kort, eller stå? (j/s)";
    cin >> x;
    if (x == "j"){
        drawPlayer();
        cout << "Hånda di nå: " << endl;
        printHand(handPlayer);
        cout << "Din verdi er nå: " << valuePlayer(handPlayer) << endl;
        
    }
    }
    
    if(x == "s"){
        cout << "Din verdi er fortsatt: " << valuePlayer(handPlayer) << endl;;
    }
    cout << "Dealers verdi: " << valueDealer(handDealer) << endl;
    printHand(handDealer);
    if (valueDealer(handDealer)<valuePlayer(handPlayer) && valueDealer(handDealer) <=21){
        while (valueDealer(handDealer) < 17){
            cout << "Dealer trekker nytt kort" << endl;
        drawDealer();
        printHand(handDealer);
        cout << "Dealers verdi: " << valueDealer(handDealer) << endl;
        }
    }
   

}

bool BlackJack::isAce(vector<Card> vec){
    for (auto i:vec){
        if (i.getRank() == Rank::ace){
            return true;
        }
    }
    return false;
}





void BlackJack::firstRound(){
    
    Card c2 = cards.drawCard();
    handPlayer.push_back(c2);

    Card c = cards.drawCard();
    handDealer.push_back(c);

    handPlayer.push_back(cards.drawCard());
    handDealer.push_back(cards.drawCard());
    
}

void BlackJack::drawPlayer(){
    handPlayer.push_back(cards.drawCard());
}

void BlackJack::drawDealer(){
    handDealer.push_back(cards.drawCard());
    
}


int rankToInt(Rank invalue){
    int value = rankValue.at(invalue);
    return value;
}

void BlackJack::initialGame(){
    handPlayer.clear();
    handDealer.clear();
}


int BlackJack::valuePlayer(vector<Card> vec){
    int value = 0;
    for (auto i:vec){
        Rank r = i.getRank();
        value += rankToInt(r);
    }
    for (auto i:vec){
        if (isAce(handPlayer)){
            if (value + 10 <= 21){
                // cout << "Oi du fikk et ess!" << endl;
                value += 10;
                
            }
        }
    }
    //cout << value << endl;
    return value;
}
    
int BlackJack::valueDealer(vector<Card> vec){
    int valueDealer = 0;
    for (auto i:vec){
        Rank r = i.getRank();
        valueDealer += rankToInt(r);
    }
    for (auto i:vec){
        if (isAce(handPlayer)){
            if (valueDealer + 10 <= 21){
            valueDealer += 10;
            }
        }
        
        
    }
    //cout << valueDealer << endl;
    return valueDealer;
}

void BlackJack::valueOneCard(vector<Card> vec){
    int value = 0;
    for (unsigned int i = 0; i < 1; i++){
        Rank r = vec[i].getRank();
        value += rankToInt(r);
    }
    cout << value << endl;
}

void BlackJack::printHand(vector<Card> vec){
    for (auto i:vec){
        cout << i.toString() << endl;
    }
}
void BlackJack::printHandDealer(vector<Card> vec){
    for (unsigned int i = 0; i < 1; i++){
        cout << vec[i].toString() << endl;
    }
}
void BlackJack::playGame(){
    
    

    
    int i = -1;

    while (i != 0){
    initialGame();
    cards.shuffle();
    firstRound();
    cout << "Dealers hånd: " << endl;
    printHandDealer(handDealer);
    cout << "Dealers verdi: ";
    valueOneCard(handDealer);
    cout << "Din hånd: " << endl;
    printHand(handPlayer);
    valuePlayer(handPlayer);

    
    question();

    if (valuePlayer(handPlayer) > 21 && valueDealer(handDealer) <= 21){
        cout << "\n" << "Du tapte!" << "\n" << endl;
    }
    else if (valuePlayer(handPlayer)<valueDealer(handDealer) && valueDealer(handDealer) <= 21){
        cout << "\n" << "Du tapte!" << "\n" << endl;
    }
    else if (valuePlayer(handPlayer)==valueDealer(handDealer)){
        cout << "\n" << "Uavgjort!" << "\n" << endl;
    }
    else if (valuePlayer(handPlayer)>valueDealer(handDealer) && valuePlayer(handPlayer) <=21){
        cout << "\n" << "Du vant!" << "\n" << endl;
    }

    else if (valuePlayer(handPlayer) <= 21 && valueDealer(handDealer) > 21){
        cout << "\n" << "Du vant!" << "\n" << endl;
    }

    
    }
}

