#include <iostream>
#include <Windows.h>

using namespace std;


//if elseif�� ��� �ִ� �ݺ� ������ ���ִ� ����� ������? 

int main()
{
	srand(GetTickCount());

	int card[52] = {};
	int pick = 0;
	int count = 0;
	int show[5] = {};
	int copy[5] = {};

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
		
		show[count] = numb; // 5�������� �̾� ���ڴµ� �� �������ʹ� ��� �ڿ������� �о� ������?
		
		// 5�� ���� �о� �ֱ�
		for (int i = 0; i < 5; i++)
		{
			copy[i] = show[i + 1];
			
		}
	

		
		//���� ī�忡 ���� high low  ����
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


		//���ڴ� 1 �Ǵ� 2�� ����
		if (pick == 2 || pick == 1 || pick == 3)
		{
			//High Low �̱� ���
			if (numb > 7 && pick == 1)
			{
				cout << "You got it right" << endl;
				cout << "The card was picked was " << mark << " " << numb << endl; // mark�� int ���� �ƴ� ���� ����??
				cout << "The last five cards have been pulled are : ";

				if (count < 5)
				{
					for (int j = 0; j < 5; j++)
					{
						cout << show[j] << " ";  //���⼭�� ���ڸ� ���̴� ���� �ƴ� ī�� ������ ���̴� ���� ������??
						show[count] = numb;
					}

				}
				else
				{
					for (int j = 0; j < 5; j++)
					{
						cout << copy[j] << " ";  //���⼭�� ���ڸ� ���̴� ���� �ƴ� ī�� ������ ���̴� ���� ������??
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
						cout << show[j] << " ";  //���⼭�� ���ڸ� ���̴� ���� �ƴ� ī�� ������ ���̴� ���� ������??
					}

				}
				else
				{
					for (int j = 0; j < 5; j++)
					{
						cout << copy[j] << " ";  //���⼭�� ���ڸ� ���̴� ���� �ƴ� ī�� ������ ���̴� ���� ������??
					}
				}

				count++;
				cout << endl << endl;
			}
			else if (numb == 7 && pick == 3)
			{
				cout << "You got it right" << endl;
				cout << "The card was picked was " << mark << " " << numb << endl;// mark�� int ���� �ƴ� ���� ����??
				cout << "The last five cards have been pulled are : ";

				if (count < 5)
				{
					for (int j = 0; j < 5; j++)
					{
						cout << show[j] << " ";  //���⼭�� ���ڸ� ���̴� ���� �ƴ� ī�� ������ ���̴� ���� ������??
					}

				}
				else
				{
					for (int j = 0; j < 5; j++)
					{
						cout << copy[j] << " ";  //���⼭�� ���ڸ� ���̴� ���� �ƴ� ī�� ������ ���̴� ���� ������??
					}
				}

				count++;
				cout << endl << endl;
			}
			else
			{
				cout << "Oooops you guess wrong" << endl;
				cout << "The card was picked was " << mark << " " << numb << endl;// mark�� int ���� �ƴ� ���� ����??
				cout << "The last five cards have been pulled are : ";

				if (count < 5)
				{
					for (int j = 0; j < 5; j++)
					{
						cout << show[j] << " ";  //���⼭�� ���ڸ� ���̴� ���� �ƴ� ī�� ������ ���̴� ���� ������??
					}

				}
				else
				{
					for (int j = 0; j < 5; j++)
					{
						cout << copy[j] << " ";  //���⼭�� ���ڸ� ���̴� ���� �ƴ� ī�� ������ ���̴� ���� ������??
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