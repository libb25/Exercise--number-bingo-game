#pragma once
#include <memory>
#include <set>
class Computer;
class Player;
class Creature;

class Field
{
public:
	Field();
	~Field();

	void Update(std::shared_ptr<Player> player);
	void StartBattle(std::shared_ptr<Player> player);

	void BingoLineNumber(std::shared_ptr<Creature> creature, std::set<int>& a);

	
protected:
	std::shared_ptr<Computer> _computer;
};

