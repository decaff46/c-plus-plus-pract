#include <iostream>
using namespace std;

/*
const 키워드

- 변수 선언시에 사용하는 키워드
- 쓰기불가 옵션

- 변수를 상수처럼 만드는 키워드
ex) const int MAX = 10;


포인터와 const 의 관계

int *p;

- 주안점 : *과 const 의 위치 관계( int 는 의미x )

A. const *p;		-> *p 상수다,	p 는 변수다.
B. * const p;		-> *p 변수,		p 가 상수다.
C. const * const p; -> *p 상수,		p 도 상수다.
*/
//	const 키워드는 원래부터 자료형이 아닌 변수에 붙이는 개념이다.
int const a = 10;
const int b = 20;

// ?
const int const c = 30;

char const *Ment = "KOR";

void main()
{
	Ment = "USA";

	//	x
	//	Ment[2] = 'B';

	int NumA = 10;
	int const *p = &NumA;

	cout << *p << endl;

	//*p = 30;
	NumA = 30;

	cout << *p << endl;

	int NumB = 100;

	// ok
	p = &NumB;
}