//#include "LibraryHeader.h"
//#include "../00_00-adlib/GetUserInput.cpp"
#include "Header.h"
#include "Player.h"

int main()
{
	srand(time(NULL));
	Player player;
	Player pc;
	CardDesk desk;
	desk.Shuffle();
	do//true
	{
		system("cls");
		cout << "Blackjack\t\tScore:" << player.GetScore() << "\n1. Take card\n2. End\n0. Exit\n";
		switch (_getch())//GetUserInput(1, 0, 2, "Select"))
		{
		case 49:
		{
			Card card(desk.GetCard());
			player.TakeCard(card);
			cout << card << endl;
			system("pause");
			if (pc.GetScore()<20)
			{
				pc.TakeCard(desk.GetCard());
			}
			break;
		}
		case 50:
		{
			while (pc.GetScore() < 15)
			{
				pc.TakeCard(desk.GetCard());
			}
			int playerScore = player.GetScore();
			int pcScore = pc.GetScore();
			cout << "Your score: " << playerScore << endl
				<< "PC score: " << pcScore << endl;
			if (pcScore>22 && playerScore<22)
			{
				cout << "You win!\n";
			}
			else if (playerScore < 22 && playerScore > pcScore)
			{
				cout << "You win!\n";
			}
			else if (playerScore < 22 && playerScore == pcScore)
			{
				cout << "Push\n";
			}
			else
			{
				cout << "You lose\n";
			}
			player.SetScore(0);
			pc.SetScore(0);
			break;
		}
		case 48:
			return 0;
		}
	} while (_getch() != 48);

}



/*//#include "LibraryHeader.h"
//#include "../00_00-adlib/GetUserInput.cpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <conio.h>
#include <time.h>

using namespace std;

const int DESK_SIZE = 52;

enum Suit { Diamonds, Hearts, Spades, Clubs };
enum Rank { R2, R3, R4, R5, R6, R7, R8, R9, R10, Jack, Queen, King, Ace };

class Card
{
public:
	friend class CardDesk;
	Rank GetRank()
	{
		return Rank(_weight % 13);
	}
	Suit GetSuit()
	{
		return Suit(_weight / 13);
	}
	friend std::ostream& operator<<(std::ostream& os, Card other)
	{
		switch (other._weight / 13)
		{
		case Diamonds:
			os << "Diamonds ";
			break;
		case Hearts:
			os << "Hearts ";
			break;
		case Spades:
			os << "Spades ";
			break;
		case Clubs:
			os << "Clubs ";
			break;
		}

		switch (other._weight % 13)
		{
		case R2:
		case R3:
		case R4:
		case R5:
		case R6:
		case R7:
		case R8:
		case R9:
		case R10:
			os << other._weight % 13 + 2;
			break;
		case Jack:
			os << "Jack ";
			break;
		case Queen:
			os << "Queen ";
			break;
		case King:
			os << "King ";
			break;
		case Ace:
			os << "Ace ";
			break;
		}
		return os;
	}

private:
	int _weight;
	Card(int weight) : _weight(weight)
	{
	}
};

class CardDesk
{
public:
	CardDesk()
	{
		_counter = 0;
		for (int i = 0; i < DESK_SIZE; ++i)
		{
			_cards[i] = i;
		}
	}

	void Shuffle()
	{
		_counter = 0;
		for (int i = 0; i < DESK_SIZE; ++i)
		{
			int rnd = rand() % DESK_SIZE;
			std::swap(_cards[i], _cards[rnd]);
		}
	}

	Card GetCard()
	{
		if (_counter++ == DESK_SIZE)
		{
			Shuffle();
		}
		return Card(_cards[_counter]);
	}

private:
	int _cards[DESK_SIZE];
	int _counter;
};

class Player
{
public:
	Player()
	{
		_score = 0;
		_turn = 0;
	}
	void TakeCard(Card card)
	{
		int rank = card.GetRank() + 2;
		if (rank < 11)
		{
			_score += rank;
		}
		else if (rank < 14)
		{
			_score += 10;
		}
		else
		{
			if (_score + 11 < 22)
			{
				_score += 11;
			}
			else
			{
				_score += 1;
			}
		}
	}
	int GetScore()
	{
		return _score;
	}
	void SetScore(int tmp)
	{
		_score = tmp;
	}

private:
	int _score;
	int _turn;
};

int main()
{
	srand(time(NULL));
	Player player;
	Player pc;
	CardDesk desk;
	desk.Shuffle();
	do//true
	{
		system("cls");
		cout << "Blackjack\t\tScore:" << player.GetScore() << "\n1. Take card\n2. End\n0. Exit\n";
		switch (_getch())//GetUserInput(1, 0, 2, "Select"))
		{
		case 49:
		{
			Card card(desk.GetCard());
			player.TakeCard(card);
			cout << card << endl;
			system("pause");
			pc.TakeCard(desk.GetCard());
			break;
		}
		case 50:
		{
			while (pc.GetScore() < 18)
			{
				pc.TakeCard(desk.GetCard());
			}
			int playerScore = player.GetScore();
			int pcScore = pc.GetScore();
			cout << "Your score: " << playerScore << endl
				<< "PC score: " << pcScore << endl;
			if (pcScore>22 && playerScore<22)
			{
				cout << "You win!\n";
			}
			else if (playerScore < 22 && playerScore > pcScore)
			{
				cout << "You win!\n";
			}
			else if (playerScore < 22 && playerScore == pcScore)
			{
				cout << "Push\n";
			}
			else
			{
				cout << "You lose\n";
			}
			player.SetScore(0);
			pc.SetScore(0);
			break;
		}
		case 48:
			return 0;
		default:
			return 1;
		}
	} while (_getch() != 48);

}



*/