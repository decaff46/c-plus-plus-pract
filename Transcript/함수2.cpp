#include <iostream>
#include <string>  // ��Ʈ���� ���µ� �־ �̰� �� �� �ʿ� �ұ�?
using namespace std;

string  Rec_Name[5] = {};
int Rec_Scr[5] = {};
int Count = 0;
bool Isplaying = true;
int choice = 0;


void Add();
void Printout();
void Delete();
void Out();


void Menu()
{

		cout << "�л� ��� �Դϴ�" << endl;
		cout << "1. �Է�" << endl;
		cout << "2. ���" << endl;
		cout << "3. ����" << endl;
		cout << "4. ����" << endl;
		cout << "���� : ";

		cin >> choice;

		if (choice == 1)
		{
			Add();
		}
		if (choice == 2)
		{
			Printout();
		}
		if (choice == 3)
		{
			Delete();
		}
		if (choice == 4)
		{
			Out();
		}
		
		cout << endl;
	
}


void Add()
{
	string student;
	int Result = 0;
	string Answer;

	if (Count < 5)
	{
		cout << "�Է��� �л� �̸��� �������� :";
		cin >> student;
		Rec_Name[Count] = student;
		cout << "�л��� ������ �����ϼ��� : ";
		cin >> Result;
		Rec_Scr[Count] = Result;
		Count++;
		cout << "���ο� �л��� �Է� �Ǿ����ϴ� !" << endl << endl;  
	}
	else
	{
		cout << "�Է� ������ �ִ� �ο� 5���� �ʰ� �߽��ϴ�. �� �Է��� ���� ��� �����ؾ� �մϴ�" << endl;
		cout << "���� �Ͻðڽ��ϱ�? (��/�ƴϿ�) �������� ���� ��� �ٷ� ����մϴ�. ";
		cin >> Answer;
		if (Answer == "��")
		{
			Delete();
		}
		if (Answer == "�ƴϿ�")
		{
			Printout();
		}
		/*else
		{
			cout << "\"�� / �ƴϿ�\"�� ���ð��� �մϴ�" << endl;
		}*/
	}
}


void Printout()
{
		int input = 0;

		if (Count != 0)
		{
			cout << "����ǥ�� ����մϴ�" << endl;
			for (int i = 0; i < Count; i++)
			{
				cout << Rec_Name[i] << " : " << Rec_Scr[i] << endl;
			}
		}
		else
		{
			cout << "�Է� �� �л��� ������ �����ϴ�" << endl;
			cout << "�л��� ������ �Է��Ͻ÷��� 1���� ��������; ����� 4���Դϴ�. " << endl;
			cin >> input;
			if (input == 1)
			{
				Add();
			}
			if (input == 4)
			{
				Out();
			}
		}
}


void Delete()
{
	string Del_Name;
	int Del_Numb = -1;
	int DelCtr = 0;

	if (Count != 0)
	{
		cout << "���ݱ��� �Է� �� �л� ���̵� �Դϴ�. " << endl;
		for (int i = 0; i < Count; i++)
		{
			cout << Rec_Name[i] << ", ";
		}
		cout << endl;

		cout << " ������ ID�� �Է��ϼ��� : ";
		cin >> Del_Name;


		while (DelCtr < Count)
		{
			if (Rec_Name[DelCtr] == Del_Name)
			{
				Del_Numb = DelCtr;
				break;
			}
			DelCtr++;
		}
		if (Del_Numb == -1)
		{
			cout << "������ �л��� ������ ã�� �� �����ϴ�" << endl;
		}
		else
		{
			if (Count == Del_Numb)
			{
				Rec_Name[Del_Numb] = " ";
				Count--;
			}
			else
			{
				for (int i = Del_Numb; i < Count-1; i++)
				{
					Rec_Name[i] = Rec_Name[i + 1];
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
}


void Out()
{
	cout << " �����մϴ� " << endl;
	Isplaying = false;
}


int main()
{
	while (Isplaying)
	{
		Menu();
	}
	return 0;
}
