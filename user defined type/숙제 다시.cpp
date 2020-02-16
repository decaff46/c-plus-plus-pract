#include <iostream>
#include <string>
using namespace std;


struct Transcript
{
	string	Name;
	int		Kor;
	int		Eng;
	int		Math;
};



void Add ( Transcript *&_pTrans,  int &_StdSize, int &_NumCnt);
void Out ( Transcript *&_pTrans,  int &_StdSize, int &_NumCnt);
void Del ( Transcript *&_pTrans,  int &_StdSize, int &_NumCnt);
void Edit( Transcript *&_pTrans,  int &_StdSize, int &_NumCnt);



void main()
{
	bool Playing = true;
	int NumCnt = 0;
	int StdSize = 2;

	//����ü Ȱ�� �����Ҵ�
	Transcript *pTrans = nullptr;
	if (pTrans == nullptr)
	{
		pTrans = new Transcript[StdSize];
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
		case 1: Add (pTrans, StdSize, NumCnt);  break;
		case 2: Out (pTrans, StdSize, NumCnt);  break;
		case 3: Del (pTrans, StdSize, NumCnt);  break;
		case 4: Edit(pTrans, StdSize, NumCnt);	break;
		case 5: Playing = false;				break;
		}
	}
}

void Add(struct Transcript *&_pTrans, int &_StdSize, int &_NumCnt)
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

			//����ü Ȱ�� 2. 
			Transcript *pNTrans = nullptr;
			if (pNTrans == nullptr)
			{
				pNTrans = new Transcript[_StdSize+Add];
			}
			//���ο� ������ ���� �� ���� 
			//pNTrans = _pTrans; �� �̷��� �������� ���۵��� ����Ű�� ����?
			for (int i = 0; i < _NumCnt; i++)
			{
				//pNTrans[i].Name = _pTrans[i].Name;
				//pNTrans[i].Kor = _pTrans[i].Kor;
				//pNTrans[i].Eng = _pTrans[i].Eng;
				//pNTrans[i].Math = _pTrans[i].Math;
				
				pNTrans[i] = _pTrans[i];
			}

			delete[] _pTrans;
			_StdSize += Add;

			//���� �迭 ���� ��, ���ο� �迭�� ���� �� �� �� ����
			_pTrans = pNTrans;			
			//delete[] pNTrans;  �� ���⼭ pNTrans�� �����ϸ� �ȵ���? ������ �Ͼ� ������ �ƴѰ�?
		}
		else
		{
			return;
		}
	}
	//�⺻ ����ǥ
	cout << "�̸� : ";
	cin >> _pTrans[_NumCnt].Name;
	cout << "����� : ";
	cin >> _pTrans[_NumCnt].Kor;
	cout << "����� : ";
	cin >> _pTrans[_NumCnt].Eng;
	cout << "���м��� : ";
	cin >> _pTrans[_NumCnt].Math;

	cout << _pTrans[_NumCnt].Name << " : " << _pTrans[_NumCnt].Kor << ", " << _pTrans[_NumCnt].Eng << ", " << _pTrans[_NumCnt].Math << " �� �߰� �߽��ϴ� " << endl;

	_NumCnt++;
	
	int YN = 0;
	cout << "��� �߰�? (1 = �� / 2 = ��)  :";
	cin >> YN;
	if (YN == 1)
	{
		Add(_pTrans, _StdSize, _NumCnt);
	}
	else
	{
		return;
	}
}

void Out (struct Transcript *&_pTrans, int &_StdSize, int &_NumCnt)
{
	//�Է� �л� üũ 
	if (_NumCnt != 0)
	{
		cout.width(4);
		cout << "�̸� : \t ����, ����, ����" << endl;
		for (int i = 0; i < _NumCnt; i++)
		{
			cout << _pTrans[i].Name << " : "  << _pTrans[i].Kor << " , " << _pTrans[i].Eng << " , " << _pTrans[i].Math << endl;
		}
		cout << "��� ��" << endl;
	}
	else
	{
		cout << "�Է� �� �л��� �����ϴ�!" << endl;
	}
	cout << endl;
}

void Del (struct Transcript *&_pTrans, int &_StdSize, int &_NumCnt)
{
	//�Է� �л� üũ 
	if (_NumCnt != 0)
	{
		string DelName = "";
		int DelCnt = 0;
		int DelTrk = -1;

		cout << "���� ���� �Է� �� �л� �����Դϴ�" << endl;
		Out(_pTrans, _StdSize, _NumCnt);

		cout << "������ �л��� �̸� ���� : ";
		cin >> DelName;

		while (DelCnt < _NumCnt)
		{
			if (_pTrans[DelCnt].Name == DelName)
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
				_pTrans[DelCnt].Name = "";
				_NumCnt--;
			}
			else
			{
				for (int i = DelCnt; i < _NumCnt - 1; i++)
				{
					//_pTrans[i].Name		= _pTrans[i + 1].Name;
					//_pTrans[i].Kor		= _pTrans[i + 1].Kor;
					//_pTrans[i].Eng		= _pTrans[i + 1].Eng;
					//_pTrans[i].Math		= _pTrans[i + 1].Math;
					_pTrans[i] = _pTrans[i+1];
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

void Edit(struct Transcript *&_pTrans, int &_StdSize, int &_NumCnt)
{
	//�Է� �л� üũ 
	if (_NumCnt != 0)
	{
		string ChangeName = "";
		int ChangeScore = 0;
		int ChangeCnt = 0;
		int ChangeTrk = -1;

		cout << "���� ���� �Է� �� �л� �����Դϴ�" << endl;
		Out(_pTrans, _StdSize, _NumCnt);

		cout << "������ �л��� �̸� ���� : ";
		cin >> ChangeName;

		while (ChangeCnt < _NumCnt)
		{
			if (_pTrans[ChangeCnt].Name == ChangeName)
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
			_pTrans[ChangeCnt].Name = ChangeName;
			cout << ChangeName << " �� ������ ������ �Է��ϼ���(������ ����) : ";
			cin >> ChangeScore;
			_pTrans[ChangeCnt].Kor = ChangeScore;
			cin >> ChangeScore;
			_pTrans[ChangeCnt].Eng = ChangeScore;
			cin >> ChangeScore;
			_pTrans[ChangeCnt].Math = ChangeScore;

			cout << _pTrans[ChangeCnt].Name << " : " << _pTrans[ChangeCnt].Kor  << _pTrans[ChangeCnt].Eng  << _pTrans[ChangeCnt].Math << "�� ������ ���� �Ǿ����ϴ�" << endl;
		}
	}
	else
	{
		cout << "�Է� �� �л��� �����ϴ�!" << endl;
	}
	cout << endl << endl;
}