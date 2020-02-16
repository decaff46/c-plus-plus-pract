#include <iostream>
using namespace std;

/*
	변수

		저장공간

	배열
		
		같은 형태의 변수묶음


	함수

		코드의 집합, 명령의 모음

		미션A, 플랜B

	함수의 구성

		반환타입	함수명( 매개변수 )
		{
			함수바디
		}

	반환타입

		돌아올 때 가지고 나오는 값

		void 가능

	return

		함수의 종료 키워드 반환값 명시 필요

		ex) return 10;, return;

	프로토타입

	매개변수

		함수 내부의 변수

		Call by Value

		TestB(4);
		int Num = 4;

		TestB(Count);
		int Num = Count;

		Call by Reference

		레퍼런스변수를 매개변수로 사용한 함수호출
*/
/*
	함수오버로딩

		반환타입에 관계없이
		함수명은 같고,
		매개변수가 다른 함수 정의법

	디폴트 매개변수
*/


// dx39_d.dll
// game.exe

//	프로토타입
void	TestB(int Num = 5);
int		TestA();

void	Pow2(int &rNum)
{
	rNum *= rNum;

	rNum = 0;
}
void	Pow2(int rNum)
{
	rNum *= rNum;

	rNum = 0;
}

void	Pow2B()
{

}
int		Pow2B(int Num = 10)
{
	int Result = Num*Num;

	Num = 0;

	return Result;
}
float	Pow2B(float Num)
{
	return Num*Num;
}
float	Pow2B(float Num, int Count)
{
	return Num*Num;
}

void Default(int a = 10, int b = 20, int c = 30)
{

}

void main()
{
	Default();
	TestB();

	cout << "Main 시작" << endl;

	int Num = TestA();

	// 레퍼런스 변수
	int &rNum = Num;

	//	일반 변수
	int Count = Num;

	TestA();
	TestA();
	TestA();
	TestA();

	TestB(4);
	TestB(6);

	// int &rNum = Count;
	//Pow2(Count);

	Count = Pow2B(Count);
}
