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

	int count = 0; // counting cards;
	int pick = 0;  // H or L choice

	//shuffle the cards
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
				int A_trash[9] = {};
				
				//cout << "ACE is selected" << endl;

				for (int j = 0; j < 9; j++)
				{
					int c_max = 10;
					int c_min = 2;

					int card = rand() % (c_max - c_min + 1) + c_min;

					ACE[j] = card;
					A_trash[j] = card;
					
					cout << "is the card high(1) or low(2)?    : " << endl;
					cin >> pick;

					//  preventing duplication 
					while (ACE[j] =! A_trash[j - 1])
					{
						if (card > 7 && pick == 1)
						{
							cout << "Selected card is ACE  " << card << endl;
							cout << "You guessed right GOOD JOB!" << endl;
							cout << "# of remain cards are  " << 31 - count << endl << endl;
							break;
						}
						else if (card < 7 && pick == 2)
						{
							cout << "Selected card is ACE  " << card << endl;
							cout << "You guessed right GOOD JOB!" << endl;
							cout << "# of remain cards are  " << 31 - count << endl << endl;
							break;
						}
						else
						{
							cout << "Selected card is ACE  " << card << endl;
							cout << "You guessed WRONG !" << endl;
							cout << "# of remain cards are  " << 31 - count << endl << endl;
							break;
						}
					}
					count++;
					pick = 0;
					break;
				}
			}
			else if (type == 2)
			{
				int H_trash[9] = {};
				
				//cout << "HEART is selected" << endl;

				for (int j = 0; j < 9; j++)
				{
					int c_max = 10;
					int c_min = 2;

					int card = rand() % (c_max - c_min + 1) + c_min;

					HEART[j] = card;
					H_trash[j] = card;

					cout << "is the card high(1) or low(2)?    : " << endl;
					cin >> pick;

					//  preventing duplication 
					while (HEART[j] =! H_trash[j - 1])
					{
						if (card > 7 && pick == 1)
						{
							cout << "Selected card is HEART   " << card << endl;
							cout << "You guessed right GOOD JOB!" << endl;
							cout << "# of remain cards are  " << 31 - count << endl << endl;
							break;
						}
						else if (card < 7 && pick == 2)
						{
							cout << "Selected card is HEART  " << card << endl;
							cout << "You guessed right GOOD JOB!" << endl;
							cout << "# of remain cards are  " << 31 - count << endl << endl;
							break;
						}
						else
						{
							cout << "Selected card is HEART  " << card << endl;
							cout << "You guessed WRONG !" << endl;
							cout << "# of remain cards are  " << 31 - count << endl << endl;
							break;
						}
					}
					count++;
					pick = 0; 
					break;
				}
			}
			else if (type == 3)
			{
				count++;
				int C_trash[9] = {};

				//cout << "CLOVER is selected" << endl;

				for (int j = 0; j < 9; j++)
				{
					int c_max = 10;
					int c_min = 2;

					int card = rand() % (c_max - c_min + 1) + c_min;

					CLOVER[j] = card;
					C_trash[j] = card;

					cout << "is the card high(1) or low(2)?    : " << endl;
					cin >> pick;

					//  preventing duplication 
					while (CLOVER[j] =! C_trash[j - 1])
					{
						if (card > 7 && pick == 1)
						{
							cout << "Selected card is CLOVER  " << card << endl;
							cout << "You guessed right GOOD JOB!" << endl;
							cout << "# of remain cards are  " << 31 - count << endl << endl;
							break;
						}
						else if (card < 7 && pick == 2)
						{
							cout << "Selected card is CLOVER  " << card << endl;
							cout << "You guessed right GOOD JOB!" << endl;
							cout << "# of remain cards are  " << 31 - count << endl << endl;
							break;
						}
						else
						{
							cout << "Selected card is CLOVER  " << card << endl;
							cout << "You guessed WRONG !" << endl;
							cout << "# of remain cards are  " << 31 - count << endl << endl;
							break;
						}
					}
					count++;
					pick = 0;
					break;
				}
			}
			else
			{
				count++;
				int D_trash[9] = {};

				//cout << "DIAMOND is selected" << endl;

				for (int j = 0; j < 9; j++)
				{
					int c_max = 10;
					int c_min = 2;

					int card = rand() % (c_max - c_min + 1) + c_min;

					DIAMOND[j] = card;
					D_trash[j] = card;
					
					cout << "is the card high(1) or low(2)?    : " << endl;
					cin >> pick;

					//  preventing duplication 
					while (DIAMOND[j] = !D_trash[j - 1])
					{
						if (card > 7 && pick == 1)
						{
							cout << "Selected card is DIAMOND   " << card << endl;
							cout << "You guessed right GOOD JOB!" << endl;
							cout << "# of remain cards are  " << 31 - count << endl << endl;
							break;
						}
						else if (card < 7 && pick == 2)
						{
							cout << "Selected card is DIAMOND  " << card << endl;
							cout << "You guessed right GOOD JOB!" << endl;
							cout << "# of remain cards are  " << 31 - count << endl << endl;
							break;
						}
						else
						{
							cout << "Selected card is DIAMOND  " << card << endl;
							cout << "You guessed WRONG !" << endl;
							cout << "# of remain cards are  " << 31 - count << endl << endl;
							break;
						}
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
