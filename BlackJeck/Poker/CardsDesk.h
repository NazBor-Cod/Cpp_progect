#pragma once
#include "LibraryHeader.h"

class CardsDesk
{
	int _cards[52];
	int _counter;
public:
	CardsDesk();
	void Shuffle();
public:
	Cards getNextCard()
	{
		++_counter;
		if (_counter == 52)
			Shuffle();
		return Cards(_cards[_counter]);
	}
};

