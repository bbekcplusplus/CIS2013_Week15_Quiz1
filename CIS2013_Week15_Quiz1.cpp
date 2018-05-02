
#include <iostream>
#include <string>
#include "Card.h"

#include "Deck.h"

#include <iostream>

using namespace std;

int main()
{
	Deck deckOfCards;
	deckOfCards.initialize();
	int choice = 1;
	cout << "Shuffling cards......." << endl;
	deckOfCards.shuffle();
	cout << "Cards are now shuffled... Here you go..." << endl;
	cout << "Dealing cards" << endl;
	deckOfCards.deal();
	cout << "Cards are now dealt" << endl;
	system("pause");
	return 0;
}