#include <iostream>
using namespace std;

#include <Windows.h>

/*
	난수	:	사용자 알수없는 수, 난수표

	rand() 함수

		반환값으로 난수를 반환해준다.

		현재 설정된 시드번호에 해당하는 난수를 차례대로 반환한다.

		0 ~ 31767

	srand()

		() 안에 값을 대입하여 시드번호를 변경한다.

	범위난수

		rand() % N  ->  0 ~ N-1

		rnad() % (MAX-MIN+1) + MIN -> MIN <= X <= MAX
*/

void main()
{
	//시드번호설정
	srand( GetTickCount() );

	for (int i = 0; i < 10; i++)
	{
		// MIN <= X <= MAX
		int MAX = 5000;
		int MIN = 3;

		int X = rand() % (MAX - MIN + 1) + MIN;

		cout << X << endl;
	}

	cout << endl << endl;
	cout << "확율" << endl << endl;

	for (int i = 0; i < 10; i++)
	{

		if (rand() % 100 < 50)
		{
			cout << "조건발동" << endl;
		}
	}
}