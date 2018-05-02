#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <sstream>
class Player
{
private:
	Card *cardsInHand;
	int countCard;
	int scores;
public:
	Player()
	{
		cardsInHand = new Card[13];
		countCard = 0;
		scores = 0;
	}

	void addCard(Card card)
	{
		cardsInHand[countCard] = card;
		countCard++;
		scores = 0;
	}

	void sortCardsInHand()
	{
		Card cardObj;
		int j;

		for (int i = 1; i < 13; i++)
		{
			cardObj = cardsInHand[i];
			j = i - 1;

			while (j >= 0 && cardsInHand[j] < cardObj)
			{
				cardsInHand[j + 1] = cardsInHand[j];
				j--;
			}
			cardsInHand[j + 1] = cardObj;
		}
	}

	string getCard(int index)
	{
		Suit suit;
		int number;
		ostringstream playerCardsAt;

		suit = cardsInHand[index].getCardSuit();
		number = cardsInHand[index].getCardNumber();

		if (suit == 1)
			playerCardsAt << setw(10) << "Club";

		else if (suit == 2)
			playerCardsAt << setw(10) << "Diamond";

		else if (suit == 3)
			playerCardsAt << setw(10) << "Heart";

		else
			playerCardsAt << setw(10) << "Spade";

		if (number == 1)
			playerCardsAt << setw(6) << "Ace";

		else if (number == 11)
			playerCardsAt << setw(6) << "Jack";

		else if (number == 12)
			playerCardsAt << setw(6) << "Queen";

		else if (number == 13)
			playerCardsAt << setw(6) << "King";

		else
			playerCardsAt << setw(6) << number;
		return playerCardsAt.str();
	}

	void computeScore()
	{
		Suit suit;
		int number;
		for (int i = 0; i < 13; i++)
		{
			suit = cardsInHand[i].getCardSuit();
			number = cardsInHand[i].getCardNumber();
			if (suit == 3)
				scores++;
			if (suit == 4 && number == 12)
				scores += 13;
		}
	}
	int getPlayerScore()
	{
		return scores;
	}
};
#endif