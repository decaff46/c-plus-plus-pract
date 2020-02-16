#include <iostream>
#include <string>
using namespace std;

/*
	조사숙제

		사용자정의 자료형

			- 열거체
			- 공용체
			- 구조체

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
		//	메뉴
		Menu();

		//	입력
		cout << "입력 : ";
		cin >> input;

		//	처리
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
	cout << "1. 입력" << endl;
	cout << "2. 출력" << endl;
	cout << "3. 삭제" << endl;
	cout << "4. 종료" << endl;
}
void	Add(string *&_rpStdName, int *&_rpStdScore, int &_rStdCnt, int &_rStdSize)
{
	//	지금 꽉 찼다.
	if (_rStdSize == _rStdCnt)
	{
		//	추가하겠냐?
		int addInput = 0;

		cout << "공간부족.. 추가하겠습니까?(1==Y) : ";
		cin >> addInput;

		//	Y
		//	메모리 재 할당
		if (addInput == 1)
		{
			int addSize = 0;
			cout << "추가할 공간크기 입력 : ";
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

	//	성적표입력
	cout << "이름 : ";
	cin >> _rpStdName[_rStdCnt];

	cout << "성적 : ";
	cin >> _rpStdScore[_rStdCnt];

	_rStdCnt++;


	//	추가입력을 하고 싶냐?
	int addInput = 0;

	cout << endl << "추가 입력?(1==Y) : ";
	cin >> addInput;

	//	Y
	if (addInput == 1)
	{
		Add(_rpStdName, _rpStdScore, _rStdCnt, _rStdSize);
	}
}
void	Out(string *_pStdName, int *_pStdScore, int _stdCnt )
{
	cout << endl << "출력" << endl;

	for (int i = 0; i < _stdCnt; i++)
	{
		cout << _pStdName[i] << " : " << _pStdScore[i] << endl;
	}
	cout << "출력끝" << endl << endl;
}
void	Del()
{

}