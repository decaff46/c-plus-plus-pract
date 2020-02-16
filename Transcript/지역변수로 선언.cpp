#include <iostream>
#include <string>
using namespace std;

//�ֵ��� ���� ���� ������ �Լ�ȭ ��Ű�� ���� �𸣰ڽ��ϴ� ���� 
string Rec_std[5] = {};
int Rec_scr[5] = {};
int Count = 0;
bool Isplaying = true;

void Del();
void Print();
void Add();
void Students();
void Edit();
void Menu();
void Change(int &_changectr, string &_Nname, int &_Nscr); 
void Ask(string &_input); //�����ε��� �ߴµ� �̰� �����? 

void Ask(string &_input)
{
	cout << "�Է� �� �л��� ������ �����ϴ� �л� ������ �Է��Ͻðڽ��ϱ�? ��/�ƴϿ�. �Է����� ���� ��� �޴��� ���� ���ϴ�.";
	cin >> _input;

	if (_input == "��")
	{
		Add();
	}
	if (_input == "�ƴϿ�")
	{
		Menu();
	}
	cout << endl;
}

void Change(int &_changectr, string &_Nname, int &_Nscr)
{
	cout << "������ �̸��� �Է��ϼ��� : ";
	cin >> _Nname;
	Rec_std[_changectr] = _Nname;
	cout << _Nname <<  " �� ������ ������ �Է��ϼ��� : " ;
	cin >> _Nscr;
	Rec_scr[_changectr] = _Nscr;

	cout << Rec_std[_changectr] << " : " << Rec_scr[_changectr] << "�� ������ ���� �Ǿ����ϴ�" << endl;
}

#pragma region  Out(); �ǹ� ���� 
//void Out()
//{
//	cout << "�ý����� �����մϴ�" << endl;
//	Isplaying = false;
//	
//} // �� ������ ����??? ������ 
#pragma endregion

void Edit()
{

	string change_std;
	string new_name;
	int new_scr;
	int change_scr = 0;
	int changectr = 0;
	int editctr = -1;
	string input;
	
	if (Count != 0)
	{
		Print(); 
		cout << endl;

		cout << "������ ���ϴ� �л��� �̸��� �Է��ϼ��� : ";
		cin >> change_std;

		while (changectr < Count)
		{
			if (Rec_std[changectr] == change_std)
			{
				editctr = changectr;
				break;
			}
			changectr++;
		}
		
		if (editctr == -1)
		{
			cout << "�л� ������ ã�� �� �����ϴ�" << endl;
			Edit();
		}
		else
		{
			Change(changectr, new_name, new_scr);
		}

		cout << endl;
	}
	else
	{
		Ask(input);
	}	
}

void Del() // �� ���� ������ �ϴµ� ������ �տ��� ���� �Ͼ� ���°���? �и� �����ϰ� �Ѱ� ������;; 
{
	string Del_Name;
	int Del_Numb = -1;
	int DelCtr = 0;

	if (Count != 0)
	{
		cout << "���ݱ��� �Է� �� �л� �Դϴ�. " << endl;
		for (int i = 0; i < Count; i++)
		{
			cout << Rec_std[i] << ", ";
		}
		cout << endl;

		cout << " ������ �̸��� �Է��ϼ��� : ";
		cin >> Del_Name;


		while (DelCtr < Count)
		{
			if (Rec_std[DelCtr] == Del_Name)
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
				Rec_std[Del_Numb] = " ";
				Count--;
			}
			else
			{
				for (int i = Del_Numb; i < Count-1; i++)
				{
					Rec_std[i] = Rec_std[i + 1];
					Rec_scr[i] = Rec_scr[i + 1];
				}
				Count--;
			}
			cout << Del_Name << "�� ����Ʈ���� ���� �߽��ϴ�" << endl;
		}

	}
	else
	{
		cout << "�Էµ� ������ �����ϴ�" << endl;
	}

	cout << endl;
}

void Print()
{
	string input;

	if (Count != 0)
	{
		cout << "�л� ������ ����մϴ�" << endl << endl;
		for (int i = 0; i < Count; i++)
		{
			cout << Rec_std[i] << " : " << Rec_scr[i] << endl;
		}
		cout << endl;
		cout << "�Է� �� �л��� ������ ��� ����Ͽ����ϴ�" << endl << endl;
	}
	else
	{
		Ask(input);
	}
}

void Add()
{
	string students; 
	int score = 0;
	string input;
	
	if (Count < 5)
	{
		cout << "���Ӱ� �Է��� �л��� �̸��� ������ �����ϼ���" << endl;
		cout << "�л� �̸� : ";
		cin >> students;
		Rec_std[Count] = students;
		cout << "���� : ";
		cin >> score;
		Rec_scr[Count] = score;
		Count++;

		cout << "���ο� �л��� ������ �Է� �Ǿ����ϴ�" << endl;
		cout << "��� ��� �Ͻðڽ��ϱ�?" << endl;
		cin >> input;
		if (input == "��")
		{
			Add();
		}
		if (input == "�ƴϿ�")
		{
			Students();
		}
	}
	else
	{
		cout << "�Է� �ִ� �л��� (5��)�� �ʰ� �߽��ϴ� �� �Է��� ���� ��� ���� �ؾ� �մϴ�" << endl;
		cout << "���� �Ͻðڽ��ϱ�? (��/�ƴϿ�) ���� ���� ���� ��� ���ݱ��� �Էµ� ������ ����մϴ�";
		cin >> input;
		if (input == "��")
		{
			Del();
		}
		if (input == "�ƴϿ�")
		{
			Print();
		}
		cout << endl;
	}	
}

void Students()
{

	while (true)
	{
		int choice = 0;
		cout << " ���ϴ� ���ڸ� �Է��ϼ��� " << endl;
		cout << "1. ���� �Է�" << endl;
		cout << "2. ���� ����" << endl;
		cout << "3. ���� ����" << endl;
		cout << "4. ���� ���" << endl;
		cout << "5. �Ŵ� ����" << endl;
		cout << " >> ";
		cin >> choice;

		if (choice == 1)
		{
			Add();
		}
		if (choice == 2)
		{
			Edit();
		}
		if (choice == 3)
		{
			Del();
		}
		if (choice == 4)
		{
			Print();
		}
		if (choice == 5)
		{
			break;
		}
	}	
	cout << endl;
	
}

void Menu()
{
	int choice = 0;
	while (true) // ���⼭ 3���� ������ break�� �ɰ� while�� ������ ���� ���� ����? 
	{
		cout << "����ǥ ���� �������� �Լ�ȭ ����!!!" << endl;
		cout << "1. �л� ����" << endl;
		cout << "2. ���� ���" << endl;
		cout << "3. ����" << endl;
		cout << " >> ";
		cin >> choice;

		if (choice == 1)
		{
			Students();
		}
		if (choice == 2)
		{
			Print();
		}
		if (choice == 3)
		{
			cout << "�ý����� �����մϴ�" << endl;
			break;
		}
	}
}


void main()
{
	while (Isplaying)
	{
		Menu();
	}
}