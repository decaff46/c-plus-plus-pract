#include <iostream>
using namespace std;

class Sample
{
public:
	int m_Num = 10;

public:
	template < typename T >
	T	Add(T a, T b)
	{
		return a + b;
	}
};

template <typename T>
class SampleB
{
public:
	T	m_Num;
};



//	클래스 템플릿
//	1. 멤버함수가 템플릿 인 경우
//		

//	2. 멤버변수가 템플릿 인 경우

//	구조체 : 사용자정의 자료형중에 하나입니다.

//	사용자정의 자료형 : 열거체, 구조체, 공용체, 클래스

struct StdInfo
{
	int Kor;
	int Math;
	int Eng;
};

int main()
{
	//MyVector<StdInfo>	StdData;

	Sample	a;
	Sample	b;
	//	int Sample::Add(int, int);
	a.Add(10, 20);
	//	float Sample::Add(float, float);
	a.Add(10.0f, 23.3f);

	cout << a.Add<char>(30, 40) << endl;

	SampleB<int>		b;
	//b.m_Num
	SampleB<float>		c;
	//c.m_Num
	SampleB<StdInfo>	d;
	d.m_Num.Math = 10;

	return 0;
}

/*
	template

		컴퓨터가 대신 함수오버로딩을 해주는 문법

		임의의 자료형을 가진 매개변수를 설정하여 함수를 작성한다.

	template < typename T >
	T	Add( T a, T b )
	{
		return a+b;
	}


*/