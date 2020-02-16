#include <iostream>
using namespace std;

int main()
{
	int count = 0;

	int my_hp = 100;
	int you_hp = 100;
	int you_atk = 4;
	int my_atk = 0;

	while (my_hp > 0 && you_hp > 0)
	{
			if (count % 2 != 0)
			{
				cout << "적을 공격합니다" << endl;
				cout << "1 또는 2를 선택하세요 1: 크릭 (최대 3번) 2: 노말   :   ";  // 저 박스위에 쓰는 법은 없나요?
				cin >> my_atk;
				
				int c = 0;

				switch (my_atk)
				{
				case 1:
					
					c++;  // 여기서 크릭을 최대 3번만 하는게 안되네요 ㅠㅠ  에휴 .. 오늘 종일 했는데  연수 화이팅입니다
					if (c <= 3)
					{
						cout << "크릭을 선택했습니다 적에게 데이지'10'을 가합니다." << endl;
						cout << 3 - c << "의 크릭 수가 남았습니다" << endl;
						you_hp = you_hp - 10;
						cout << "상대의 hp는 " << you_hp << "남았습니다" << endl << endl;
					}
					else  
					{
						cout << "크릭을 최대 사용했습니다 일반 공격을 합니다" << endl << endl;
						you_hp = you_hp - 5;
					}
					break;
				
				case 2:
				
					cout << "일반 공격을 가합니다 " << endl;
					you_hp = you_hp - 5;
					cout << "상대의 hp는 " << you_hp << "남았습니다" << endl << endl;
					break;
				
				default:
					cout << "1 또는 2만 가능하다고" << endl;
					break;
				}

				if (you_hp <= 0)
				{
					cout << "상대가 죽었습니다 " << endl << endl;
					break;
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
					break;
				}
				else
				{
					cout << "나의 HP는 " << my_hp << "입니다" << endl << endl;
				}
			}
		
	}

	return 0;
}
