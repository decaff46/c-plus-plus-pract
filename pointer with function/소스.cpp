#include <iostream>
using namespace std;

/*
	함수 포인터 -> funtion<> -> ★람다식

	함수 포인터

		- 포인터 변수	: 주소 값을 저장,변경할 수 있는 메모리 공간
		- 함수 포인터	: 함수의 주소 값을 저장하는 포인터
		- 함수 호출	: 함수명(값) <- 함수명 == 함수포인터

	함수 포인터 선언법

		반환자료형	(*함수포인터명)(매개변수자료형.... );

		ex) 
		int Add( int a, int b );
		int (*Func)(int,int);
		Func = Add;

	함수 포인터 종류

		일반 함수 포인터
		클래스 함수 포인터 : 멤버함수 함수포인터

	함수 포인터의 사용

	
	포인터 변수와 차이점

		1. 선언

		iut *p = &a;

		int(*Func)(int,int) = Add;
		Func = Add;


		2. 사용
		//	*p == a;
		*p = 10;

		Func(10, 20);
	//////////////////////////////////////////////////////

		함수포인터의 사용

			1.	메인 코드를 정형화 시키는 목적 => 코드 흐름과 실행알고리즘의 분리
				새로운 코드의 적용, 확장에 유리하다.

			2.	코드의 판매 or 배포
				저작권 : 네임스페이스(std) + 라이브러리(lib, dll)

				코드 수정이 불가능 + 사용자의 코드 적용

		함수포인터의 활용분야

			코어프로그램 개발자, 운영체제 개발자

	//////////////////////////////////////////////////////

	함수포인터의 빈번한 typedef 를 지원하기 위한 표준

	functional 헤더

	function<반환자료형(매개변수)>		함수포인터자료형;

	///////////////////////////////////////////////////////

	문제점

		- 1회용에 관계없이 함수화
		- 변수 처리의 불편함
			a.	클래스 멤버변수,멤버함수의 무의미화
			b.	함수형태의 커스터마이징 불가

	문제의 해결책 : 람다식

		- 람다식 : 이름이 없는 함수, 인스턴트 함수, 코드상 함수 정의

		- 람다식
*/

#include <functional>

function<void(void)>	f;

//	
void	Kor()
{
	cout << "안녕하세요" << endl;
}
void	Eng()
{
	cout << "Hello" << endl;
}
void	Cha()
{
	cout << "????" << endl;
}
void	Jan()
{
	cout << "고니찌와" << endl; 
}

void	Meet(int _type)
{
	switch(_type)
	{
	case 0:	Kor(); break;
	case 1:	Eng(); break;
	case 2: Cha(); break;
	case 3: Jan(); break;
	}
}
void	NewMeet(void(*_func)(void))
{
	_func();
}
void	NewMeetB(function<void(void)>	_f)
{
	_f();
}

/*
	dll 파일

	*.cpp -> dll
	
*/

typedef	void(*FUNC)(void);

int Add(int a, int b)
{
	return a + b;
}

int main()
{
	if(false)
	{
		//	선언 및 초기화
		int(*Func)(int, int) = Add;
		//	대입
		Func = Add;

		//	사용
		int a = Func(10, 10);
	}
	
	Meet(0);

	/////////////////////////////////////////////

	FUNC	list[4]			= { Kor, Eng, Cha, Jan };
	void(*func[3])(void)	= { Kor, Eng, Cha };
	
	NewMeet(list[3]);

	func[3]();

	//////////////////////////////////////////////
	function<int(int, int)>	cf		= Add;
	function<void(void)>	f[4]	= { Kor, Eng, Cha, Jan };

	cout << cf(10, 20) << endl;

	NewMeetB(f[3]);

	return 0;
}