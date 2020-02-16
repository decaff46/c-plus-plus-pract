#include <iostream>
#include <Windows.h>

using namespace std;


//if elseif에 들어 있는 반복 구문을 없애는 방법은 없을까? 

int main()
{
	srand(GetTickCount());

	int card[52] = {};
	int pick = 0;
	int count = 0;
	int show[5] = {};
	int copy[5] = {};

	//카드 생성
	for (int i = 0; i < 52; i++)
	{
		card[i] = i;

		//카드 분류 및 숫자 대입
		int mark = card[i] / 13;
		int numb = card[i] % 13;


		//셔플링 범위 
		int Nmax = 13;
		int Nmin = 1;

		int Mmax = 3;
		int Mmin = 0;

		numb = rand() % (Nmax - Nmin + 1) + Nmin;
		mark = rand() % (Mmax - Mmin + 1) + Mmin;

		
		//최근 5개 카드 배열 생성
		
		show[count] = numb; // 5번까지는 뽑아 내겠는데 그 다음부터는 어떻게 뒤에서부터 밀어 넣을까?
		
		// 5번 이후 밀어 넣기
		for (int i = 0; i < 5; i++)
		{
			copy[i] = show[i + 1];
			
		}
	

		
		//랜덤 카드에 따른 high low  선택
		switch (mark)
		{
		case 0:
			cout << "Ace has been selected guess if it's high or low" << endl;
			cout << "1 = higher than 7 // 2 = lower than 7  // 3 = it's 7  :";
			cin >> pick;
			break;
		case 1:
			cout << "Heart has been selected guess if it's high or low" << endl;
			cout << "1 = higher than 7 // 2 = lower than 7  // 3 = it's 7  :";
			cin >> pick;
			break;
		case 2:
			cout << "Diamond has been selected guess if it's high or low" << endl;
			cout << "1 = higher than 7 // 2 = lower than 7  // 3 = it's 7  :";
			cin >> pick;
			break;
		default:
			cout << "Clover has been selected guess if it's high or low" << endl;
			cout << "1 = higher than 7 // 2 = lower than 7  // 3 = it's 7  :";
			cin >> pick;
			break;
		}


		//숫자는 1 또는 2만 선택
		if (pick == 2 || pick == 1 || pick == 3)
		{
			//High Low 뽑기 결과
			if (numb > 7 && pick == 1)
			{
				cout << "You got it right" << endl;
				cout << "The card was picked was " << mark << " " << numb << endl; // mark에 int 값이 아닌 문자 값은??
				cout << "The last five cards have been pulled are : ";

				if (count < 5)
				{
					for (int j = 0; j < 5; j++)
					{
						cout << show[j] << " ";  //여기서도 숫자만 보이는 것이 아닌 카드 모양까지 보이는 법은 없을까??
						show[count] = numb;
					}

				}
				else
				{
					for (int j = 0; j < 5; j++)
					{
						cout << copy[j] << " ";  //여기서도 숫자만 보이는 것이 아닌 카드 모양까지 보이는 법은 없을까??
					}
				}
				
				count++;
				cout << endl << endl;
			}
			else if (numb < 7 && pick == 2)
			{
				cout << "You got it right" << endl;
				cout << "The card was picked was " << mark << " " << numb << endl;
				cout << "The last five cards have been pulled are : ";

				if (count < 5)
				{
					for (int j = 0; j < 5; j++)
					{
						cout << show[j] << " ";  //여기서도 숫자만 보이는 것이 아닌 카드 모양까지 보이는 법은 없을까??
					}

				}
				else
				{
					for (int j = 0; j < 5; j++)
					{
						cout << copy[j] << " ";  //여기서도 숫자만 보이는 것이 아닌 카드 모양까지 보이는 법은 없을까??
					}
				}

				count++;
				cout << endl << endl;
			}
			else if (numb == 7 && pick == 3)
			{
				cout << "You got it right" << endl;
				cout << "The card was picked was " << mark << " " << numb << endl;// mark에 int 값이 아닌 문자 값은??
				cout << "The last five cards have been pulled are : ";

				if (count < 5)
				{
					for (int j = 0; j < 5; j++)
					{
						cout << show[j] << " ";  //여기서도 숫자만 보이는 것이 아닌 카드 모양까지 보이는 법은 없을까??
					}

				}
				else
				{
					for (int j = 0; j < 5; j++)
					{
						cout << copy[j] << " ";  //여기서도 숫자만 보이는 것이 아닌 카드 모양까지 보이는 법은 없을까??
					}
				}

				count++;
				cout << endl << endl;
			}
			else
			{
				cout << "Oooops you guess wrong" << endl;
				cout << "The card was picked was " << mark << " " << numb << endl;// mark에 int 값이 아닌 문자 값은??
				cout << "The last five cards have been pulled are : ";

				if (count < 5)
				{
					for (int j = 0; j < 5; j++)
					{
						cout << show[j] << " ";  //여기서도 숫자만 보이는 것이 아닌 카드 모양까지 보이는 법은 없을까??
					}

				}
				else
				{
					for (int j = 0; j < 5; j++)
					{
						cout << copy[j] << " ";  //여기서도 숫자만 보이는 것이 아닌 카드 모양까지 보이는 법은 없을까??
					}
				}

				count++;
				cout << endl << endl;
			}
		}
		else
		{
			cout << "please pick either 1 or 2. Thank you" << endl << endl;
		}


	}

	return 0;
}