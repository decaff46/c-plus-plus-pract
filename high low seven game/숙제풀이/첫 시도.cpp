#include < iostream >
using namespace std;
#include <Windows.h>

int main()
{
	srand(GetTickCount());

	// ī��� 2 - 10���� ���� j,q,k,a �� ����  
	//0=ace; 1=dia; 2=clover; 3=heart
	
	int ctype [4][8] = {};
	int count = 0;
	int hl = 0;
	
	

	//ī�� ����
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			ctype[i][j] = i, j+2;
			count++;
		}
		
		// ī�� �ִ� 31�� ���� �� ���� 
		while (count < 33)
		{
			//ī�� ������ (1. 4 ���� �� �ϳ� ����   2. ������ ī�� �� ���� ����)
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
					cout << "ī�带 �������ϴ� High (1) �Ǵ� Low (2)�� �����ϼ���." << endl;
					cin >> hl; 
					

					if (rpick < 7 && hl = 2)
					{
						cout << "you got it right" << endl;
					} 
					else
					{
						cout << "you got it WRONG" << endl;
					}
					
					//�� ī�� ������?

					break;

				case 1:
					int MAX = 10;
					int MIN = 2;
					int rpick = rand() % (MAX - MIN + 1) + MIN;
					cout << "ī�带 �������ϴ� High (1) �Ǵ� Low (2)�� �����ϼ���." << endl;
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
					cout << "ī�带 �������ϴ� High (1) �Ǵ� Low (2)�� �����ϼ���." << endl;
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
					cout << "ī�带 �������ϴ� High (1) �Ǵ� Low (2)�� �����ϼ���." << endl;
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



