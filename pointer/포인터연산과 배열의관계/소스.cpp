#include <iostream>
using namespace std;

// �迭 �� ������

// �迭�� �̸� : ���������, ��迭, �迭���

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