#include <iostream>
using namespace std;

// 배열 과 포인터

// 배열의 이름 : 상수포인터, 모배열, 배열상수

void main()
{
	int Array[5] = {};

	cout << &Array[1] << endl;
	cout << (Array + 1) << endl;

	// Array[n]

	//	*(Array+n)

	*(Array + 3) = 234;

	cout << Array[3] << endl;
}