#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	srand(GetTickCount());

	// card are from 2 - 10 "max card # is 31;  
	// types: ACE, HEART, CLOVER, DIAMOND;

	int ACE[9] = {};
	int HEART[9] = {};
	int CLOVER[9] = {};
	int DIAMOND[9] = {};

	// creating cards

	for (int i = 0; i < 9; i++)
	{
		ACE[i] = i + 2;
		HEART[i] = i + 2;
		CLOVER[i] = i + 2;
		DIAMOND[i] = i + 2;

		/*
		cout << ACE[i] << endl;
		cout << HEART[i] << endl;
		cout << CLOVER[i] << endl;
		cout << DIAMOND[i] << endl;
		*/
	}
	
	/*문제점:
		카드 값이 -가 됐는데도 돌아가고 있다; --> 이건 이유를 모르겠다 아마도 31-?가 문제지 않을까 싶은데.. 그럼 -1까지만 나와야 하는데 실제 -2까지 나옴.  
		중복 처리를 하지 못했다; --> 카드 종류마다 쓰레기 배열을 생성해서 저장하고 바로 전 값이랑 비교 할려고 했는데 소스3에서 실패.
		중복 처리가 안되다 보니 이상하게도 하나의 종류의 카드가 많이 나오는 경향도 있는 것 같다. 
		지금까지 나온거 다섯개를 보여 주지 못하고 있다;	 --> 이건 array[4]만들어서 for로 돌려서 값 5개만 저장되게 하면 될 것 같은데 어디다가 놔야 할 지 모르겠다.
	*/

	int count = 0; // counting cards;
	int pick = 0;

	//shuffle the cards1
	while (count < 33)
	{
		//rand card type pick  1 - ACE; 2 - HEART; 3 - CLOVER; 4 - DIAMOND;
		for (int i = 0; i < 4; i++)
		{
			int t_max = 4;
			int t_min = 1;

			int type = rand() % (t_max - t_min + 1) + t_min;

			if (type == 1)
			{
				cout << "ACE is selected" << endl;
				for (int j = 0; j < 10; j++)
				{
					int c_max = 10;
					int c_min = 2;

					int card = rand() % (c_max - c_min + 1) + c_min;
					
				
					cout << "is the card high(1) or low(2)? " << endl;
					cin >> pick; 

					if (card > 7 && pick == 1)
					{
						// "" 안에 "" 사용이 안되나요?
						cout << "Selected card is   " << card << endl;
						cout << "You guessed right GOOD JOB!" << endl;
						cout << "# of remain cards are  " << 31 - count << endl << endl;
					}
					else if (card < 7 && pick == 2)
					{
						cout << "Selected card is   " << card << endl;
						cout << "You guessed right GOOD JOB!" << endl;
						cout << "# of remain cards are  " << 31 - count << endl << endl;
					}
					else 
					{
						cout << "Selected card is   " << card << endl;
						cout << "You guessed WRONG !" << endl;
						cout << "# of remain cards are  " << 31 - count << endl << endl;
					}

					count++;
					pick = 0;
					break;
				}
			}
			else if (type == 2)
			{
				cout << "HEART is selected" << endl;
				for (int j = 0; j < 10; j++)
				{
					int c_max = 10;
					int c_min = 2;

					int card = rand() % (c_max - c_min + 1) + c_min;



					cout << "is the card high(1) or low(2)? " << endl;
					cin >> pick;

					if (card > 7 && pick == 1)
					{
						// "" 안에 "" 사용이 안되나요?
						cout << "Selected card is   " << card << endl;
						cout << "You guessed right GOOD JOB!" << endl;
						cout << "# of remain cards are  " << 31 - count << endl << endl;
					}
					else if (card < 7 && pick == 2)
					{
						cout << "Selected card is   " << card << endl;
						cout << "You guessed right GOOD JOB!" << endl;
						cout << "# of remain cards are  " << 31 - count << endl << endl;
					}
					else
					{
						cout << "Selected card is   " << card << endl;
						cout << "You guessed WRONG !" << endl;
						cout << "# of remain cards are  " << 31 - count << endl << endl;
					}

					count++;
					pick = 0;
					break;
				}
			}
			else if (type == 3)
			{
				cout << "CLOVER is selected" << endl;
				for (int j = 0; j < 10; j++)
				{
					int c_max = 10;
					int c_min = 2;

					int card = rand() % (c_max - c_min + 1) + c_min;



					cout << "is the card high(1) or low(2)? " << endl;
					cin >> pick;

					if (card > 7 && pick == 1)
					{
						// "" 안에 "" 사용이 안되나요?
						cout << "Selected card is   " << card << endl;
						cout << "You guessed right GOOD JOB!" << endl;
						cout << "# of remain cards are  " << 31 - count << endl << endl;
					}
					else if (card < 7 && pick == 2)
					{
						cout << "Selected card is   " << card << endl;
						cout << "You guessed right GOOD JOB!" << endl;
						cout << "# of remain cards are  " << 31 - count << endl << endl;
					}
					else
					{
						cout << "Selected card is   " << card << endl;
						cout << "You guessed WRONG !" << endl;
						cout << "# of remain cards are  " << 31 - count << endl << endl;
					}

					count++;
					pick = 0;
					break;
				}
			}
			else
			{
				cout << "DIAMOND is selected" << endl;
				for (int j = 0; j < 10; j++)
				{
					int c_max = 10;
					int c_min = 2;

					int card = rand() % (c_max - c_min + 1) + c_min;



					cout << "is the card high(1) or low(2)? " << endl;
					cin >> pick;

					if (card > 7 && pick == 1)
					{
						// "" 안에 "" 사용이 안되나요?
						cout << "Selected card is   " << card << endl;
						cout << "You guessed right GOOD JOB!" << endl;
						cout << "# of remain cards are  " << 31 - count << endl << endl;
					}
					else if (card < 7 && pick == 2)
					{
						cout << "Selected card is   " << card << endl;
						cout << "You guessed right GOOD JOB!" << endl;
						cout << "# of remain cards are  " << 31 - count << endl << endl;
					}
					else
					{
						cout << "Selected card is   " << card << endl;
						cout << "You guessed WRONG !" << endl;
						cout << "# of remain cards are  " << 31 - count << endl << endl;
					}

					count++;
					pick = 0;
					break;
				}
			}
			
		}
	}
	

	return 0;
}
