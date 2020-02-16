#include "MyString.h"


class Transcript
{
private:

	struct Info
	{
		DataType *Name;
		int Kor;
		int Eng;
		int Math;
	};

	bool Playing = true;
	int NumCnt = 0;
	int StdSize = 2;
	Info *pTrans = nullptr;
	Info *pNTrans = nullptr;

public:
	Transcript()
	{
		pTrans = new Info[StdSize];
	}
	~Transcript()
	{
		cout << "���α׷� ����" << endl;
		delete[] pTrans;
	}
	void start();
	void Add();
	void Out();
	void Del();
	void Edit();

};

void Transcript::start()
{
	if (pTrans == nullptr)
	{
		pTrans = new Info [StdSize];
	}

	int Input = 0;

	while (Playing)
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
		case 1: Add();  break;
		case 2: Out();  break;
		case 3: Del();  break;
		case 4: Edit();	break;
		case 5: Playing = false;				break;
		}
	}
}

void Transcript::Add()
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

			if (pNTrans == nullptr)
			{
				pNTrans = new Info[StdSize + Add];
			}

			for (int i = 0; i < NumCnt; i++)
			{
				pNTrans[i] = pTrans[i];
			}

			delete[] pTrans;
			StdSize += Add;

			pTrans = pNTrans;
		}
		else
		{
			return;
		}
		//�⺻ ����ǥ
		cout << "�̸� : ";
		cin >> pTrans[NumCnt].Name;
		cout << "����� : ";
		cin >> pTrans[NumCnt].Kor;
		cout << "����� : ";
		cin >> pTrans[NumCnt].Eng;
		cout << "���м��� : ";
		cin >> pTrans[NumCnt].Math;

		cout << pTrans[NumCnt].Name << " : " << pTrans[NumCnt].Kor << ", " << pTrans[NumCnt].Eng << ", " << pTrans[NumCnt].Math << " �� �߰� �߽��ϴ� " << endl;

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

void Transcript::Out()
{
	if (NumCnt != 0)
	{
		cout.width(4);
		cout << "�̸� : \t ����, ����, ����" << endl;
		for (int i = 0; i < NumCnt; i++)
		{
			cout << pTrans[i].Name << " : " << pTrans[i].Kor << " , " << pTrans[i].Eng << " , " << pTrans[i].Math << endl;
		}
		cout << "��� ��" << endl;
	}
	else
	{
		cout << "�Է� �� �л��� �����ϴ�!" << endl;
	}
	cout << endl;
}

void Transcript::Del()
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
			if (pTrans[DelCnt].Name == DelName)
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
				pTrans[DelCnt].Name = "";
				NumCnt--;
			}
			else
			{
				for (int i = DelCnt; i < NumCnt - 1; i++)
				{
					pTrans[i] = pTrans[i + 1];
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

void Transcript::Edit()
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
			if (pTrans[ChangeCnt].Name == ChangeName)
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
			pTrans[ChangeCnt].Name = ChangeName;
			cout << ChangeName << " �� ������ ������ �Է��ϼ���(������ ����) : ";
			cin >> ChangeScore;
			pTrans[ChangeCnt].Kor = ChangeScore;
			cin >> ChangeScore;
			pTrans[ChangeCnt].Eng = ChangeScore;
			cin >> ChangeScore;
			pTrans[ChangeCnt].Math = ChangeScore;

			cout << pTrans[ChangeCnt].Name << " : " << pTrans[ChangeCnt].Kor << pTrans[ChangeCnt].Eng << pTrans[ChangeCnt].Math << "�� ������ ���� �Ǿ����ϴ�" << endl;
		}
	}
	else
	{
		cout << "�Է� �� �л��� �����ϴ�!" << endl;
	}
	cout << endl << endl;
}
