#pragma once
#include "Header.h"
const int DESK_SIZE = 52;

enum Suit { Diamonds, Hearts, Spades, Clubs };
enum Rank { R2, R3, R4, R5, R6, R7, R8, R9, R10, Jack, Queen, King, Ace };



class Card
{
public:
	friend class CardDesk;
	Rank GetRank();
	Suit GetSuit();
	friend std::ostream& operator<<(std::ostream& os, Card other);
private:
	int _weight;
	Card(int weight) : _weight(weight)
	{
	}
};


class CardDesk
{
public:
	CardDesk();
	void Shuffle();
	Card GetCard();

private:
	int _cards[DESK_SIZE];
	int _counter;

};