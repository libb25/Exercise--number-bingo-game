#include "Creature.h"
#include <iostream>
using namespace std;

int Creature::GetBingoTableValue(int key)
{
	return _bingoTable[key];

}

void Creature::BingolineCountPlus()
{
	_bingolineCount++;
}

int Creature::BingolineCountCheck()
{
	return _bingolineCount;
}

void Creature::ClearBingoNumber(int attack)
{
	for (int i = 0; i < 25; i++)
	{
		if (_bingoTable.find(i)->second == attack)
		{
			_bingoTable[i] = 0;
			break;
		}
			
	}
	
}

void Creature::PrintBingoTable()
{
	cout << "---------------------------"<< endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout.width(2);
			cout << _bingoTable.find((5*i)+j)->second << " ";
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;
}
