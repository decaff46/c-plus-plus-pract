#include <iostream>
using namespace std;

class ComplexNumber
{
public:
	float	m_realNum	= 0;
	float	m_imgNum	= 0;

	ComplexNumber	operator+(const ComplexNumber &_right)
	{
		ComplexNumber	result;

		result.m_realNum	= m_realNum + _right.m_realNum;
		result.m_imgNum		= m_imgNum	+ _right.m_imgNum;

		return result;
	}
	ComplexNumber	operator+(const float &_right)
	{
		ComplexNumber	result;

		result.m_realNum	= m_realNum + _right;
		result.m_imgNum		= m_imgNum;

		return result;
	}

	void	Out()
	{
		cout << m_realNum << " + " << m_imgNum << "i";
	}
};

int main()
{
	

	ComplexNumber	A = { 7, 2 };
	ComplexNumber	B = { 5, 3 };
	ComplexNumber	C;

	//	12 + 5i;
	C = A + B;
	C = A.operator+(B);
	C = A + 75.0f;

	
	string	a;

	a = "�ȳ�";
	a += "�ϼ���";
	if (a == "�ȳ��ϼ���")
	{

	}

	return 0;
}

/*
	����

		char 

	���ڿ�

		char �迭

		if( Name == "����" )	(x)		strcmp

		Name = "kor";			(x)		strcpy
		Name += "������";			(x)		strcat

	string
*/