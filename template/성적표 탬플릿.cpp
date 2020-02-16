#include <iostream>

using namespace std; 

template <typename T>
class Person
{
private:
	struct Info 
	{
		T *Name;
		T Kor;
		T Eng;
		T Math;
	};

	int		NumCnt = 0;
	int		StdSize = 2;
	Info	*pInfo = nullptr;
	Info	*nInfo = nullptr;


public:
	Person() {}
	~Person() 
	{
		delete pInfo[];
		delete nInfo[];
	}

	void Add();
	void Out();
	void Del();
	void Edit();
};

template <typename T>
void Person::Add()
{
	if (NumCnt == StdSize)
	{
		int Input = 0;
		cout << "�뷮�� �� á���ϴ� �߰� �Ͻðڽ��ϱ�? (1 = �� / 2 = �ƴϿ�)   :";
		cin >> Input;

		if (Input == 1)
		{
			int Add = 0;
			cout << "�߰� �ο� �Է�  : ";
			cin >> Add;

			//����ü Ȱ�� 2. 
			if (nInfo == nullptr)
			{
				nInfo = new Info[StdSize + Add];
			}

			for (int i = 0; i < NumCnt; i++)
			{
				nInfo[i] = pInfo[i];
			}

			delete[] pInfo;
			StdSize += Add;

			pInfo = nInfo;
		}
		else
		{
			return;
		}

		//�⺻ ����ǥ
		cout << "�̸� : ";
		cin >> pInfo[NumCnt].Name;
		cout << "����� : ";
		cin >> pInfo[NumCnt].Kor;
		cout << "����� : ";
		cin >> pInfo[NumCnt].Eng;
		cout << "���м��� : ";
		cin >> pInfo[NumCnt].Math;

		cout << pInfo[NumCnt].Name << " : " << pInfo[NumCnt].Kor << ", " << pInfo[NumCnt].Eng << ", " << pInfo[NumCnt].Math << " �� �߰� �߽��ϴ� " << endl;

		NumCnt++;

		int YN = 0;
		cout << "��� �߰�? (1 = �� / 2 = ��)  :";
		cin >> YN;
		if (YN == 1)
		{
			Add();
		}
		else
		{
			return;
		}
	}
}

template <typename T>
void Person::Out()
{
	if (NumCnt != 0)
	{
		cout.width(4);
		cout << "�̸� : \t ����, ����, ����" << endl;
		for (int i = 0; i < NumCnt; i++)
		{
			cout << pInfo[i].Name << " : " << pInfo[i].Kor << " , " << pInfo[i].Eng << " , " << pInfo[i].Math << endl;
		}
		cout << "��� ��" << endl;
	}
	else
	{
		cout << "�Է� �� �л��� �����ϴ�!" << endl;
	}
	cout << endl;
}

template <typename T>
void Person:: Del() 
{
	if (NumCnt != 0)
	{
		string DelName = "";
		int DelCnt = 0;
		int DelTrk = -1;

		cout << "���� ���� �Է� �� �л� �����Դϴ�" << endl;
		Out();

		cout << "������ �л��� �̸� ���� : ";
		cin >> DelName;

		while (DelCnt < NumCnt)
		{
			if (pInfo[DelCnt].Name == DelName)
			{
				DelTrk = DelCnt;
				break;
			}
			DelCnt++;
		}

		if (DelTrk == -1)
		{
			cout << "�Էµ� ������ ã�� �� �����ϴ� " << endl;
		}
		else
		{
			if (NumCnt == DelCnt)
			{
				pInfo[DelCnt].Name = "";
				NumCnt--;
			}
			else
			{
				for (int i = DelCnt; i < NumCnt - 1; i++)
				{
					pInfo[i] = pInfo[i + 1];
				}
				NumCnt--;
			}
			cout << DelName << "�� ����Ʈ���� ���� �߽��ϴ�" << endl;
		}

	}
	else
	{
		cout << "�Է� �� �л��� �����ϴ�!" << endl;
	}
	cout << endl << endl;
}

template <typename T>
void Person::Edit()
{
	if (NumCnt != 0)
	{
		string ChangeName = "";
		int ChangeScore = 0;
		int ChangeCnt = 0;
		int ChangeTrk = -1;

		cout << "���� ���� �Է� �� �л� �����Դϴ�" << endl;
		Out();

		cout << "������ �л��� �̸� ���� : ";
		cin >> ChangeName;

		while (ChangeCnt < NumCnt)
		{
			if (pInfo[ChangeCnt].Name == ChangeName)
			{
				ChangeTrk = ChangeCnt;
				break;
			}
			ChangeCnt++;
		}

		if (ChangeTrk == -1)
		{
			cout << "�Էµ� ������ ã�� �� �����ϴ� " << endl;
		}
		else
		{
			cout << "������ �̸��� �Է��ϼ��� : ";
			cin >> ChangeName;
			pInfo[ChangeCnt].Name = ChangeName;
			cout << ChangeName << " �� ������ ������ �Է��ϼ���(������ ����) : ";
			cin >> ChangeScore;
			pInfo[ChangeCnt].Kor = ChangeScore;
			cin >> ChangeScore;
			if (NumCnt != 0)
	{
		string ChangeName = "";
		int ChangeScore = 0;
		int ChangeCnt = 0;
		int ChangeTrk = -1;

		cout << "���� ���� �Է� �� �л� �����Դϴ�" << endl;
		Out();

		cout << "������ �л��� �̸� ���� : ";
		cin >> ChangeName;

		while (ChangeCnt < NumCnt)
		{
			if (pInfo[ChangeCnt].Name == ChangeName)
			{
				ChangeTrk = ChangeCnt;
				break;
			}
			ChangeCnt++;
		}

		if (ChangeTrk == -1)
		{
			cout << "�Էµ� ������ ã�� �� �����ϴ� " << endl;
		}
		else
		{
			cout << "������ �̸��� �Է��ϼ��� : ";
			cin >> ChangeName;
			pInfo[ChangeCnt].Name = ChangeName;
			cout << ChangeName << " �� ������ ������ �Է��ϼ���(������ ����) : ";
			cin >> ChangeScore;
			pInfo[ChangeCnt].Kor = ChangeScore;
			cin >> ChangeScore;
			pInfo[ChangeCnt].Eng = ChangeScore;
			cin >> ChangeScore;
			pInfo[ChangeCnt].Math = ChangeScore;

			cout << pInfo[ChangeCnt].Name << " : " << pInfo[ChangeCnt].Kor << pInfo[ChangeCnt].Eng << pInfo[ChangeCnt].Math << "�� ������ ���� �Ǿ����ϴ�" << endl;
		}
	}
	else
	{
		cout << "�Է� �� �л��� �����ϴ�!" << endl;
	}
	cout << endl << endl;[ChangeCnt].Eng = ChangeScore;
			cin >> ChangeScore;
			pInfo[ChangeCnt].Math = ChangeScore;

			cout << pInfo[ChangeCnt].Name << " : " << pInfo[ChangeCnt].Kor << pInfo[ChangeCnt].Eng << pInfo[ChangeCnt].Math << "�� ������ ���� �Ǿ����ϴ�" << endl;
		}
	}
	else
	{
		cout << "�Է� �� �л��� �����ϴ�!" << endl;
	}
	cout << endl << endl;
}


int main(void)
{
	Person person;
	bool Is_playing = true; 

	while (Is_playing) 
	{
		if (pInfo == nullptr)
		{
			pInfo = new Info[StdSize];
		}

		int Input = 0;

		while (Is_playing)
		{
			cout << " 1. �л� �Է�" << endl;
			cout << " 2. �л� ���" << endl;
			cout << " 3. �л� ����" << endl;
			cout << " 4. �л� ����" << endl;
			cout << " 5. ����" << endl;
			cout << "���ϴ� ��ȣ�� �����ϼ���   : ";
			cin >> Input;

			switch (Input)
			{
			case 1: person.Add();  break;
			case 2: person.Out();  break;
			case 3: person.Del();  break;
			case 4: person.Edit();	break;
			case 5: Is_playing = false;				break;
			}
		}
	}


	return 0;
}