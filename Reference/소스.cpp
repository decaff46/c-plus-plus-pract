#include <iostream>
using namespace std;

/*
	���۷��� ����

		������ ������ ��Ī�� �ο��Ͽ� ����ϴ� ����

		�ʱ�ȭ�� �ʼ������� �ؾ��Ѵ�.

	���۷��� ����

		�ڷ��� &������ = ����������;

		ex) int &rNum = Num;
			rNum = 10;
*/

void Pow2(int &rNum)
{
	rNum *= rNum;
}

void main()
{
	int Num = 10;
	int &rNum = Num;

	rNum = 100;

	cout << Num << endl;

	// int &rNum = Num;
	Pow2(Num);
	cout << Num << endl;
}