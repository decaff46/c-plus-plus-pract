#include <iostream>
using namespace std; 

int main()
{
	int count = 0;

	int my_hp = 100;
	int you_hp = 100;
	int you_atk = 4;
	
	
	/*int atk = 0;
	int crit = 0;
	while (crit <= 3)
	{
	
		cout << "공격할 포인트를 입력하세요 (1: 크릭- 데미지10, 2: 일반- 데미지 5)"; 
		cout << "크릭 데미지는 최대 3번만 사용 가능합니다: << endl;
		cin >> atk; 
		if (crit > 3)
		{
		cout << "크릭을 최대한 사용하였습니다! 일반 공격을 가하겠습니다. " << endl;
		atk == 2; 
		}
	
		switch (atk)
		{
		case 1: 
			crit++;

			cout << "상대방에게 강력한 공격을 가합니다 " << endl;
			you_hp = you_hp - 10; 
			cout << "상대방의 남은 체력은 " << you_hp << "입니다 " << endl;
			break; 
		case 2:
			cout << "상대방에게 일반 공격을 가합니다." << endl;
			you_hp = you_hp - 10;
			cout << "상대방의 남은 체력은 " << you_hp << "입니다 " << endl;
			break;
		default: 
			cout << "1,2 둘중 하나만 선택하세요!!" << endl;
			break;
		}
	}*/
	
	// 홀수일때 내가 공격 짝수일때 상대가 공격

	int my_atk = 5;
	
	while (my_hp > 0 || you_hp > 0)
	{
		for (count = 0; count <= 25; count++) // 여기서 25 말고 다른 방법이 없을까요? 
		{
			count = count % 2;
			if (count != 0)
			{
				cout << "적을 공격합니다" << endl;
				you_hp = you_hp - my_atk;
				cout << "상대방의 HP는 " << you_hp << "입니다" << endl << endl;
			}
			else {
				cout << "적이 공격합니다" << endl;
				my_hp = my_hp - you_atk;
				cout << "나의 HP 는 " << my_hp << "입니다" << endl << endl;
			}
		}
	}

			/* switch (count) 
			{
			case 0 :
				cout << "적을 공격합니다" << endl;
				you_hp = you_hp - my_atk;
				cout << "상대방의 HP는 " << you_hp << "입니다" << endl;
				break;
			case 1 :
				cout << "적이 공격합니다" << endl;
				my_hp = my_hp - you_atk;
				cout << "나의 HP 는 " << my_hp << "입니다" << endl;
				break;
			default :
				break;
			}*/ //이렇게 하니 상대만 공격하게 되네요 ... ㅠㅠ

		return 0;
}
