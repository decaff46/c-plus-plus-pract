#include <iostream>
using namespace std;

int main()
{

	// 내 기본 정보
	int mAtk = 0;
	int mHP = 100;
	int mDef = 100;
	//int max_mAtk = 120; 정의를 너무많이 했다고 나와서요 지워 봤습니다 
	//int min_mAtk = 110;  동일 한 이유 
	
	// 적 기본 정보
	int yAtk = 110;
	int yHP = 100;
	int yDef = 80;
	
	
	do
	{
		int mHP = mHP - (mDef - yAtk);
		cout << "상대가 공격합니다" << endl;
		cout << "당신의 체력은 " << int mHP << "공격으로 인해 상대를" << mAtk << "피해를 입혔습니다" << endl;
		cout << "상대의 체력은 " << int yHP << endl;
		cout << "공격 포인트 110, 120 둘중 하나 선택하세요 (1: 크릭_최대 3번 사용 ; 2: 일반) ";
		cin >> mAtk;
		//switch (mAtk)
		switch (mAtk)
		{
		case 120:
			//int mAtk = max_mAtk;
			int yHP = mHP + (mDef - yAtk);
			int crit = 0;
			for (crit == 0; crit <= 3; crit++)
			{
				if (crit > 3)
				{
					cout << " 크릭을 최대한 사용했습니다" << endl;
				}
				else
				{
					cout << "크릭을 사용하였습니다. 최대 대미치 120를 적용합니다. 남은 크릭 수는 " << 3 - crit << endl;
				}
			}
			break;

		case 110:
			//int mAtk = min_mAtk;
			cout << "일반 공격을 사용하였습니다. 최대 대미지 110. 남은 크릭 수는 " << 3 - crit << endl;
			break;

		default:
			cout << " 1 // 2 둘중 하나만 사용 가능합니다" << endl;
			break;
		}
	}
	while (mHP > 0 || yHP > 0)
	{
		if (mATk == 120 || mAtk == 110)
		{
			
		}
	}

	

	

	return 0;
}