#include <iostream>
using namespace std;

/*
	�ݺ���

		Ư�� ����� �ݺ��ϴ� ����
		������ ���� ��� �ݺ��� �����Ѵ�.

	while, do~while, for, foreach, range base for....


	while( ���� ) �ݺ��Ҹ��;

	while(����)
	{
		�ݺ��Ҹ��;
	}


	do
	{
		�ݺ��� ���;
	}while(����);
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