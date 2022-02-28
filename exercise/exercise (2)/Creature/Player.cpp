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
				// �Է°��� 0�̳� 50���ϰ� �ƴϸ� �����Է�
				if (input != 0 && input<=50)
				{
					// �ߺ��� �ƴϸ� �״�� �Է�
					if (temp.find(input) == temp.end())
					{
						temp.insert(input);
						_bingoTable.insert(pair<int, int>(i, input));
						break;
					}
					// �ߺ��̸� �ٽ��Է�
					else
					{
						cout <<input<< "�� �ߺ��Դϴ�. �ٽ� �Է��ϼ���" << endl;
						continue;
					}
				}
				else
				{
					cout << "0�̳� 50���� ū ���� �Է��� �� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
					continue;
				}
			}
		}
}