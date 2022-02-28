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
	
	cout << "빙고판을 제작합시다." << endl;
	cout << "5X5 칸의 빙고판입니다." << endl;
	cout << "--------------------------" << endl;
	cout << "00 00 00 00 00" << endl;
	cout << "00 00 00 00 00" << endl;
	cout << "00 00 00 00 00" << endl;
	cout << "00 00 00 00 00" << endl;
	cout << "00 00 00 00 00" << endl;
	cout << "--------------------------" << endl;
	cout << "한 줄에 5개씩 숫자를 입력해 주세요" << endl;
	cout << "숫자는 1~50까지 입력 가능합니다" << endl;

		
	_player->InputPlayerData();

	
}