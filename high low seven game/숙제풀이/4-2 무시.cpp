#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	srand(GetTickCount());
	
	int card [52] = {};
	int pick = 0;
	int show[4] = {};


	//카드 생성
	for (int i = 0; i < 52; i++)
	{
		card [i] = i;

		//카드 분류 및 숫자 대입
		int mark = card [i] / 13;
		int numb = card [i] % 13;
		
		
		//셔플링 범위 
		int Nmax = 13;
		int Nmin = 2;

		int Mmax = 3;
		int Mmin = 0;


		//랜덤 마크/카드 선택 
		numb = rand() % (Nmax - Nmin + 1) + Nmin;
		mark = rand() % (Mmax - Mmin + 1) + Mmin;

		switch (mark)
		{
		case 0:
			cout << "Ace" << endl;
			break;
		case 1:
			cout << "Heart" << endl;
			break;
		case 2:
			cout << "Diamond" << endl;
			break;
		case 3:
			cout << "Clover" << endl;
			break;
		} //여기서 마크가 맨 처음에 보이고 그 다음에 뽑은 카드에서 마크 + 숫자를 보이는 데서는 왜 안될까요 
		

		//최근 5개 카드 배열
		int count = 0;
		show[count] = numb;// 도대체 이거는 어떻게 해야 할까요? 


		//랜덤 카드에 따른 high low  선택
		cout << "A card has been selected guess if it's high or low" << endl;
		cout << "1: higher than 7 // 2: lower than 7" << endl;
		cin >> pick;
		

		//숫자는 1 또는 2만 선택
		if (pick == 2 || pick == 1)
		{
			//High Low 뽑기 결과
			if (numb >= 7 && pick == 1)
			{
				cout << "You got it right" << endl;
				cout << "The card was picked was " << mark << " " << numb << endl;
				cout << "The last five cards have been pulled are : " << show << endl << endl;
				count++;
			}
			else if (numb <= 7 && pick == 2)
			{
				cout << "You got it right" << endl;
				cout << "The card was picked was " << mark << " " << numb << endl;
				cout << "The last five cards have been pulled are : " << show << endl << endl;
				count++;
			}
			else
			{
				cout << "Oooops you guess wrong" << endl;
				cout << "The card was picked was " << mark << " " << numb << endl;
				cout << "The last five cards have been pulled are : " << show << endl << endl;
				count++;
			}
		}
		else
		{
			cout << "please pick either 1 or 2. Thank you" << endl << endl;
		}

		
	}

	return 0;
}