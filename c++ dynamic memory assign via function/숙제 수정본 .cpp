#include <iostream>
#include <string>
using namespace std;



///�� string���� ���� �������� �����߽��ϴ�! (�Ƹ���) �׷��� ���ڿ��� �Ϸ��� �ϴ� �ѱ� �Է½� ���� �մϴ� 
///ó������ �� ����� �����ؼ� �׷����� �ؼ� ����� �÷ȴµ��� �׷��׿� �ֱ׷����?? 
///���� �߻��� Program()�� �ѹ� ���� ?�� �����µ� �̰� ���� �ǹб��?


void Program();
void Add (char *&_pName, int *&_pScore, int &_StdSize,int &_NumCnt);
void Out (char *&_pName, int *&_pScore, int &_StdSize, int &_NumCnt);
void Del (char *&_pName, int *&_pScore, int &_StdSize, int &_NumCnt);
void Edit(char *&_pName, int *&_pScore, int &_StdSize, int &_NumCnt);

void main()
{
	Program();
}

void Program()
{
	bool Playing = true;
	int NumCnt = 0;
	int StdSize = 2;

	//string *pName = nullptr;  
	char *pName  = nullptr;
	int  *pScore = nullptr;

	if (pName == nullptr && pScore == nullptr)
	{
		pName	= new char[StdSize];
		pScore	= new int [StdSize];
	}

	int Input = 0;
	while (Playing)
	{
		
		cout << endl << " 1. �л� �Է�" << endl;
		cout << " 2. �л� ���" << endl;
		cout << " 3. �л� ����" << endl;
		cout << " 4. �л� ����" << endl;
		cout << " 5. ����" << endl;
		cout << "���ϴ� ��ȣ�� �����ϼ���   : ";
		cin >> Input;

		switch (Input)
		{
		case 1: Add (pName, pScore, StdSize, NumCnt); break;
		case 2: Out (pName, pScore, StdSize, NumCnt); break;
		case 3: Del (pName, pScore, StdSize, NumCnt); break;
		case 4: Edit(pName, pScore, StdSize, NumCnt); break;
		case 5: Playing = false;					  break;
		}
	}
}

void Add (char *&_pName, int *&_pScore, int &_StdSize, int &_NumCnt)
{
	//�뷮 üũ 
	if (_NumCnt == _StdSize)
	{
		int Input = 0;
		cout << "�뷮�� �� á���ϴ� �߰� �Ͻðڽ��ϱ�? (1 = �� / 2 = �ƴϿ�)   :";
		cin >> Input;

		if (Input == 1)
		{
			int Add = 0;
			cout << "�߰� �ο� �Է�  : ";
			cin >> Add;

			char *pNewName  = nullptr;
			int  *pNewScore = nullptr;

			if (pNewName == nullptr && pNewScore == nullptr)
			{
				pNewName	= new char[_StdSize + Add];
				pNewScore	= new int [_StdSize + Add];
			}

			for (int i = 0; i < _NumCnt; i++)
			{
				pNewName[i] = _pName[i];
				pNewScore[i]= _pScore[i];
			}

			delete[] _pName;
			delete[] _pScore;
			
			_StdSize += Add;
			_pName  = pNewName;
			_pScore = pNewScore;
		}	
		else
		{
			return;
		}
	}
	
	//�⺻ ����ǥ
	cout << "�̸� : ";
	cin >> _pName[_NumCnt];
	cout << "���� : ";
	cin >> _pScore[_NumCnt];

	cout << _pName[_NumCnt] << " : " << _pScore[_NumCnt] << " �� �߰� �߽��ϴ� " << endl;
	_NumCnt++;

	int YN = 0;
	cout << "��� �߰�? (1 = �� / 2 = ��)  :";
	cin >> YN;
	if (YN == 1)
	{
		Add(_pName, _pScore, _StdSize, _NumCnt);
	}
	else
	{
		return;
	}
	cout << endl << endl;
}
		 
void Out (char *&_pName, int *&_pScore, int &_StdSize, int &_NumCnt)
{
	//�Է� �л� üũ 
	if (_NumCnt != 0)
	{
		for (int i = 0; i < _NumCnt; i++)
		{
			cout << _pName[i] << " : " << _pScore[i] << endl;
		}
		cout << "��� ��" << endl;
	}
	else
	{
		cout << "�Է� �� �л��� �����ϴ�!" << endl;
	}
	cout << endl << endl;
}
		  
void Del (char *&_pName, int *&_pScore, int &_StdSize, int &_NumCnt)
{
	//�Է� �л� üũ 
	if (_NumCnt != 0)
	{
		char DelName = '\n';
		int DelCnt = 0;
		int DelTrk = -1;
		
		cout << "���� ���� �Է� �� �л� �����Դϴ�" << endl;
		Out(_pName, _pScore, _StdSize, _NumCnt);

		cout << "������ �л��� �̸� ���� : ";
		cin >> DelName;

		while (DelCnt < _NumCnt)
		{
			if (_pName[DelCnt] == DelName)
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
			if (_NumCnt == DelCnt)
			{
				_pName[DelCnt] = '\n';
				_NumCnt--;
			}
			else
			{
				for (int i = DelCnt; i < _NumCnt - 1; i++)
				{
					_pName[i] = _pName[i + 1];
					_pScore[i] = _pScore[i + 1];
				}
				_NumCnt--;
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
		  
void Edit(char *&_pName, int *&_pScore, int &_StdSize, int &_NumCnt)
{
	//�Է� �л� üũ 
	if (_NumCnt != 0)
	{
		char ChangeName = '\n';
		int ChangeScore = 0;
		int ChangeCnt = 0;
		int ChangeTrk = -1;

		cout << "���� ���� �Է� �� �л� �����Դϴ�" << endl;
		Out(_pName, _pScore, _StdSize, _NumCnt);

		cout << "������ �л��� �̸� ���� : ";
		cin >> ChangeName;

		while (ChangeCnt < _NumCnt)
		{
			if (_pName[ChangeCnt] == ChangeName)
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
			_pName[ChangeCnt] = ChangeName;
			cout << ChangeName << " �� ������ ������ �Է��ϼ��� : ";
			cin >> ChangeScore;
			_pScore[ChangeCnt] = ChangeScore;

			cout << _pName[ChangeCnt] << " : " << _pScore[ChangeCnt] << "�� ������ ���� �Ǿ����ϴ�" << endl;
		}
	}
	else
	{
		cout << "�Է� �� �л��� �����ϴ�!" << endl;
	}
	cout << endl << endl;
}