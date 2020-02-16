# include <iostream>
# include <Windows.h>

using namespace std;


//1.ī�� ����
//2. ī�� ����
//3. 8�� ����
//4. ī�� ����
//5. ī�� ���� a,b
//6. ī�� ��

void ViewCard(int _Pick[])
{

	switch (_Pick[] / 13)
	{
	case 0:		cout << "��";  break;
	case 1:		cout << "��";  break;
	case 2:		cout << "��";  break;
	case 3:		cout << "��";  break;
	}
	switch (_Pick[] % 13)
	{
	case 0:		cout << "A";  break;
	case 10:	cout << "J";  break;
	case 11:	cout << "Q";  break;
	case 12:	cout << "K";  break;
	default:	cout << _Pick[] % 13 + 1;
	}
}

void main()
{
	srand(GetTickCount());


	//��ǥ �� ����
	const int Size = 4;
	int Out[Size*Size] = {};
	bool IsView[Size*Size] = {};
	int Card[52];
	int Pick[Size*2] = {};


	//ī�� ����
	for (int i = 0; i < 52; i++)
	{
		Card[i] = i;
	}


	//ī�� ����
	for (int i = 0; i < 100; i++)
	{
		int S = rand() % 52;
		int D = rand() % 52;

		int Temp = Card[S];
		Card[S] = Card[D];
		Card[D] = Temp;
	}


////8�� ����
//for (int j = 0; j < Size * 2; j++)
//{
//	Pick[j] = Card[j];
//}



	//���� �׸� 2��
	for (int i = 0; i < Size*Size; i++)
	{
		Out[i] = Card[i / 2];  
	}
	
	

	//��ǥ�� ����
	for (int i = 0; i < Size*Size * 3; i++) 
	{
		int Src = rand() % (Size*Size);
		int Dev = rand() % (Size*Size);

		int Temp = Out[Src];
		Out[Src] = Out[Dev];
		Out[Dev] = Temp;
	}



	//���� ��
	int		NOT_SELECT = -1;
	int		First = NOT_SELECT;
	int		Second = NOT_SELECT;

	int		Index = 0;


	while (true) 
	{
		for (int j = 0; j < Size; j++)
		{
			for (int i = 0; i < Size; i++)
			{
				//if (IsView[Size*j + i] == false)
				//{
				//	cout << "��";
				//}
				//else
				//{
					switch (Out[Size*j + i])  // ���ڷα����� �ϰڴµ� ī�� ����� �����Դ� ���ϰ���
					{
					case 0:	cout << Pick[0];	break;						
					case 1:	cout << Pick[1];	break;						
					case 2:	cout << Pick[2];	break;						
					case 3:	cout << Pick[3];	break;						
					case 4:	cout << Pick[4];	break;						
					case 5:	cout << Pick[5];	break;						
					case 6:	cout << Pick[6];	break;						
					case 7:	cout << Pick[7];	break;						
					}														
				//}															
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