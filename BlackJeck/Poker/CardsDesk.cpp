#include "CardsDesk.h"



CardsDesk::CardsDesk()
{
	_counter = 0;
	for (int i = 0; i < 52; i++)
		_cards[i] = i;
}

void CardsDesk::Shuffle()
{
	_counter = 0;
	for (int i = 0; i < 52; i++)
	{
		int rnd = rand() % 52;
		int tmp = _cards[i];
		_cards[i] = _cards[rnd];
		_cards[rnd] = tmp;
	}
}



