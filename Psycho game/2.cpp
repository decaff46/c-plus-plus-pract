#include <iostream>
#include <Windows.h>
using namespace std;

void main()
{
	srand(GetTickCount());

	// �̸��� �ִ� ���
	const int	Size = 4;
	int			Out[Size*Size] = {};
	bool		IsView[Size*Size] = {};

	for (int i = 0; i < Size*Size; i++)
	{
		Out[i] = i / 2; //�̰� �ΰ��� ������ ī�尡 ���;��ؼ� /2�� �ϽŰǰ���?
	}

	// ����
	// 1. �ε��� 2���� ���Ƿ� �����Ѵ�.
	// 2. �ش� �ε����� ���� ��ü�Ѵ�.
	for (int i = 0; i < Size*Size * 3; i++) //Size*Size * 3 �� ���⼭ *3�� �ؾ� �ϳ���? ������ 200ó�� �׳� �ΰ���?
	{
		int Src = rand() % (Size*Size); 
		int Dev = rand() % (Size*Size);

		int Temp = Out[Src];
		Out[Src] = Out[Dev];
		Out[Dev] = Temp;
	}

	//	�ݺ� ����
	bool	IsPlaying = true;
	int		Input = 0;

	//	�񱳿�
	int		NOT_SELECT = -1;
	int		First = NOT_SELECT;
	int		Second = NOT_SELECT;

	while (IsPlaying)
	{
		// ���
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
					switch (Out[Size*j + i]) 
					{
					case 0:	cout << "��";	break;
					case 1:	cout << "��";	break;
					case 2:	cout << "��";	break;
					case 3:	cout << "��";	break;
					case 4:	cout << "��";	break;
					case 5:	cout << "��";	break;
					case 6:	cout << "��";	break;
					case 7:	cout << "��";	break;
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