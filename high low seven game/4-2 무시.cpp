#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	srand(GetTickCount());
	
	int card [52] = {};
	int pick = 0;
	int show[4] = {};


	//ī�� ����
	for (int i = 0; i < 52; i++)
	{
		card [i] = i;

		//ī�� �з� �� ���� ����
		int mark = card [i] / 13;
		int numb = card [i] % 13;
		
		
		//���ø� ���� 
		int Nmax = 13;
		int Nmin = 2;

		int Mmax = 3;
		int Mmin = 0;


		//���� ��ũ/ī�� ���� 
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
		} //���⼭ ��ũ�� �� ó���� ���̰� �� ������ ���� ī�忡�� ��ũ + ���ڸ� ���̴� ������ �� �ȵɱ�� 
		

		//�ֱ� 5�� ī�� �迭
		int count = 0;
		show[count] = numb;// ����ü �̰Ŵ� ��� �ؾ� �ұ��? 


		//���� ī�忡 ���� high low  ����
		cout << "A card has been selected guess if it's high or low" << endl;
		cout << "1: higher than 7 // 2: lower than 7" << endl;
		cin >> pick;
		

		//���ڴ� 1 �Ǵ� 2�� ����
		if (pick == 2 || pick == 1)
		{
			//High Low �̱� ���
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