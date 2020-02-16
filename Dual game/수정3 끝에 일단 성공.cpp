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
				cout << "적을 공격합니다" << endl;
				you_hp = you_hp - my_atk;
				if (you_hp <= 0)
				{
					cout << "상대가 죽었습니다 " << endl;
				}
				else
				{
					cout << "상대방의 HP는 " << you_hp << "입니다" << endl << endl;
				}
			}
			else
			{
				cout << "적이 공격합니다" << endl;
				my_hp = my_hp - you_atk;
				
				if (my_hp <= 0)
				{
					cout << "내가 죽었습니다 " << endl;
				}
				else
				{
					cout << "나의 HP는 " << my_hp << "입니다" << endl << endl;
				}
			}

			count++;
	}

	return 0;
}
