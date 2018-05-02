#ifndef Deck_h
#define Deck_h
#include "Card.h"
#include "Player.h"

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;
const int SIZE = 52;
Card card[52]; // card array

			   //Class Deck definition
class Deck
{
	//private card variable
	Card deckOfCards[SIZE];

public:

	void initialize()
	{
		//the string to perform the description
		string cardDesc;
		char name[10];
		int setFlag;

		//the for loop to initialize the deck Of Cards
		for (int i = 1; i <= SIZE; i++)
		{
			setFlag = 0;
			if (i == 1 || i == 14 || i == 27 || i == 40)
			{
				cardDesc = "Ace";
				setFlag = 1;
			}

			else if (i == 11 || i == 24 || i == 37 || i == 50)
			{
				cardDesc = "Jack";
				setFlag = 1;
			}

			else if (i == 12 || i == 25 || i == 38 || i == 51)
			{
				cardDesc = "Queen";
				setFlag = 1;
			}

			else if (i == 13 || i == 26 || i == 39 || i == 52)
			{
				cardDesc = "King";
				setFlag = 1;
			}

			if (i <= 13)
			{
				deckOfCards[i - 1].setCardSuit(Spades);
				deckOfCards[i - 1].setCardNumber(i);

				if (setFlag == 0)
				{
					(deckOfCards[i - 1].getCardNumber(), name, 10);
					cardDesc = ((string)name);
				}

				cardDesc = " of Spades";
				deckOfCards[i - 1].setDescription(cardDesc);
			}

			else if (i > 13 && i <= 26)
			{
				deckOfCards[i - 1].setCardSuit(Hearts);
				deckOfCards[i - 1].setCardNumber(i - 13);

				if (setFlag == 0)
				{
					(deckOfCards[i - 1].getCardNumber(), name, 10);
					cardDesc = ((string)name);
				}

				cardDesc = " of Hearts";
				deckOfCards[i - 1].setDescription(cardDesc);
			}

			else if (i > 26 && i <= 39)
			{
				deckOfCards[i - 1].setCardSuit(Diamonds);
				deckOfCards[i - 1].setCardNumber(i - 26);

				if (setFlag == 0)
				{
					(deckOfCards[i - 1].getCardNumber(), name, 10);
					cardDesc = ((string)name);
				}

				cardDesc = " of Diamonds";
				deckOfCards[i - 1].setDescription(cardDesc);
			}

			else
			{
				deckOfCards[i - 1].setCardSuit(Clubs);
				deckOfCards[i - 1].setCardNumber(i - 39);

				if (setFlag == 0)
				{
					(deckOfCards[i - 1].getCardNumber(), name, 10);
					cardDesc = ((string)name);
				}

				cardDesc = (" of Clubs");
				deckOfCards[i - 1].setDescription(cardDesc);
			}
		}
	}

	void shuffle()
	{
		Card cardObj;
		int numRandm;
		srand(time(NULL));

		for (int i = 0; i < SIZE; i++)
		{
			numRandm = rand() % 52;
			cardObj = deckOfCards[i];
			deckOfCards[i] = deckOfCards[numRandm];
			deckOfCards[numRandm] = cardObj;
		}
	}

	void deal()
	{
		Player players[4];
		for (int j = 0; j < 13; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				players[i].addCard(deckOfCards[i + 4 * j]);
			}
		}
		sort(players);
		display(players);
	}

	void sort(Player players[4])
	{
		for (int itr = 0; itr < 4; itr++)
		{
			players[itr].sortCardsInHand();
			players[itr].computeScore();
		}
	}

	void display(Player players[4])
	{
		Suit suit;
		int number;

		cout << endl << setw(14) << "Player 1" << setw(16) << "Player 2" << setw(16) << "Player 3" << setw(16) << "Player 4";
		cout << endl << setw(14) << "--------" << setw(16) << "--------" << setw(16) << "--------" << setw(16) << "--------" << endl;
		cout << endl << setw(14) << players[0].getPlayerScore() << setw(16) << players[1].getPlayerScore() << setw(16) << players[2].getPlayerScore() << setw(16) << players[3].getPlayerScore() << endl;
		cout << endl << setw(14) << "--------" << setw(16) << "--------" << setw(16) << "--------" << setw(16) << "--------" << endl << endl;

		for (int j = 0; j < 13; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				cout << players[i].getCard(j);
			}
			cout << endl;
		}
	}

	void playGame()
	{

	}
};

#endif /* Deck_h */