#include <iostream>
#include <Windows.h>
using namespace std;

void main()
{
	srand(GetTickCount());

	//	���̷ο켼��

	//	ī���غ�
	int		Card[52] = {};

	for (int i = 0; i < 52; i++)
	{
		Card[i] = i;
	}

	//	�̹� ������ ī��
	int		CardIndex = 0;
	
	//	ī�弯�´�.
	for (int i = 0; i < 200; i++)
	{
		int Src = rand() % 52;
		int Dev = rand() % 52;

		int Temp = Card[Src];
		Card[Src] = Card[Dev];
		Card[Dev] = Temp;
	}

	
	//	���� ����( �ݺ� )
	while (true)
	{
		//	���� ī�� ����
		cout << "���� ī�� : ";
		for (int i = 0; i < 5; i++)
		{
			int Index = CardIndex - i - 1;

			if (Index < 0)
			{
				break;
			}

			switch (Card[Index] / 13)
			{
			case 0:	cout << "��";  break;
			case 1:	cout << "��";  break;
			case 2:	cout << "��";  break;
			case 3:	cout << "��";  break;
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

		//	���̷ο켼���Է� �޴´�.
		cout << "1. ����" << endl;
		cout << "2. �ο�" << endl;
		cout << "3. ����" << endl;
		cout << "4. ����" << endl;
		cout << "�Է� : ";
		cin >> Input;

		if (Input == 4)
		{
			cout << "����" << endl;
			break;
		}

		//	ī�����
		cout << endl;

		switch (Card[CardIndex] / 13)
		{
		case 0:	cout << "��";  break;
		case 1:	cout << "��";  break;
		case 2:	cout << "��";  break;
		case 3:	cout << "��";  break;
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

		//	��� ó��
		if ((Input == 1 && Num > 6) ||
			(Input == 2 && Num < 6) ||
			(Input == 3 && Num == 6))
		{
			cout << "����" << endl;
		}
		else
		{
			cout << "����" << endl;
		}

		CardIndex++;

		//	�ܼ� �Ͻ����� ���
		system("pause");
		//	�ܼ� ȭ�� û��
		system("cls");
	}
}

/*
	C++			
	�ڹ�	100 ���� ����

*/