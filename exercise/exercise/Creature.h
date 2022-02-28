#pragma once
#include <map>
#include <memory>




class Creature
{
public:
	Creature()
	{
	/*	for (int i = 0; i < 25; ++i)
			_bingoTable.insert(std::pair<int, int>(i, 0));*/
	}
	virtual ~Creature()
	{

	}
	int GetBingoTableValue(int key);
	void BingolineCountPlus();
	int BingolineCountCheck();

	void ClearBingoNumber(int attack);
	void PrintBingoTable();

protected:

	std::map<int, int> _bingoTable;
	int _bingolineCount = 0;
	

};