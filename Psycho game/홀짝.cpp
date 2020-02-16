#include <iostream>
#include < Windows.H>
using namespace std;



///// 여기서 홀 수 값이 나왔는데도 짝수로 만 인정이 되는데 그건 왜일까??
void main()
{
	srand(GetTickCount());

	int Sel = 0;
	int A_Dice = 0;
	int B_Dice = 0;
	int Result = 0;




	while (true)
	{
		cout << "주사위를 굴립니다" << endl;
		cout << "1. 홀 " << endl;
		cout << "2. 짝 " << endl ;
		cout << "3. 종료" << endl << endl;
		

		//주사위 랜덤 값
		int Max = 6;
		int Min = 1;

		int Numb1 = rand() % (Max - Min + 1) + Min;
		int Numb2 = rand() % (Max - Min + 1) + Min;


		A_Dice = Numb1;
		B_Dice = Numb2;
		Result = A_Dice + B_Dice;

		cin >> Sel;

		if (Sel == 1 || Sel == 2 || Sel ==3)
		{
			if (Sel == 3)
			{
				cout << "종료" << endl;
				break;
			}

			if ((Sel == 2 && Result % 2 == 0) ||
				(Sel == 1 && Result % 2 != 0))
			{
				cout << "정답입니다" << endl;
			}
			else
			{
				cout << "오답입니다" << endl;
			}

			cout << "뽑힌 숫자는 : ";
			cout << A_Dice << ", " << B_Dice;
			cout << endl;

		}
		else
		{
			cout << "1,2,3중 선택";
		}
				
		//	일시정지
		system("pause");

		// 화면 청소
		system("cls");

	}
	
}

