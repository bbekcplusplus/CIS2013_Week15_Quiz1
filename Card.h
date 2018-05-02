#ifndef Card_h
#define Card_h

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;

//The enumerated data types
enum Suit
{
	Clubs = 1,
	Diamonds = 2,
	Hearts = 3,
	Spades = 4
};

//The Card class
class Card
{
 
private:
	string description;
	Suit suit;
	int number;

public:

	// default constructor
	Card()
	{
		number = 0;
		description = "";
	}

	// get function for suit
	Suit getCardSuit()
	{
		return suit;
	}

	// set function for suit
	void setCardSuit(Suit m_suit)
	{
		suit = m_suit;
	}

	int getCardNumber()
	{
		return number;
	}

	// set function for card
	void setCardNumber(int m_num)
	{
		number = m_num;
	}

	// get function for description
	string getCardDescription()
	{
		return description;
	}

	// set the card description
	void setDescription(string m_description)
	{
		description = m_description;
	}

	// Overloaded operator < function
	bool operator <(const Card& card2)
	{
		if (suit < card2.suit)
			return true;

		else if (suit > card2.suit)
			return false;

		else
		{
			if (number == 1)
				return false;

			else if (card2.number == 1)
				return true;

			else if (card2.number < number)
				return true;
		}

		return false; // may be incorrect
	}
};

#endif /* Card_h */