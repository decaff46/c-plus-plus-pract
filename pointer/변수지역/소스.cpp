#include <iostream>
using namespace std;

//	지역

/*
	지역에서 선언된 변수는 지역이 끝나면 다 해제된다.

	해제되면, 없는 변수라서 사용불가
*/

/*
	메모리 영역

		4가지

		코드	영역

		데이터	영역	전역변수, 정적변수... 상수

		스택	영역	일반적으로 변수들 저장들..

		힙		영역	동적 변수들이 저장
		--------------------------------------------

	변수의 종류

		변수선언지역

			전역변수, 지역변수

		변수선언방법

			정적변수, 일반변수
*/
static int g_Num = 10;
int g_Num2 = 110;


void Test()
{
	// 일반 지역 변수
	int a = 10;

	cout << a << endl;

	a++;
}
void TestB()
{
	// 일반 지역 변수
	static int a = 10;

	cout << a << endl;

	a++;
}

void TestC();

//	
void main()
{
	TestC();
	TestC();
	TestC();
	TestC();
	TestC();
	TestC();

	return;

	int Num;

	{
		static int a = 10;

		cout << a << endl;
	}

	//cout << a << endl;

	int b = 10;

	{
		int b = 0;

		cout << b << endl;
	}

	cout << b << endl;
}