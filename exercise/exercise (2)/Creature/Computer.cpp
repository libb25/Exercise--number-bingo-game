#include "Computer.h"
#include <stdlib.h>
#include <set>


void Computer::InputComputerData()
{
	std::set<int> temp;
	for (int i = 0; i < 25; ++i)
	{
		while (true)
		{
			int input = (rand() % 50) + 1;
			// 중복이 아니면 그대로 입력
			if (temp.find(input) == temp.end())
			{
				temp.insert(input);
				_bingoTable.insert(std::pair<int, int>(i, input));
				break;
			}
			// 중복이면 다시입력
			else
			{
				continue;
			}
			
		}
	}
}