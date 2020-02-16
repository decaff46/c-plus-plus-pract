#include <iostream>
using namespace std;

/*
	typedef 키워드

		자료형의 별칭을 지정하는 키워드

	reference 변수 vs typedef 키워드

		reference는 "변수" 의 별명
		ex) int a;
			int &r = a;

		typedef는 "자료형"의 별명

		ex) typedef int	COUNT;
			
			// int StudentCnt;
			COUNT	StudentCnt;

	typedef 용도

		a. 자료형의 목적을 표시 < 다른 사람이 코드를 봤을 때 쉽게 이해 : 가독성 >
		b. 자료형의 변경을 쉽게 하기 위해서...
		c. 포인터같은 특수형태의 자료형을 만들기 위해...
*/ 
typedef short	COUNT, SINT, *PSINT, &RSINT;

//	PCNT	-> short 형 포인터 자료형
typedef short	*PCNT;
typedef short	&RCNT;

//	PCNT -> short*
PCNT	p;

// 포인터 자료형의 차수를 낮춘다.
COUNT	a;
PCNT	b = &a;
RCNT	c = a;


//	int 가 부적절하다 -> short 으로 바꾸자.
//	short 시작...max 32767...-> int  

//	a 정수값
void Func(int a);

//	a 정수값, 배열,개체 "크기" 값을 
void Func2(size_t a);

void main()
{
	COUNT		StudentCnt	= 10;
	//.
	//.
	//.
	COUNT		ArrayCnt = 20;
}