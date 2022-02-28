#include "Field.h"
#include "Computer.h"
#include <iostream>
#include "Player.h"
#include <set>
using namespace std;

Field::Field() : _computer(make_shared<Computer>())
{

}

Field::~Field()
{

}

void Field::Update(std::shared_ptr<Player> player)
{
	if(_computer!=nullptr)
		_computer->InputComputerData();
	while (true)
	{
		if (player->BingolineCountCheck() < 3 && _computer->BingolineCountCheck() < 3)
			StartBattle(player);
		else 
			break;
	}

}

void Field::StartBattle(std::shared_ptr<Player> player)
{	
	player->PrintBingoTable();
	std::set<int> p;
	std::set<int> c;
	std::set<int> playerCall;
	while (true)
	{
		//플레이어-> 컴퓨터 공격
		cout << "공격! 빙고판에 있는 숫자 중에서 하나를 입력해 주세요" << endl;
		int attack, count=0;
		cin >> attack;
		for (int i = 0; i < 25; i++)
		{
			if (attack !=0 && player->GetBingoTableValue(i) == attack)
			{
				_computer->ClearBingoNumber(attack);
				player->ClearBingoNumber(attack);
				count++;
				playerCall.insert(attack);
				break;
			}
		}
		if (count == 0)
			continue;

		player->PrintBingoTable();
		BingoLineNumber(player,p);
		BingoLineNumber(_computer,c);
			
		if (player->BingolineCountCheck() >= 3)
		{
			cout << "축하합니다" << endl;
			cout << "이겼습니다~~" << endl;
			cout << "컴퓨터 빙고판" << endl;
			_computer->PrintBingoTable();
			break;
		}
		if (_computer->BingolineCountCheck() >= 3)
		{
			cout << "졌습니다 ㅜㅜ" << endl;
			cout << "다시 도전해보세요" << endl;
			cout << "컴퓨터 빙고판" << endl;
			_computer->PrintBingoTable();
			break;
		}

		//컴퓨터 -> 플레이어 공격 
		cout << "컴퓨터가 숫자를 골랐습니다" << endl;
			
		while (true)
		{
			int key = rand() % 25;
			attack = _computer->GetBingoTableValue(key);
			if (attack != 0 && playerCall.find(attack)==playerCall.end())
			{
				cout << ">>>>> " << attack << endl;
				_computer->ClearBingoNumber(attack);
				player->ClearBingoNumber(attack);
				break;
			}
			else
				continue;
		}
		player->PrintBingoTable();
		BingoLineNumber(player,p);
		BingoLineNumber(_computer,c);

		if (player->BingolineCountCheck() >= 3)
		{
			cout << "축하합니다" << endl;
			cout << "이겼습니다~~" << endl;
			cout << "컴퓨터 빙고판" << endl;
			_computer->PrintBingoTable();
			break;
		}
		if (_computer->BingolineCountCheck() >= 3)
		{
			cout << "졌습니다 ㅜㅜ" << endl;
			cout << "다시 도전해보세요" << endl;
			cout << "컴퓨터 빙고판" << endl;
			_computer->PrintBingoTable();
			break;
		}

		
	}
}

void Field::BingoLineNumber(std::shared_ptr<Creature> creature, std::set<int>& a)
{
	int count=0;
	
	// 가로줄 + 100
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (creature->GetBingoTableValue((5*i)+j) == 0)
				count++;
		}
		
		if (count == 5)
		{
			if (a.find(i+100) == a.end())
			{
				a.insert(i+100);
				creature->BingolineCountPlus();
			}
		}
		count = 0;
	}
	
	// 세로줄 +200
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (creature->GetBingoTableValue(i + (5*j)) == 0)
				count++;
		}

		if (count == 5)
		{
			if (a.find(i + 200) == a.end())
			{
				a.insert(i + 200);
				creature->BingolineCountPlus();
			}
		}
		count = 0;
	}
	
	//대각선 1
	for (int i = 0; i < 5; i++)
	{
		if (creature->GetBingoTableValue(0 + (6 * i)) == 0)
			count++;
	}
	
	if (count == 5)
	{
		if (a.find(1) == a.end())
		{
			a.insert(1);
			creature->BingolineCountPlus();
		}
	}
	count = 0;
	//대각선 2 
	for (int i = 0; i < 5; i++)
	{
		if (creature->GetBingoTableValue(4 + (4 * i)) == 0)
			count++;
	}
	if (count == 5)
	{
		if (a.find(2) == a.end())
		{
			a.insert(2);
			creature->BingolineCountPlus();
		}
	}

}