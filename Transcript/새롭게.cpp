#include <iostream>
#include <string>
using namespace std;


void Menu()
{
	cout << "1. �Է�" << endl;
	cout << "2. ���" << endl;
	cout << "3. ����" << endl;
	cout << "4. ����" << endl;
	cout << "���� : ";
}





void main()
{
	int Input = 0;
	int ID = 0;
	int Scr = 0;
	int Rec_Id[5] = {};
	int Rec_Scr[5] = {};
	const int Max = 5; 
	int Count = 0;
	bool Isplaying = true;
	string Answer;
	int Del_Id = -1;
	

	while (Isplaying)
	{

		Menu();
		cin >> Input;

		cout << endl << endl;

		switch (Input)
		{
		case 1:
			cout << "ID �Է� : ";
			cin >> ID;
			cout << "���� �Է� : "; // ������ ���߿�  ����ȭ
			cin >> Scr;

			if (Count+1 < Max)
			{
				Rec_Id[Count] = ID;
				Rec_Scr[Count] = Scr;
				Count++; 
			}
			else
			{
				cout << " �ִ� �Է� �ο� (5��)�� �ʰ��߽��ϴ�" << endl;
				cout << " �� �Է� �ϱ� ���ؼ� ���� �ؾ� �մϴ�. ���� �Ͻðڽ��ϱ�? " << endl;
				cin >> Answer;

				if (Answer == "��")
				{
					Input = 3;
					break;
				}
				else
				{
					cout << "�ټ����� ����ǥ�� ����մϴ�" << endl;
					Input = 2; 
					break;
				}
			}
			
			cout << endl;
			break;

		case 2:
			if (Count != 0)
			{
				cout << "���� ���" << endl;
				for (int i = 0; i < Count; i++)
				{
					cout << Rec_Id[i] << " : " << Rec_Scr[i] << endl;
				}
				cout << "��� �Ϸ�!" << endl;

			}
			else
			{
				cout << "��� ���� ����" << endl;
			}

			cout << endl;
			break;

		case 3:
			//int Del_Id = -1;  �� �������� �ȵǴ� �ɱ�??
			if (Count != 0)
			{
				cout << "���ݱ��� �Է� �� �л� ���̵� �Դϴ�. " << endl;
				for (int i = 0; i < Count; i++)
				{
					cout << Rec_Id[i] << ", " ;
				}
				cout << endl;
				cout << " ������ ID�� �Է��ϼ��� : ";
				cin >> Del_Id;
				
				int Del_Count = 0;
				while (Del_Count < Count)
				{
					if (Rec_Id[Del_Count] == Del_Id) 
					{
						Del_Id = Del_Count; 
						break;
					}
					Del_Count ++ ;
				}
				if (Del_Id == -1)
				{
					cout << "�л��� ������ ã�� �� �����ϴ�" << endl;
				}
				else
				{
					if (Count == Del_Id)
					{
						Count--;
						Rec_Id[Del_Id]= NULL;
					}
					else
					{
						for (int i = Del_Id; i < Count; i++)
						{
							Rec_Id[i] = Rec_Id[i + 1];
							Rec_Scr[i] = Rec_Scr[i + 1];
						}
						Count--;
					}
					cout << "���� �߽��ϴ�" << endl;
				}
				
			}
			else
			{
				cout << "�Էµ� ������ �����ϴ�" << endl;
			}

			cout << endl;
			break;

		case 4: 
			cout << "����" << endl;
			Isplaying = false;

			cout << endl;
			break;

		default: 
			cout << " 1,2,3,4 �߿��� �����ϼ��� ";
			cout << endl << endl;
			break;
		}

	}
	
}
