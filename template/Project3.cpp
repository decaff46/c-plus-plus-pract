#include <iostream>
using namespace std;

/*
	템플릿

		- 컴파일러가 사용자 대신 오버로딩을 해주는 개념

		- 함수 오버로딩 :	반환타입에 관계없이 함수명은 같고, 매개변수가 다른 함수 정의법
		- 연산자 오버로딩...

		- 오버로딩 == 다의어

		int		add(int,	int)
		float	add(float,	float)


	일반화 프로그래밍 

		- 모든 타입에 변수에 대응되는 프로그래밍
		X add( X, X )

		X : 일반적인 개념 : 템플릿


		typdef 와 template의 차이

		typedef		는 타입의 별명
		template	은 타입의 일반화
*/

//	함수 설계도
template< typename T >
void output(T a)
{
	cout << a << endl;
}


//	클래스 템플릿

//	1. 멤버함수 템플릿
class TempA
{
	int m_num = 10;
public:
	template< typename T >
	void output(T a)
	{
		cout << m_num	<< endl;
		cout << a		<< endl;
	}

	template< typename T >
	void output2(T a);
};

template< typename T >
void TempA::output2(T a)
{
	cout << m_num << endl;
	cout << a << endl;
}

//	2. 멤버변수 템플릿
template < typename T >
class TempB
{
public:
	T	m_num;
};



////////////////////////////////////////////////

//	템플릿 주의점

//	1. 쓰기전까지는 오류를 체크하지 않는다.
template< typename T >
void FuncC(T a, T b)
{
	a.m_out = 32;
	a.m_num = new int;

	b += a;
}

struct Info
{
	int		m_out;
	int		*m_num;
};

// 2. 오류의 출력내용이 복잡하다.

int main()
{
	Info	info = {};

	FuncC(info, info);

	return 0;

	TempA	a;

	a.output("안녕");
	a.output(3.4);
	a.output2(1);

	TempB<int>		b;
	b.m_num = 10;

	TempB<float>	c = {};



	return 0;

	//	output<int>( int a )
	output(10);

	//
	output("korea");

	//output<int>(10.230f);

	output(10.230f);

    return 0;
}

