#include <iostream>
using namespace std;

#include <Windows.h>

/*
	����	:	����� �˼����� ��, ����ǥ

	rand() �Լ�

		��ȯ������ ������ ��ȯ���ش�.

		���� ������ �õ��ȣ�� �ش��ϴ� ������ ���ʴ�� ��ȯ�Ѵ�.

		0 ~ 31767

	srand()

		() �ȿ� ���� �����Ͽ� �õ��ȣ�� �����Ѵ�.

	��������

		rand() % N  ->  0 ~ N-1

		rnad() % (MAX-MIN+1) + MIN -> MIN <= X <= MAX
*/

void main()
{
	//�õ��ȣ����
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
	cout << "Ȯ��" << endl << endl;

	for (int i = 0; i < 10; i++)
	{

		if (rand() % 100 < 50)
		{
			cout << "���ǹߵ�" << endl;
		}
	}
}