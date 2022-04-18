#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "BlackJack.h"

// Enumarasjoner Oppgave e) Enklere å finne fram?

int main()
{

	system("chcp 65001 > nul");
	srand(static_cast<unsigned int>(time(nullptr)));

	// suitToString(Suit::clubs);
	// Card c(Suit::clubs, Rank::four);
	// cout << c.toStringShort() << endl;

	// CardDeck so;
	// so.print();
	// cout << "\n\n";
	// so.drawCard();
	// cout << "\n\n";
	// so.print();
	// cout << "\n\n";
	
	BlackJack play;
	play.playGame();
	
	// int test = rankToInt(Rank::jack);
	// cout << test;

	

	

	keep_window_open();
}

//------------------------------------------------------------------------------
