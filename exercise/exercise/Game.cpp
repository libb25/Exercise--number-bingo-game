#include "Game.h"
#include "Player.h"
#include<iostream>
#include "Field.h"
using namespace std;

Game::Game() : _player(make_shared<Player>()), _field(make_shared<Field>())
{

}

Game::~Game()
{

}



void Game::Update()
{
	if (_player != nullptr && _field != nullptr)
	{
		CreatePlayer();
		_field->Update(_player);
	}

}

void Game::CreatePlayer()
{
	
	cout << "�������� �����սô�." << endl;
	cout << "5X5 ĭ�� �������Դϴ�." << endl;
	cout << "--------------------------" << endl;
	cout << "00 00 00 00 00" << endl;
	cout << "00 00 00 00 00" << endl;
	cout << "00 00 00 00 00" << endl;
	cout << "00 00 00 00 00" << endl;
	cout << "00 00 00 00 00" << endl;
	cout << "--------------------------" << endl;
	cout << "�� �ٿ� 5���� ���ڸ� �Է��� �ּ���" << endl;
	cout << "���ڴ� 1~50���� �Է� �����մϴ�" << endl;

		
	_player->InputPlayerData();

	
}