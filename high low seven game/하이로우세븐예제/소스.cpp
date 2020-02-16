#include <iostream>
#include <Windows.h>
using namespace std;

void main()
{
	srand(GetTickCount());

	//	하이로우세븐

	//	카드준비
	int		Card[52] = {};

	for (int i = 0; i < 52; i++)
	{
		Card[i] = i;
	}

	//	이번 게임의 카드
	int		CardIndex = 0;
	
	//	카드섞는다.
	for (int i = 0; i < 200; i++)
	{
		int Src = rand() % 52;
		int Dev = rand() % 52;

		int Temp = Card[Src];
		Card[Src] = Card[Dev];
		Card[Dev] = Temp;
	}

	
	//	게임 시작( 반복 )
	while (true)
	{
		//	현재 카드 상태
		cout << "지난 카드 : ";
		for (int i = 0; i < 5; i++)
		{
			int Index = CardIndex - i - 1;

			if (Index < 0)
			{
				break;
			}

			switch (Card[Index] / 13)
			{
			case 0:	cout << "♠";  break;
			case 1:	cout << "♡";  break;
			case 2:	cout << "◇";  break;
			case 3:	cout << "♣";  break;
			}
			switch (Card[Index] % 13)
			{
			case 0:		cout << "A";  break;
			case 10:	cout << "J";  break;
			case 11:	cout << "Q";  break;
			case 12:	cout << "K";  break;
			default:	cout << Card[Index] % 13 + 1;
			}

			cout << "  ";
		}
		cout << endl << endl;

		int Input = 0;

		//	하이로우세븐입력 받는다.
		cout << "1. 하이" << endl;
		cout << "2. 로우" << endl;
		cout << "3. 세븐" << endl;
		cout << "4. 종료" << endl;
		cout << "입력 : ";
		cin >> Input;

		if (Input == 4)
		{
			cout << "종료" << endl;
			break;
		}

		//	카드오픈
		cout << endl;

		switch (Card[CardIndex] / 13)
		{
		case 0:	cout << "♠";  break;
		case 1:	cout << "♡";  break;
		case 2:	cout << "◇";  break;
		case 3:	cout << "♣";  break;
		}

		int Num = Card[CardIndex] % 13;

		switch (Num)
		{
		case 0:		cout << "A";  break;
		case 10:	cout << "J";  break;
		case 11:	cout << "Q";  break;
		case 12:	cout << "K";  break;
		default:	cout << Num+1;
		}
		cout << endl << endl;

		//	결과 처리
		if ((Input == 1 && Num > 6) ||
			(Input == 2 && Num < 6) ||
			(Input == 3 && Num == 6))
		{
			cout << "정답" << endl;
		}
		else
		{
			cout << "오답" << endl;
		}

		CardIndex++;

		//	콘솔 일시정지 명령
		system("pause");
		//	콘솔 화면 청소
		system("cls");
	}
}

/*
	C++			
	자바	100 구조 설계

*/