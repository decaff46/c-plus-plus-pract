#include <iostream>
#include <functional>
using namespace std;

class Temp
{
public:
	function<void(void)>	m_Func;
	function<void(int)>		m_Func2;

	void	Run()
	{
		m_Func();
	}
};

int main()
{
	//	함수포인터
	void(*pFunc)(void);

	//	함수 포인터처럼 사용하는 클래스
	function<void(void)>	func;

	auto Func = []	
	{	
		cout << "HelloWorld" << endl;	
	};

	Func();

	func	= Func;
	pFunc	= Func;

	func();
	pFunc();

	func = []
	{
		cout << "Hello2" << endl;
	};

	pFunc = []
	{
		cout << "Hello3" << endl;
	};

	Func();
	func();
	pFunc();

	//Func = []
	//{
	//	cout << "Hello3" << endl;
	//};

	///////////////////////////////////////////////////////////////////////////

	auto rAdd = [](int a, int b)->int
	{
		return a + b;
	};

	cout << rAdd(10, 20) << endl;

	int num = 0;

	[](int a, int b)->int
	{
		return a + b;
	}(10, 20);

	///////////////////////////////////////////////////////////////////////////

	Temp	A;
	int		sum			= 1;
	int		factorial	= 5;

	A.m_Func = [=, &sum]
	{
		for (int i = 1; i <= factorial; i++)
		{
			sum *= i;
		}
	};

	A.Run();

	cout << "sum : " << sum << endl;

	A.Run();

	cout << "sum : " << sum << endl;

	A.m_Func2 = [&sum](int _Dmg)
	{
		sum -= _Dmg;
	};

	A.m_Func2(100);

	cout << "sum : " << sum << endl;



	auto ram14 = [](auto a, auto b) -> auto
	{
		return a + b;
	};

	return 0;
}

////	이렇게 안됨, 이거 하려면 템플릿써야한다.
//auto	Sub(auto a, auto b)
//{
//	return a - b;
//}

/*
	람다식 : Java, C#, C++11

		이름없는 함수

		인스턴트 함수

	가장 심플한 람다

		[]
		{

		};


		함수명();

	람다를 정의하고 바로 실행하고 싶다.

		[]
		{

		}();

	제대로된 구조

		[캡처절](매개변수들) -> 반환자료형
		{
			코드
		};

	ex)

		[](int a, int b) -> int
		{
			return a + b;
		};

		int Add(int, int)

	//	캡처절
	
		람다구현위치보다 상위에 있는 지역변수를 참조할 수 있는 문법

		=, &

		= : 상위 모든 지역변수를 읽기만 가능
		& : 상위 모든 지역변수를 읽기/쓰기 가능

		int a = 0;
		int b = 0;
		int c = 0;

		
		[a]		//	a만 읽기가능
		[a,b]	//	a,b 만 읽기가능
		[&a]	//	a만 읽기/쓰기 가능
		[&a, b]	//	a는 읽기/쓰기, b는 읽기
		[=]		//	모든 상위 읽기
		[&]		//	모든 상위 읽기/쓰기
		[=, &a]	//	a는 읽기/쓰기, 나머지는 읽기만


		C++14

			일반화 람다 : 매개변수를 auto 사용 가능

*/