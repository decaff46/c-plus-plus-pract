#include <iostream>
using namespace std; 

int main() 
{
	
	// 내 기본 정보
	int mAtk = 0;
	int mHP = 100; 
	int mDef = 100; 
	int max_mAtk = 120;
	int min_mAtk = 110;


	// 적 기본 정보
	int yAtk = 110;
	int yHP = 100;
	int yDef = 80;

	/*   여기는 hp가 낮아 질 수록 치명타를 날리고 싶었는데 모르겠네요 ~ ㅎㅎ
	int max_mAtk = 130;
	*/

	

	// 턴재로 한번 씩 공격한다

	while (mHP > 0 || yHP > 0)
	{
		cout << "1,2중 선택하세요 (1: 크릭 (최대 3번 사용가능) ; 2: 일반)  ";
		cin >> mAtk;
				
			switch (mAtk)
			{
			case 1:
				int mAtk = max_mAtk;
				cout << "1을 선택하셨습니다 공격하겠습니다" << endl;
				int crit = 3; 
				if (crit == 3; crit == 0; crit--) //crit은 최대 3번만 사용하고 싶습니다
				break;
			case 2:
				int mAtk = min_mAtk;
				cout << "2를 선택하셨습니다. 공격하겠습니다" << endl;
				break;
			default:
				cout << "1과 2 중 둘중 하나만 선택하라고!" << endl;
				break;
			}
		}

		int mHP = mHP + (mDef - yAtk);
		int yHP = yHP + (yDef - mAtk);

	}
	
	return 0;
}