#include <iostream>
#include <string>
using namespace std; 


void Menu(int Num_Std, int Count, string *pName_Std, int *pScr_Std);


void Del(int &_Count, string *pName, int *pScore)
{
	string Del_Name;
	int Del_Numb = -1;
	int DelCtr = 0;

	if (_Count != 0)
	{
		cout << "���ݱ��� �Է� �� �л� �Դϴ�. " << endl;
		for (int i = 0; i < _Count; i++)
		{
			cout << pName[i] << ", ";
		}
		cout << endl;

		cout << " ������ �̸��� �Է��ϼ��� : ";
		cin >> Del_Name;


		while (DelCtr < _Count)
		{
			if (pName[DelCtr] == Del_Name)
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
			if (_Count == Del_Numb)
			{
				pName[Del_Numb] = " ";
				_Count--;
			}
			else
			{
				for (int i = Del_Numb; i < _Count - 1; i++)
				{
					pName[i] = pName[i + 1];
					pScore[i] = pScore[i + 1];
				}
				_Count--;
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

void Print(int &_Count,string *pName, int *pScore)
{
	if (_Count != 0)
	{
		cout << _Count << "�� �л��� ������ ����մϴ�" << endl << endl;
		for (int i = 0; i < _Count; i++)
		{
			cout << pName[i] << " : " << pScore[i] << endl;
		}
		cout << endl;
		cout << "�Է� �� �л��� ������ ��� ����Ͽ����ϴ�" << endl << endl;
	}
	else 
	{
		cout << "�Է� �� ������ �����ϴ� " << endl << endl;
	}
}

void Edit(int &_Count, string *pName, int *pScore)
{
	string change_std;
	string new_name;
	int new_scr = 0;
	int change_scr = 0;
	int changectr = 0;
	int editctr = -1;
	int Choice = 0;

	if (_Count != 0)
	{
		Print(_Count, pName, pScore);
		cout << endl;

		cout << "������ ���ϴ� �л��� �̸��� �Է��ϼ��� : ";
		cin >> change_std;

		while (changectr < _Count)
		{
			if (pName[changectr] == change_std)
			{
				editctr = changectr;
				break;
			}
			changectr++;
		}

		if (editctr == -1)
		{
			cout << "�л� ������ ã�� �� �����ϴ�" << endl;
		}
		else
		{
			cout << "������ �̸��� �Է��ϼ��� : ";
			cin >> new_name;
			pName[changectr] = new_name;
			cout << new_name << " �� ������ ������ �Է��ϼ��� : ";
			cin >> new_scr;
			pScore[change_scr] = new_scr;

			cout << pName[changectr] << " : " << pScore[changectr] << "�� ������ ���� �Ǿ����ϴ�" << endl;
		}

		cout << endl;
	}
}

void Add(int Num_Std, string *pName_Std, int *pScr_Std, int &_Count)
{
	string Names;
	int Score = 0;
	int Choice = 0;
	
		if (_Count < Num_Std )
		{
			cout << "���Ӱ� �Է��� �л��� �̸��� ������ �����ϼ���" << endl;
			cout << "�л� �̸� : ";
			cin >> Names;
			pName_Std[_Count] = Names;
			cout << "���� : ";
			cin >> Score;
			pScr_Std[_Count] = Score;

			_Count++;

			cout << "���ο� �л��� ������ �Է� �Ǿ����ϴ�" << endl;
			cout << "��� ��� �Ͻðڽ��ϱ�? (�� = 1 // �ƴϿ� = 2) ";
			cin >> Choice;

			cout << endl << endl;

			switch (Choice)
			{
			case 1: Add(Num_Std, pName_Std, pScr_Std, _Count); break;
			case 2: Menu(Num_Std, _Count, pName_Std, pScr_Std); break;
			}

		}
		else
		{
			cout << "ó�� �Է��� �ִ� �ο��� �ʰ��߽��ϴ�! ���� �ο� �� ���� �ؾ� �����մϴ�" << endl;
			Del (_Count,  pName_Std,  pScr_Std);
		}
}

void Menu(int Num_Std, int Count, string *pName_Std,int *pScr_Std)
{
	int Input = 0;

	while (true)
	{
		cout << " 1.���� �Է� " << endl;
		cout << " 2.���� ��� " << endl;
		cout << " 3.���� ���� " << endl;
		cout << " 4.���� ���� " << endl;
		//cout << " 5.���� ���� " << endl;


		cin >> Input;
		switch (Input)
		{
		case 1: Add(Num_Std, pName_Std, pScr_Std, Count); break;
		case 2: Print(Count, pName_Std, pScr_Std); break;
		case 3: Edit(Count, pName_Std, pScr_Std); break;
		case 4: Del(Count, pName_Std, pScr_Std); break;
		//case 5: cout << "�ý����� �����մϴ�!" << endl; break;
		}
	}
}


void main()
{	
	int Num_Std = 0;
	int Count = 0;
	string *pName_Std = nullptr;
	int *pScr_Std = nullptr;
	
	cout << " �� �л� ���� �Է� �ϼ��� " << endl;
	cin >> Num_Std;

	cout << endl << endl;
	
	if (Num_Std == 0)
	{
		cout << "�л� ���� 0�� �� �����ϴ�" << endl;
		main();
	}
	else 
	{
		cout << Num_Std<< "���� ����ǥ ������ ���� �մϴ� " << endl<< endl;

		if (pName_Std == nullptr && pScr_Std == nullptr)
		{
			pName_Std = new string[Num_Std];
			pScr_Std = new int[Num_Std];
		}

		Menu(Num_Std, Count, pName_Std, pScr_Std);
	}

	delete[] pName_Std; delete[] pScr_Std;
	pName_Std = nullptr; pScr_Std = nullptr; 
}