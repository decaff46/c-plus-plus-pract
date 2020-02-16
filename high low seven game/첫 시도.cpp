#include < iostream >
using namespace std;
#include <Windows.h>

int main()
{
	srand(GetTickCount());

	// 카드는 2 - 10까지 숫자 j,q,k,a 는 배제  
	//0=ace; 1=dia; 2=clover; 3=heart
	
	int ctype [4][8] = {};
	int count = 0;
	int hl = 0;
	
	

	//카드 생성
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			ctype[i][j] = i, j+2;
			count++;
		}
		
		// 카드 최대 31장 뽑을 수 있음 
		while (count < 33)
		{
			//카드 랜덤픽 (1. 4 종류 중 하나 선택   2. 선택한 카드 중 숫자 선택)
			for (int k = 0; k < 4; k++)
			{
				int max = 4;
				int min = 1;
				int rpick = rand() % (max - min + 1) + min;

				switch (rpick)
				{
				case 0:
					int MAX = 10;
					int MIN = 2;
					int rpick = rand() % (MAX - MIN + 1) + MIN;
					cout << "카드를 집었습니다 High (1) 또는 Low (2)를 선택하세요." << endl;
					cin >> hl; 
					

					if (rpick < 7 && hl = 2)
					{
						cout << "you got it right" << endl;
					} 
					else
					{
						cout << "you got it WRONG" << endl;
					}
					
					//쓴 카드 버리기?

					break;

				case 1:
					int MAX = 10;
					int MIN = 2;
					int rpick = rand() % (MAX - MIN + 1) + MIN;
					cout << "카드를 집었습니다 High (1) 또는 Low (2)를 선택하세요." << endl;
					cin >> hl;


					if (rpick < 7 && hl = 2)
					{
						cout << "you got it right" << endl;
					}
					else
					{
						cout << "you got it WRONG" << endl;
					}
					break;

				case 2:
					int MAX = 10;
					int MIN = 2;
					int rpick = rand() % (MAX - MIN + 1) + MIN;
					cout << "카드를 집었습니다 High (1) 또는 Low (2)를 선택하세요." << endl;
					cin >> hl;


					if (rpick < 7 && hl = 2)
					{
						cout << "you got it right" << endl;
					}
					else
					{
						cout << "you got it WRONG" << endl;
					}
					break;

				default:
					int MAX = 10;
					int MIN = 2;
					int rpick = rand() % (MAX - MIN + 1) + MIN;
					cout << "카드를 집었습니다 High (1) 또는 Low (2)를 선택하세요." << endl;
					cin >> hl;


					if (rpick < 7 && hl = 2)
					{
						cout << "you got it right" << endl;
					}
					else
					{
						cout << "you got it WRONG" << endl;
					}
					break;
				}
				
	}
	return 0;

}



