#include <iostream>
using namespace std;

/*
	typedef Ű����

		�ڷ����� ��Ī�� �����ϴ� Ű����

	reference ���� vs typedef Ű����

		reference�� "����" �� ����
		ex) int a;
			int &r = a;

		typedef�� "�ڷ���"�� ����

		ex) typedef int	COUNT;
			
			// int StudentCnt;
			COUNT	StudentCnt;

	typedef �뵵

		a. �ڷ����� ������ ǥ�� < �ٸ� ����� �ڵ带 ���� �� ���� ���� : ������ >
		b. �ڷ����� ������ ���� �ϱ� ���ؼ�...
		c. �����Ͱ��� Ư�������� �ڷ����� ����� ����...
*/ 
typedef short	COUNT, SINT, *PSINT, &RSINT;

//	PCNT	-> short �� ������ �ڷ���
typedef short	*PCNT;
typedef short	&RCNT;

//	PCNT -> short*
PCNT	p;

// ������ �ڷ����� ������ �����.
COUNT	a;
PCNT	b = &a;
RCNT	c = a;


//	int �� �������ϴ� -> short ���� �ٲ���.
//	short ����...max 32767...-> int  

//	a ������
void Func(int a);

//	a ������, �迭,��ü "ũ��" ���� 
void Func2(size_t a);

void main()
{
	COUNT		StudentCnt	= 10;
	//.
	//.
	//.
	COUNT		ArrayCnt = 20;
}