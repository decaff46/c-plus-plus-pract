#include <iostream>
using namespace std;

/*
	반복문

		특정 명령을 반복하는 문법
		조건이 참일 경우 반복을 지속한다.

	while, do~while, for, foreach, range base for....


	while( 조건 ) 반복할명령;

	while(조건)
	{
		반복할명령;
	}


	do
	{
		반복할 명령;
	}while(조건);
*/

void main()
{
	int i = 10;

	while (i <= 100)
	{
		cout << i << endl;

		i += 10;
	}

	//i = 0;

	while (i < 10)
	{
		cout << 10*(i+1) << endl;

		i++;
	}
}