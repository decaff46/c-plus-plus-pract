#include <iostream>
using namespace std;

//	����

/*
	�������� ����� ������ ������ ������ �� �����ȴ�.

	�����Ǹ�, ���� ������ ���Ұ�
*/

/*
	�޸� ����

		4����

		�ڵ�	����

		������	����	��������, ��������... ���

		����	����	�Ϲ������� ������ �����..

		��		����	���� �������� ����
		--------------------------------------------

	������ ����

		������������

			��������, ��������

		����������

			��������, �Ϲݺ���
*/
static int g_Num = 10;
int g_Num2 = 110;


void Test()
{
	// �Ϲ� ���� ����
	int a = 10;

	cout << a << endl;

	a++;
}
void TestB()
{
	// �Ϲ� ���� ����
	static int a = 10;

	cout << a << endl;

	a++;
}

void TestC();

//	
void main()
{
	TestC();
	TestC();
	TestC();
	TestC();
	TestC();
	TestC();

	return;

	int Num;

	{
		static int a = 10;

		cout << a << endl;
	}

	//cout << a << endl;

	int b = 10;

	{
		int b = 0;

		cout << b << endl;
	}

	cout << b << endl;
}