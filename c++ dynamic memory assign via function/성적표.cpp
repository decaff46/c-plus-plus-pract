#include <iostream>
#include <string>
using namespace std;

/*
	�������

		��������� �ڷ���

			- ����ü
			- ����ü
			- ����ü

*/

void	Program();
void	Menu();
void	Add(string *&_rpStdName, int *&_rpStdScore, int &_rStdCnt, int &_rStdSize);
void	Out(string *_pStdName, int *_pStdScore, int _stdCnt);
void	Del();

int main()
{
	Program();

	return 0;
}

void	Program()
{
	int		stdCnt			= 0;
	int		stdSize			= 1;
	string	*pStdName		= new string[stdSize];
	int		*pStdScore		= new int[stdSize];
	bool	isPlaying		= true;
	int		input = 0;

	while (isPlaying)
	{
		//	�޴�
		Menu();

		//	�Է�
		cout << "�Է� : ";
		cin >> input;

		//	ó��
		switch (input)
		{
		case 1:	Add(pStdName, pStdScore, stdCnt, stdSize);	break;
		case 2:	Out(pStdName, pStdScore, stdCnt);			break;
		case 3:	Del();		break;
		case 4:	isPlaying = false;
		}
	}

	delete[] pStdName;
	pStdName = nullptr;
	delete[] pStdScore;
	pStdScore = nullptr;
}

void	Menu()
{
	cout << "1. �Է�" << endl;
	cout << "2. ���" << endl;
	cout << "3. ����" << endl;
	cout << "4. ����" << endl;
}
void	Add(string *&_rpStdName, int *&_rpStdScore, int &_rStdCnt, int &_rStdSize)
{
	//	���� �� á��.
	if (_rStdSize == _rStdCnt)
	{
		//	�߰��ϰڳ�?
		int addInput = 0;

		cout << "��������.. �߰��ϰڽ��ϱ�?(1==Y) : ";
		cin >> addInput;

		//	Y
		//	�޸� �� �Ҵ�
		if (addInput == 1)
		{
			int addSize = 0;
			cout << "�߰��� ����ũ�� �Է� : ";
			cin >> addSize;

			string	*pNewName	= new string[_rStdSize + addSize];
			int		*pNewScore	= new int[_rStdSize + addSize];

			for (int i = 0; i < _rStdCnt; i++)
			{
				pNewName[i] = _rpStdName[i];
				pNewScore[i] = _rpStdScore[i];
			}
			delete[] _rpStdName;
			delete[] _rpStdScore;

			_rpStdName	= pNewName;
			_rpStdScore = pNewScore;
			_rStdSize += addSize;
		}
		else
		{
			//	N
			return;
		}
	}

	//	����ǥ�Է�
	cout << "�̸� : ";
	cin >> _rpStdName[_rStdCnt];

	cout << "���� : ";
	cin >> _rpStdScore[_rStdCnt];

	_rStdCnt++;


	//	�߰��Է��� �ϰ� �ͳ�?
	int addInput = 0;

	cout << endl << "�߰� �Է�?(1==Y) : ";
	cin >> addInput;

	//	Y
	if (addInput == 1)
	{
		Add(_rpStdName, _rpStdScore, _rStdCnt, _rStdSize);
	}
}
void	Out(string *_pStdName, int *_pStdScore, int _stdCnt )
{
	cout << endl << "���" << endl;

	for (int i = 0; i < _stdCnt; i++)
	{
		cout << _pStdName[i] << " : " << _pStdScore[i] << endl;
	}
	cout << "��³�" << endl << endl;
}
void	Del()
{

}