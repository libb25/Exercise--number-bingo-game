#include "Player.h"
#include<iostream>
using namespace std;
#include <set>


void Player::InputPlayerData()
{
		std::set<int> temp;
		cout << "> ";
		for (int i = 0; i < 25; ++i)
		{
			while (true)
			{
				int input;
				cin >> input;
				// 입력값이 0이나 50이하가 아니면 정상입력
				if (input != 0 && input<=50)
				{
					// 중복이 아니면 그대로 입력
					if (temp.find(input) == temp.end())
					{
						temp.insert(input);
						_bingoTable.insert(pair<int, int>(i, input));
						break;
					}
					// 중복이면 다시입력
					else
					{
						cout <<input<< "은 중복입니다. 다시 입력하세요" << endl;
						continue;
					}
				}
				else
				{
					cout << "0이나 50보다 큰 수는 입력할 수 없습니다. 다시 입력하세요" << endl;
					continue;
				}
			}
		}
}