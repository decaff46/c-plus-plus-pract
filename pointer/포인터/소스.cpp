#include <iostream>
using namespace std;

/*
	������

		�ּҰ��� ������ �� �ִ� ����
	
	������ �ּҰ�
		& ������


	�Ϲݺ��� ����

		�ڷ��� ������ = �ʱ�ȭ��;

		�ڷ��� *������ = �ʱ�ȭ�ּҰ�;

	������

		*	�ش� �ּҰ��� ��ġ�� ����

		&	�ش� ������ �ּҰ�
*/

void RFunc(int &_Num)
{
	// int &_Num = Num;
	_Num += 100;
}
void PFunc(int *_pNum)
{
	// int *_pNum = &Num;
	*_pNum += 100;
}
void PFunc2(int *_pNum)
{
	_pNum = 0;
}

void main()
{
	int Num = 100;
	RFunc(Num);

	cout << Num << endl;

	PFunc(&Num);

	cout << Num << endl;

	int *pNum = &Num;

	PFunc2(pNum);


	return;

	int  a = 10;
	int*  p = &a;
	int* *p2 = &p;
	int** *p3 = &p2;

	double       ****dp, dp2, **dp3, *******dp4;

	cout << sizeof(dp) << endl;
	cout << sizeof(dp2) << endl;

	cout << &a << endl;
}