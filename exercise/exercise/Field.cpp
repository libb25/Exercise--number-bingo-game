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
		//�÷��̾�-> ��ǻ�� ����
		cout << "����! �����ǿ� �ִ� ���� �߿��� �ϳ��� �Է��� �ּ���" << endl;
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
			cout << "�����մϴ�" << endl;
			cout << "�̰���ϴ�~~" << endl;
			cout << "��ǻ�� ������" << endl;
			_computer->PrintBingoTable();
			break;
		}
		if (_computer->BingolineCountCheck() >= 3)
		{
			cout << "�����ϴ� �̤�" << endl;
			cout << "�ٽ� �����غ�����" << endl;
			cout << "��ǻ�� ������" << endl;
			_computer->PrintBingoTable();
			break;
		}

		//��ǻ�� -> �÷��̾� ���� 
		cout << "��ǻ�Ͱ� ���ڸ� ������ϴ�" << endl;
			
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
			cout << "�����մϴ�" << endl;
			cout << "�̰���ϴ�~~" << endl;
			cout << "��ǻ�� ������" << endl;
			_computer->PrintBingoTable();
			break;
		}
		if (_computer->BingolineCountCheck() >= 3)
		{
			cout << "�����ϴ� �̤�" << endl;
			cout << "�ٽ� �����غ�����" << endl;
			cout << "��ǻ�� ������" << endl;
			_computer->PrintBingoTable();
			break;
		}

		
	}
}

void Field::BingoLineNumber(std::shared_ptr<Creature> creature, std::set<int>& a)
{
	int count=0;
	
	// ������ + 100
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
	
	// ������ +200
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
	
	//�밢�� 1
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
	//�밢�� 2 
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