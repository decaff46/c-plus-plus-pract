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



//	Ŭ���� ���ø�
//	1. ����Լ��� ���ø� �� ���
//		

//	2. ��������� ���ø� �� ���

//	����ü : ��������� �ڷ����߿� �ϳ��Դϴ�.

//	��������� �ڷ��� : ����ü, ����ü, ����ü, Ŭ����

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

		��ǻ�Ͱ� ��� �Լ������ε��� ���ִ� ����

		������ �ڷ����� ���� �Ű������� �����Ͽ� �Լ��� �ۼ��Ѵ�.

	template < typename T >
	T	Add( T a, T b )
	{
		return a+b;
	}


*/