#include <iostream>
#include < Windows.H>
using namespace std;



///// ���⼭ Ȧ �� ���� ���Դµ��� ¦���� �� ������ �Ǵµ� �װ� ���ϱ�??
void main()
{
	srand(GetTickCount());

	int Sel = 0;
	int A_Dice = 0;
	int B_Dice = 0;
	int Result = 0;




	while (true)
	{
		cout << "�ֻ����� �����ϴ�" << endl;
		cout << "1. Ȧ " << endl;
		cout << "2. ¦ " << endl ;
		cout << "3. ����" << endl << endl;
		

		//�ֻ��� ���� ��
		int Max = 6;
		int Min = 1;

		int Numb1 = rand() % (Max - Min + 1) + Min;
		int Numb2 = rand() % (Max - Min + 1) + Min;


		A_Dice = Numb1;
		B_Dice = Numb2;
		Result = A_Dice + B_Dice;

		cin >> Sel;

		if (Sel == 1 || Sel == 2 || Sel ==3)
		{
			if (Sel == 3)
			{
				cout << "����" << endl;
				break;
			}

			if ((Sel == 2 && Result % 2 == 0) ||
				(Sel == 1 && Result % 2 != 0))
			{
				cout << "�����Դϴ�" << endl;
			}
			else
			{
				cout << "�����Դϴ�" << endl;
			}

			cout << "���� ���ڴ� : ";
			cout << A_Dice << ", " << B_Dice;
			cout << endl;

		}
		else
		{
			cout << "1,2,3�� ����";
		}
				
		//	�Ͻ�����
		system("pause");

		// ȭ�� û��
		system("cls");

	}
	
}

