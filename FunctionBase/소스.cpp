#include <iostream>
using namespace std;

/*
	함수

		명령의 집합체

	함수의 종류

		main함수		:	프로그램의 시작
		표준함수		:	rand나 srand 처럼. 이미 만들어진 함수
		사용자정의함수	:	내가 만드는 함수

	함수의 구성

		반환자료형		(함수호출규약)		함수명( 매개변수들....  )
		{
			함수의 본체
		}

	함수의 사용

		함수명(매개변수초기화값);

	return 

		함수의 종료, 반환자료형이 있을 경우 return 뒤에 값을 적어야 한다.
*/

int Add(int a, int b)
{
	cout << "Add함수" << endl;
	return a + b;
}

void Pow2(int a)
{
	a *= a;
}

// 배열명을 넣으면 배열요소를 변경하는 것은 가능하다.
void BaseArray(int Array[], int Size)
{
	for (int i = 0; i < Size; i++)
	{
		Array[i] = i;
	}
}

void main()
{
	int Sum = Add(10, 20);
	cout << Sum << endl;
	cout << Add(100, 22) << endl;

	//int a = Sum;
	Pow2(Sum);

	int A[5];

	BaseArray(A, 5);
}