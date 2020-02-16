#include <iostream>
using namespace std;

/*
	함수의 종류

		1. main함수
		2. 표준함수
		3. 사용자정의 함수

	사용자정의 자료형

		1. 표준 : int, short...
		2. 내가 만드는 자료형
		3. 관계된 변수를 하나의 자료형으로 묶는다.

	열거체

		1. 관계된 심볼릭 상수의 나열	const int MAX = 10;
		2. 연관성, 연속성

	enum	열거체명(생략가능)
	{ 
		INPUT,		//	최초 값이 생략되면 0으로
		DEL,		//	이전거의 +1
		ON,
		MODI = 3,	//	대입하면 그 값으로
		OUT,		//	이전거의 +1
		END
	};

	//	유지보수의 편의성과 가독성 상승


	/////////////////////////////////////////////////

	구조체

		1. 변수 묶음, 변수 가방
		2. 변수만 저장 가능, 함수(X) <- C...

	struct 구조체명
	{	
		int a;
		int b;
		shot c;
		float d;
		.
		.
	};

	구조체 선언

		구조체명	변수명;
	초기화
		구조체명	변수명 = { 순서대로 값 열거, , , };

	구조체 멤버변수의 사용

		. 연산자

			변수명.멤버변수명 = 값;

		-> 연산자

			구조체 포인터 변수일때

			(*변수명).멤버변수명 = 값;
			변수명->멤버변수명 = 값;

	구조체의 크기

		가장 큰 변수의 크기 단위로 박스처리 한다.
		빈 공간(패딩비트)이 발생할 수 있다.

	패딩비트 처리

		패딩비트가 없도록 짠다.
		구조체의 순서를 맞춘다.
		컴파일옵션으로 패딩비트를 제거한다.

/////////////////////////////////////////////////
	공용체

		구조체랑 완전 똑같은데, 메모리 공유

*/

union IP_Add
{
	int		Num;

	char	Add[4];
};

union Score
{
	struct
	{
			int Kor;
			int Math;
			int Eng;
	};

	int		Array[3];
};

enum EMENU
{
	INPUT = 0,
	OUTPUT,
	DELETE,
	MODI,
	END
};

struct Sample
{
	int		a;
	float	b;
	string	c;
	char	d[10];
};

struct SizeA
{
	int a;
};
struct SizeB
{
	int		a;	//4
	short	b;	//4
};

struct SizeC
{
	int		a;	//4
	short	b;	//4
	int		c;	//4
};

struct SizeD
{
	int		a;	//4
	short	b;	//4(2)
	char	c;	//4(1)
	int		d;	//4
};

struct SizeF 
{
};

struct SizeE
{
	int		a;	//4
	short	b;	//4(2)
	int		d;	//4
	char	c;	//4(1)
};

int main()
{
	cout << sizeof(SizeE) << endl;

	return 1;

	Score	Std;

	for (int i = 0; i < 3; i++)
	{
		cout << Std.Array[i] << "\t";
	}
	cout << endl;

	Std.Kor		= 100;
	Std.Math	= 93;

	////////////////////////////
	Sample	e;

	e.a = 10;

	cout << e.a << endl;

	return 0;

	EMENU	a;
	a = EMENU::INPUT;

	int Menu[END] = {};

	switch (a)
	{
	case INPUT:
		break;
	case OUTPUT:
		break;
	}

	return 0;
}