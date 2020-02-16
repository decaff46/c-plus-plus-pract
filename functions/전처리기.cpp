#include <iostream>
using namespace std;

#pragma region MyRegion


#pragma endregion

/*
	코드작성 - 컴파일 - 링킹 - 빌드파일생성

	전처리기

		컴파일전에 처리하는 문법

	전처리기 특징

		앞에 #이 붙는다.
		한줄에는 하나의 전처리기만 가능

		\ 연산자를 사용해서 하나의 전처리기가 여러줄 가능

		끝에 ;가 없다.

	전처리기 종류

		#include 

		#define

		#if, #ifdef, #endif,...

		#error

		#line

		#pragma

	////////////////////////////////////////////

	#include 
		붙여넣기

		<> , ""

	#define

		매크로

	매크로 상수

		#define MAX 10

	매크로 함수

		#define ADD(x) (x+=10)

	매크로 정의

		#define	KMK
*/

#pragma region 디파인들

#define MAX 10
#define ADD(x)		(x+=10)
#define SIZEOF(x)	(sizeof(x))
//#define KMK

#pragma endregion


void main()
{
#ifdef KMK
	cout << "KMK정의되었다." << endl;
#else
	cout << "KMK정의안됬다." << endl;
#endif

	cout << "MAX" << endl;
	cout << MAX << endl;

	int Num = 0;

	//Num += 10;
	ADD(Num);

	
	cout << sizeof(Num) << endl;
	cout << SIZEOF(int) << endl;
}