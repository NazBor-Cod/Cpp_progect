#pragma once
#include "Header.h"

class Player
{
	public:
		Player();
		void TakeCard(Card card);
		int GetScore();
		void SetScore(int tmp);
	private:
		int _score;
		int _turn;
};

