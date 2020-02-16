#include <iostream>
using namespace std;

/*
포인터

주소값을 저장할 수 있는 변수

변수의 주소값
& 연산자


일반변수 선언

자료형 변수명 = 초기화값;

자료형 *변수명 = 초기화주소값;

연산자

*	해당 주소값에 위치한 변수

&	해당 변수의 주소값
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
	cout << p3 << endl;  //  이렇게 했을때 p3 의 자리값과 a의 자리값은 같아야 하지 않나??



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