#include <iostream>
using namespace std;

int main()
{
	int count = 0;

	int my_hp = 100;
	int you_hp = 100;
	int you_atk = 4;
	int my_atk = 5;

	while (my_hp > 0 && you_hp > 0)
	{

			if (count % 2 != 0)
			{
				cout << "���� �����մϴ�" << endl;
				you_hp = you_hp - my_atk;
				if (you_hp <= 0)
				{
					cout << "��밡 �׾����ϴ� " << endl;
				}
				else
				{
					cout << "������ HP�� " << you_hp << "�Դϴ�" << endl << endl;
				}
			}
			else
			{
				cout << "���� �����մϴ�" << endl;
				my_hp = my_hp - you_atk;
				
				if (my_hp <= 0)
				{
					cout << "���� �׾����ϴ� " << endl;
				}
				else
				{
					cout << "���� HP�� " << my_hp << "�Դϴ�" << endl << endl;
				}
			}

			count++;
	}

	return 0;
}
