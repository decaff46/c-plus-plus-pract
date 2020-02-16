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
	//	�Լ�������
	void(*pFunc)(void);

	//	�Լ� ������ó�� ����ϴ� Ŭ����
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

////	�̷��� �ȵ�, �̰� �Ϸ��� ���ø�����Ѵ�.
//auto	Sub(auto a, auto b)
//{
//	return a - b;
//}

/*
	���ٽ� : Java, C#, C++11

		�̸����� �Լ�

		�ν���Ʈ �Լ�

	���� ������ ����

		[]
		{

		};


		�Լ���();

	���ٸ� �����ϰ� �ٷ� �����ϰ� �ʹ�.

		[]
		{

		}();

	����ε� ����

		[ĸó��](�Ű�������) -> ��ȯ�ڷ���
		{
			�ڵ�
		};

	ex)

		[](int a, int b) -> int
		{
			return a + b;
		};

		int Add(int, int)

	//	ĸó��
	
		���ٱ�����ġ���� ������ �ִ� ���������� ������ �� �ִ� ����

		=, &

		= : ���� ��� ���������� �б⸸ ����
		& : ���� ��� ���������� �б�/���� ����

		int a = 0;
		int b = 0;
		int c = 0;

		
		[a]		//	a�� �бⰡ��
		[a,b]	//	a,b �� �бⰡ��
		[&a]	//	a�� �б�/���� ����
		[&a, b]	//	a�� �б�/����, b�� �б�
		[=]		//	��� ���� �б�
		[&]		//	��� ���� �б�/����
		[=, &a]	//	a�� �б�/����, �������� �б⸸


		C++14

			�Ϲ�ȭ ���� : �Ű������� auto ��� ����

*/