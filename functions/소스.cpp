#include <iostream>
using namespace std;

/*
	����

		�������

	�迭
		
		���� ������ ��������


	�Լ�

		�ڵ��� ����, ����� ����

		�̼�A, �÷�B

	�Լ��� ����

		��ȯŸ��	�Լ���( �Ű����� )
		{
			�Լ��ٵ�
		}

	��ȯŸ��

		���ƿ� �� ������ ������ ��

		void ����

	return

		�Լ��� ���� Ű���� ��ȯ�� ��� �ʿ�

		ex) return 10;, return;

	������Ÿ��

	�Ű�����

		�Լ� ������ ����

		Call by Value

		TestB(4);
		int Num = 4;

		TestB(Count);
		int Num = Count;

		Call by Reference

		���۷��������� �Ű������� ����� �Լ�ȣ��
*/
/*
	�Լ������ε�

		��ȯŸ�Կ� �������
		�Լ����� ����,
		�Ű������� �ٸ� �Լ� ���ǹ�

	����Ʈ �Ű�����
*/


// dx39_d.dll
// game.exe

//	������Ÿ��
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

	cout << "Main ����" << endl;

	int Num = TestA();

	// ���۷��� ����
	int &rNum = Num;

	//	�Ϲ� ����
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
