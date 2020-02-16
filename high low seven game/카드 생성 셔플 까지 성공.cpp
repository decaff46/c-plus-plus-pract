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
	
	/*������:
		ī�� ���� -�� �ƴµ��� ���ư��� �ִ�; --> �̰� ������ �𸣰ڴ� �Ƹ��� 31-?�� ������ ������ ������.. �׷� -1������ ���;� �ϴµ� ���� -2���� ����.  
		�ߺ� ó���� ���� ���ߴ�; --> ī�� �������� ������ �迭�� �����ؼ� �����ϰ� �ٷ� �� ���̶� �� �ҷ��� �ߴµ� �ҽ�3���� ����.
		�ߺ� ó���� �ȵǴ� ���� �̻��ϰԵ� �ϳ��� ������ ī�尡 ���� ������ ���⵵ �ִ� �� ����. 
		���ݱ��� ���°� �ټ����� ���� ���� ���ϰ� �ִ�;	 --> �̰� array[4]���� for�� ������ �� 5���� ����ǰ� �ϸ� �� �� ������ ���ٰ� ���� �� �� �𸣰ڴ�.
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
						// "" �ȿ� "" ����� �ȵǳ���?
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
						// "" �ȿ� "" ����� �ȵǳ���?
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
						// "" �ȿ� "" ����� �ȵǳ���?
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
						// "" �ȿ� "" ����� �ȵǳ���?
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
