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
	//int Num = 100;
	//RFunc(Num);

	//cout << Num << endl;

	//PFunc(&Num);

	//cout << Num << endl;

	//int *pNum = &Num;

	//PFunc2(pNum);

	//cout << *pNum << endl;




	int  a = 10;
	int*  p = &a;
	int* *p2 = &p;
	int** *p3 = &p2;

	double       ****dp, dp2, **dp3, *******dp4;

	//cout << sizeof(dp) << endl;
	//cout << sizeof(dp2) << endl;

	cout << &a << endl;
	cout << p << endl;
	cout << **p2 << endl;
	cout << p3 << endl;  //  �̷��� ������ p3 �� �ڸ����� a�� �ڸ����� ���ƾ� ���� �ʳ�??



	int Array[5] = {};

	cout << &Array[1] << endl;
	cout << (Array + 1) << endl;

	// Array[n]

	//	*(Array+n)

	*(Array + 3) = 234;

	cout << Array[3] << endl;



	int firstvalue, secondvalue;
	int * mypointer;

	mypointer = &firstvalue;
	*mypointer = 10;
	mypointer = &secondvalue;
	*mypointer = 20;
	cout << "firstvalue is " << firstvalue << '\n';
	cout << "secondvalue is " << secondvalue << '\n';
	cout << *mypointer << '\n';


	int numbers[5];
	int * ptr;
	ptr = numbers;  
	*ptr = 10;
	ptr++;  
	*ptr = 20;
	ptr = &numbers[2];  
	*ptr = 30;
	ptr = numbers + 3;  
	*ptr = 40;
	ptr = numbers;  
	*(ptr + 4) = 50;

	for (int n = 0; n<5; n++)
		cout << numbers[n] << ", ";

}