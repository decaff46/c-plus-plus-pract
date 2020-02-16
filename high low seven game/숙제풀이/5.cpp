#include <iostream>
#include <Windows.h>

using namespace std;




void ViewCard(int _Mark, int _Num)
{
	cout << "The card was picked was ";

	switch (_Mark)
	{
	case 0:		cout << "��";	 break;
	case 1:		cout << "��";	 break;
	case 2:		cout << "��";	 break;
	case 3:		cout << "��";	 break;
	}

	cout << _Num << endl;
}

void ViewPrevCard(int _Mark, int _Num)
{
	switch (_Mark)
	{
	case 0:		cout << "��";	 break;
	case 1:		cout << "��";	 break;
	case 2:		cout << "��";	 break;
	case 3:		cout << "��";	 break;
	}

	cout << _Num;
}

int main()
{
	srand(GetTickCount());

	int card[52] = {};
	int pick = 0;
	int count = 0;
	int show[5] = {};
	int showB[5] = {};
	int copy[5] = {};


	int ViewPrevCount = 0;

	//ī�� ����
	for (int i = 0; i < 52; i++)
	{
		card[i] = i;

		//ī�� �з� �� ���� ����
		int mark = card[i] / 13;
		int numb = card[i] % 13;


		//���ø� ���� 
		int Nmax = 13;
		int Nmin = 1;

		int Mmax = 3;
		int Mmin = 0;

		numb = rand() % (Nmax - Nmin + 1) + Nmin;
		mark = rand() % (Mmax - Mmin + 1) + Mmin;

		
		//�ֱ� 5�� ī�� �迭 ����
		
		if (ViewPrevCount  < 5)
		{
			showB[ViewPrevCount] = mark;
			show[ViewPrevCount] = numb; 
			ViewPrevCount++;
		}
		else
		{
			// ������ ����
			for (int i = 0; i < 4; i++)
			{
				show[i] = show[i + 1];
				showB[i] = showB[i + 1];
			}

			// �� ���ڸ��� �̹� ���� �ֱ�
			show[4] = numb;
			showB[4] = mark;
		}
		
		//���� ī�忡 ���� high low  ����
		switch (mark)
		{
		case 0: cout << "Ace has been selected guess if it's high or low" << endl; break;
		case 1: cout << "Heart has been selected guess if it's high or low" << endl; break;
		case 2: cout << "Diamond has been selected guess if it's high or low" << endl; break;
		default: cout << "Clover has been selected guess if it's high or low" << endl; break;
		}

		cout << "1 = higher than 7 // 2 = lower than 7  // 3 = it's 7  :";
		cin >> pick;


		//���ڴ� 1, 2, 3�� ����
		if (pick == 2 || pick == 1 || pick == 3)
		{
			//High Low �̱� ���
			if (numb > 7 && pick == 1)
			{
				cout << "You got it right" << endl;
				
				ViewCard(mark, numb);
				
				cout << "The last five cards have been pulled are : ";

				for (int j = 0; j < ViewPrevCount; j++)
				{
					ViewPrevCard(showB[j], show[j]);

					cout << ", ";
				}

				cout << endl << endl;
			}
			else if (numb < 7 && pick == 2)
			{
				cout << "You got it right" << endl;
				
				ViewCard(mark, numb);

				cout << "The last five cards have been pulled are : ";

				for (int j = 0; j < ViewPrevCount; j++)
				{
					ViewPrevCard(showB[j], show[j]);

					cout << ", ";
				}
				cout << endl << endl;
			}
			else if (numb == 7 && pick == 3)
			{
				cout << "You got it right" << endl;
				
				ViewCard(mark, numb);
				
				cout << "The last five cards have been pulled are : ";

				for (int j = 0; j < ViewPrevCount; j++)
				{
					ViewPrevCard(showB[j], show[j]);

					cout << ", ";
				}

				cout << endl << endl;
			}
			else
			{
				cout << "Oooops you guess wrong" << endl;
				
				ViewCard(mark, numb);// mark�� int ���� �ƴ� ���� ����??
				
				cout << "The last five cards have been pulled are : ";

				for (int j = 0; j < ViewPrevCount; j++)
				{
					ViewPrevCard(showB[j], show[j]);

					cout << ", ";
				}

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