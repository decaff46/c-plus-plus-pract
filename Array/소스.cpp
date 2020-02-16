#include <iostream>
using namespace std;

/*
	배열

		동일한 자료형을 메모리에 연속적으로 선언하는 문법

	선언방법 : 선언시 개수는 상수만 넣을 수 있다.

		자료형 배열명[ 개수 ];

		ex) int A[5];
			int A[] = {0, 1, 2}; // 비추

	초기화
		
		자료형 배열명[ 개수 ] = { 값1, 값2, 값3.... };

		EX) int A[5];					//	5개 선언됬는데 다 쓰레기값
			int A[5] = {0, 1, 2, 3, 4 };
			int A[5] = {0, 2};			// { 0, 2, 0, 0, 0 };
			int A[5] = {};				// { 0, 0, 0, 0, 0 };

	요소 사용 : 인덱스는 0~ 시작

		배열명[인덱스]

		ex) cout << A[0] << endl;
			
			A[3] = 4;
*/

void main()
{
	int Array[10] = {};

	for (int i = 0; i < 10; i++)
	{
		Array[i] = i+1;
	}

	for (int i = 0 ; i < 10; i++)
	{
		cout << Array[i] << " " ;
	}
}