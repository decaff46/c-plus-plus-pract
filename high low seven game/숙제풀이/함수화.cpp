#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	srand(GetTickCount());

	int card[52] = {};
	int pick = 0;
	int show[4] = {};


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


		//�ֱ� 5�� ī�� �迭
		int count = 0;
		show[count] = numb; // ����ü �̰Ŵ� ��� �ؾ� �ұ��? 



							//���� ī�忡 ���� high low  ����
		switch (mark)
		{
		case 0:
			cout << "Ace has been selected guess if it's high or low" << endl;
			cout << "1: higher than 7 // 2: lower than 7  :  ";
			cin >> pick;
			break;
		case 1:
			cout << "Heart has been selected guess if it's high or low" << endl;
			cout << "1: higher than 7 // 2: lower than 7  :  ";
			cin >> pick;
			break;
		case 2:
			cout << "Diamond has been selected guess if it's high or low" << endl;
			cout << "1: higher than 7 // 2: lower than 7  :  ";
			cin >> pick;
			break;
		case 3:
			cout << "Clover has been selected guess if it's high or low" << endl;
			cout << "1: higher than 7 // 2: lower than 7  :  ";
			cin >> pick;
			break;
		}


		//���ڴ� 1 �Ǵ� 2�� ����
		if (pick == 2 || pick == 1)
		{
			//High Low �̱� ���
			if (numb >= 7 && pick == 1)
			{
				cout << "You got it right" << endl;
				cout << "The card was picked was " << mark << " " << numb << endl; // mark�� int ���� �ƴ� ���� ����??
				cout << "The last five cards have been pulled are : " << show[count] << endl << endl;// �ϳ��� ���̰ڴµ� �ټ����� ���??
				count++;
			}
			else if (numb <= 7 && pick == 2)
			{
				cout << "You got it right" << endl;
				cout << "The card was picked was " << mark << " " << numb << endl;// mark�� int ���� �ƴ� ���� ����??
				cout << "The last five cards have been pulled are : " << mark << show[count] << endl << endl;// �ϳ��� ���̰ڴµ� �ټ����� ���??
				count++;
			}
			else
			{
				cout << "Oooops you guess wrong" << endl;
				cout << "The card was picked was " << mark << " " << numb << endl;// mark�� int ���� �ƴ� ���� ����??
				cout << "The last five cards have been pulled are : " << show[count] << endl << endl; // �ϳ��� ���̰ڴµ� �ټ����� ���??
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