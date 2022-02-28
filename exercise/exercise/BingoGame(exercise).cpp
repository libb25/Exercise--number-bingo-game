#include <iostream>
using namespace std;
#include "Game.h"
#include "Player.h"
#include "Field.h"


int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	
	Game game;
	game.Update();
		
	return 0;
}

