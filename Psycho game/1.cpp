#include <iostream>
#include <Windows.h>

using namespace std;




void main() 
{
	srand(GetTickCount());
	
	//ī�� ����
	int Card[52] = {};

	for (int i = 0; i < 52; i++)
	{
		Card[i] = i;
	}

	//��ǥ�� ���� 
	const int	Size = 4;
	int			Out[Size*Size] = {};
	bool		IsView[Size*Size] = {};

	for (int i = 0; i < Size*Size; i++)
	{
		Out[i] = i / 2;
	}


	// �̹� ī��
	int CardIndex = 0;


	//ī�� ����
	for (int i = 0; i < 200; i++)
	{
		int Temp1 = rand() % 52;
		int Temp2 = rand() % 52;

		int Swap = Card[Temp1];
		Card[Temp1] = Card[Temp2];
		Card[Temp2] = Swap;
	}




	//	�ݺ� ����
	bool	IsPlaying = true;
	int		Input = 0;

	//	�񱳿�
	int		NOT_SELECT = -1;
	int		First = NOT_SELECT;
	int		Second = NOT_SELECT;
	
														
	//���� ���� (�ݺ�)
	while (IsPlaying)
	{
		//ī�� ���� 
		for (int j = 0; j < Size; j++)
		{
			for (int i = 0; i < Size; i++)
			{			
				if (IsView[Size*j + i] == false) 
				{
					cout << "��";
				}
				else
				{
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
					case 0:		cout << "A" << " ";  break;
					case 11:	cout << "J" << " ";  break;
					case 12:	cout << "Q" << " ";  break;
					case 13:	cout << "K" << " ";  break;
					default:	cout << Num + 1 << " ";
					}
				}
			}
			cout << endl;
		}

		cout << "��ȣ : ";

		// �Է�
		if (First == NOT_SELECT)
		{
			cin >> First;
			IsView[First] = true;
		}
		else if (Second == NOT_SELECT)
		{
			cin >> Second;
			IsView[Second] = true;
		}

		// ����
		else
		{
			if (Out[First] != Out[Second])
			{
				IsView[First] = false;
				IsView[Second] = false;
			}


			First = NOT_SELECT;
			Second = NOT_SELECT;

			//	�Ͻ�����
			system("pause");
		}

		// ȭ�� û��
		system("cls");
	}
}

