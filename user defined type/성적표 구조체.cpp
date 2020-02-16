#include <iostream>
#include <string>
using namespace std;


struct Transcript
{
	string	*pName = nullptr;
	int		*pKor = nullptr;
	int		*pEng = nullptr;
	int		*pMath = nullptr;

	// ������ �ʿ��ϴٴµ� �̰� ���� ���ϱ�?  ��Ģ������ ������ �������� ���� �Ѱ� �ƴϾ���?
	//if (pName == nullptr && pKor == nullptr && pEng == nullptr && pMath == nullptr)
	//{
	//	Trans.pName = new string[StdSize];
	//	Trans.pKor = new int[StdSize];
	//	Trans.pEng = new int[StdSize];
	//	Trans.pMath = new int[StdSize];
	//}
};


struct N_Trans
{
	string	*pNewName = nullptr;
	int		*pNewKor = nullptr;
	int		*pNewEng = nullptr;
	int		*pNewMath = nullptr;
};

void Program();
void Add (string *&_pName, int *&_pKor, int *&_pEng, int *&_pMath, int &_StdSize, int &_NumCnt);
void Out (string *&_pName, int *&_pKor, int *&_pEng, int *&_pMath, int &_StdSize, int &_NumCnt);
void Del (string *&_pName, int *&_pKor, int *&_pEng, int *&_pMath, int &_StdSize, int &_NumCnt);
void Edit(string *&_pName, int *&_pKor, int *&_pEng, int *&_pMath, int &_StdSize, int &_NumCnt);

void main()
{
	Program();
}


void Program()
{
	bool Playing = true;
	int NumCnt = 0;
	int StdSize = 2;
	
	//����ü ���
	Transcript Trans;

	if (Trans.pName == nullptr && Trans.pKor == nullptr && Trans.pEng == nullptr && Trans.pMath == nullptr)
	{
		Trans.pName		= new string[StdSize];
		Trans.pKor		= new int[StdSize];
		Trans.pEng		= new int[StdSize];
		Trans.pMath		= new int[StdSize];
	}

	int Input = 0;

	while (Playing)
	{
		cout << " 1. �л� �Է�" << endl;
		cout << " 2. �л� ���" << endl;
		cout << " 3. �л� ����" << endl;
		cout << " 4. �л� ����" << endl;
		cout << " 5. ����"		<< endl;
		cout << "���ϴ� ��ȣ�� �����ϼ���   : ";
		cin >> Input;

		switch (Input)
		{
		case 1: Add (Trans.pName, Trans.pKor, Trans.pEng,Trans.pMath, StdSize, NumCnt);  break;
		case 2: Out (Trans.pName, Trans.pKor, Trans.pEng,Trans.pMath, StdSize, NumCnt);  break;
		case 3: Del (Trans.pName, Trans.pKor, Trans.pEng,Trans.pMath, StdSize, NumCnt);  break;
		case 4: Edit(Trans.pName, Trans.pKor, Trans.pEng, Trans.pMath, StdSize, NumCnt); break;
		case 5: Playing = false;														 break;
		}

		cout << endl << endl;
	}
}

void Add(string *&_pName, int *&_pKor, int *&_pEng, int *&_pMath, int &_StdSize, int &_NumCnt)
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
			
			//����ü Ȱ��
			N_Trans NTran;

			if (NTran.pNewName == nullptr && NTran.pNewKor == nullptr && NTran.pNewEng == nullptr&& NTran.pNewMath == nullptr)
			{
				NTran.pNewName		= new string[_StdSize + Add];
				NTran.pNewKor		= new int[_StdSize + Add];
				NTran.pNewEng		= new int[_StdSize + Add];
				NTran.pNewMath		= new int[_StdSize + Add];
			}

			for (int i = 0; i < _NumCnt; i++)
			{
				NTran.pNewName[i] = _pName[i];
				NTran.pNewKor[i]  = _pKor [i];
				NTran.pNewEng[i]  = _pEng [i];
				NTran.pNewMath[i] = _pMath[i];
			}


			delete[] _pName;
			delete[] _pKor;
			delete[] _pEng;
			delete[] _pMath;


			_StdSize += Add;
			_pName	= NTran.pNewName;
			_pKor	= NTran.pNewKor;
			_pEng	= NTran.pNewEng;
			_pMath	= NTran.pNewMath;
		}
		else
		{
			return;
		}
	}


	//�⺻ ����ǥ
	cout << "�̸� : ";
	cin >> _pName[_NumCnt];
	cout << "����� : ";
	cin >> _pKor[_NumCnt];
	cout << "����� : ";
	cin >> _pEng[_NumCnt];
	cout << "���м��� : ";
	cin >> _pMath[_NumCnt];

	cout << _pName[_NumCnt] << " : " << _pKor[_NumCnt] << ", " << _pEng[_NumCnt] << ", " << _pMath[_NumCnt] <<" �� �߰� �߽��ϴ� " << endl;
	_NumCnt++;
	cout << endl;

	int YN = 0;
	cout << "��� �߰�? (1 = �� / 2 = ��)  :";
	cin >> YN;
	if (YN == 1)
	{
		Add(_pName, _pKor,_pEng, _pMath, _StdSize, _NumCnt);
	}
	else
	{
		return;
	}

}

void Out(string *&_pName, int *&_pKor, int *&_pEng, int *&_pMath, int &_StdSize, int &_NumCnt)
{
	//�Է� �л� üũ 
	if (_NumCnt != 0)
	{
		
		//���� �����ϴ� �� �� �˷� �ּ��� !
		cout << "�̸� : \t ����, ����, ����" << endl;
		for (int i = 0; i < _NumCnt; i++)
		{
			cout << _pName[i] << " : " << "\t"<< _pKor[i]  <<" , "<< _pEng[i]  <<" , "<< _pMath[i] << endl;
		}
		cout << "��� ��" << endl;
	}
	else
	{
		cout << "�Է� �� �л��� �����ϴ�!" << endl;
	}
	cout << endl;
}

void Del(string *&_pName, int *&_pKor, int *&_pEng, int *&_pMath, int &_StdSize, int &_NumCnt)
{
	//�Է� �л� üũ 
	if (_NumCnt != 0)
	{
		string DelName = "";
		int DelCnt = 0;
		int DelTrk = -1;

		cout << "���� ���� �Է� �� �л� �����Դϴ�" << endl;
		Out(_pName, _pKor, _pEng, _pMath, _StdSize, _NumCnt);

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
				_pName[DelCnt] = "";
				_NumCnt--;
			}
			else
			{
				for (int i = DelCnt; i < _NumCnt - 1; i++)
				{
					_pName[i] = _pName[i + 1];
					_pKor [i] = _pKor [i + 1];
					_pEng [i] = _pEng [i + 1];
					_pMath[i] = _pMath[i + 1];

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

void Edit(string *&_pName, int *&_pKor, int *&_pEng, int *&_pMath, int &_StdSize, int &_NumCnt)
{
	//�Է� �л� üũ 
	if (_NumCnt != 0)
	{
		string ChangeName = "";
		int ChangeScore = 0;
		int ChangeCnt = 0;
		int ChangeTrk = -1;

		cout << "���� ���� �Է� �� �л� �����Դϴ�" << endl;
		Out(_pName, _pKor, _pEng, _pMath, _StdSize, _NumCnt);

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
			cout << ChangeName << " �� ������ ������ �Է��ϼ���(������ ����) : ";
			cin >> ChangeScore;
			_pKor[ChangeCnt] = ChangeScore;
			cin >> ChangeScore;
			_pEng[ChangeCnt] = ChangeScore;
			cin >> ChangeScore;
			_pMath[ChangeCnt] = ChangeScore;

			cout << _pName[ChangeCnt] << " : " << _pKor[ChangeCnt] << ",\t" << _pEng[ChangeCnt] << ",\t" << _pMath[ChangeCnt]<< "�� ������ ���� �Ǿ����ϴ�" << endl;
		}
	}
	else
	{
		cout << "�Է� �� �л��� �����ϴ�!" << endl;
	}
	cout << endl << endl;
}