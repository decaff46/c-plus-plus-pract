#include <iostream>
using namespace std;

class Sample
{
public:
	//	�ɺ��� ���
	const	int COUNTMAX	=	10;	//	C++11 ���Ŀ� ����������.
			int	m_Array[5]	= { 0, 1, 2 };

	//	���۷��� ����
	float		m_Num	=	1000;
	float		&m_rNum =	m_Num;

public:
	Sample()
	:COUNTMAX(100)
	{

	}
	Sample(int _max)
	:COUNTMAX(_max)
	{

	}
	Sample(float &_Num)
	:m_rNum(_Num)
	{

	}

	//	������ ����
	Sample(int _num, int _num2)
	:Sample()
	{
		m_Num = _num * _num2 * 0.1f;
	}

	void Out()
	{
		cout << "MAX : " << COUNTMAX << endl;
	}
};

int main()
{
	int		num1 = 10;
	int		num2 = 10;
	//int		num3;

	//cout << num3 << endl;



	Sample	a;
	a.Out();

	Sample	b(20);
	b.Out();

	//	b. + (101);
	//	b  + 101

	int d = 0;

	float	num = 300;
	Sample	c(num);

	c.m_rNum = 1000;

	cout << num << endl;



	return 0;
}