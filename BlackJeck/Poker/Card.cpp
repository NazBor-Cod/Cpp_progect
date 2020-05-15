#include "Card.h"

Rank Card::GetRank()
{
	return Rank(_weight % 13);
}

Suit Card::GetSuit()
{
	return Suit(_weight / 13);
}

std::ostream & operator<<(std::ostream & os, Card other)
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
