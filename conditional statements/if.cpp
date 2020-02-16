#include <iostream>
using namespace std;

/*
	조건문

		조건이 참이면 실행되는 문법

	if	

		조건이 참이면 실행된다.
		
	else if

		위의 조건이 거짓이고, 내 조건이 참이면 실행된다.
		여러개 사용이 가능하다.

	else 

		위의 조건들이 거짓이면 실행된다.


	조건문의 구성

		if	

		if ~ else

		if ~ else if ~ else

	묶음 중 참 실행문이 있으면 하위 조건은 무시된다.

	if( 조건 )
	{
		명령1;
		명령2;
	}

	if( 조건1 )
	{
		if( 조건2)
		{
			A;
		}

		B;
	}

	if( 조건1 && 조건2 )
	{

	}
		
*/

void main()
{
	int Num = 1000;

	if (Num < 100)
	{
		cout << "Num은 100보다 작다" << endl;

		cout << "if" << endl;

	}
	

	else
		cout << "Num은 100보다는 크다." << endl;
}