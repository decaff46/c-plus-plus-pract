#include <iostream>
using namespace std;

/*
	포인터

		주소값을 저장할 수 있는 변수
	
	변수의 주소값
		& 연산자


	일반변수 선언

		자료형 변수명 = 초기화값;

		자료형 *변수명 = 초기화주소값;

	연산자

		*	해당 주소값에 위치한 변수

		&	해당 변수의 주소값
*/

void RFunc(int &_Num)
{
	// int &_Num = Num;
	_Num += 100;
}
void PFunc(int *_pNum)
{
	// int *_pNum = &Num;
	*_pNum += 100;
}
void PFunc2(int *_pNum)
{
	_pNum = 0;
}

void main()
{
	int Num = 100;
	RFunc(Num);

	cout << Num << endl;

	PFunc(&Num);

	cout << Num << endl;

	int *pNum = &Num;

	PFunc2(pNum);


	return;

	int  a = 10;
	int*  p = &a;
	int* *p2 = &p;
	int** *p3 = &p2;

	double       ****dp, dp2, **dp3, *******dp4;

	cout << sizeof(dp) << endl;
	cout << sizeof(dp2) << endl;

	cout << &a << endl;
}