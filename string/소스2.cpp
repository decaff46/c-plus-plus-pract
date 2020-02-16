#include <iostream>
#include <string>
using namespace std;

bool IsPlaying = true;

void Quit()
{
	IsPlaying = false;
}

void SetScore(int &_NowCnt, string *_pId, int *_pKor, int *_Math)
{
	if (_NowCnt == 5)
		return;

	cout << "Id : ";
	cin >> _pId[_NowCnt];

	cout << "Kor : ";
	cin >> _pKor[_NowCnt];

	cout << "Math : ";
	cin >> _Math[_NowCnt];

	_NowCnt++;
}
void PrintScore(int _NowCnt, string *_pId, int *_pKor, int *_Math)
{
	for (int i = 0; i < _NowCnt; ++i)
	{
		cout << "Id : " << _pId[i] << endl;
	}
}

void main()
{
	int		NowCnt = 0;
	string Id[5] = {};
	int		Kor[5] = {};
	int		Math[5] = {};

	SetScore(NowCnt, Id, Kor, Math);
	SetScore(NowCnt, Id, Kor, Math);

	PrintScore(NowCnt, Id, Kor, Math);
}