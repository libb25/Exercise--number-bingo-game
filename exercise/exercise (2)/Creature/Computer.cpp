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
			// �ߺ��� �ƴϸ� �״�� �Է�
			if (temp.find(input) == temp.end())
			{
				temp.insert(input);
				_bingoTable.insert(std::pair<int, int>(i, input));
				break;
			}
			// �ߺ��̸� �ٽ��Է�
			else
			{
				continue;
			}
			
		}
	}
}