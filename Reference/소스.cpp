#include <iostream>
using namespace std;

/*
	레퍼런스 변수

		기존의 변수에 별칭을 부여하여 사용하는 문법

		초기화를 필수적으로 해야한다.

	레퍼런스 선언

		자료형 &변수명 = 원본변수명;

		ex) int &rNum = Num;
			rNum = 10;
*/

void Pow2(int &rNum)
{
	rNum *= rNum;
}

void main()
{
	int Num = 10;
	int &rNum = Num;

	rNum = 100;

	cout << Num << endl;

	// int &rNum = Num;
	Pow2(Num);
	cout << Num << endl;
}