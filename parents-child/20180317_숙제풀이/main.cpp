#include <iostream>
using namespace std;

/*
	����

		ĳ����

			����, ���

		����

			��, Ȱ, â


		���� �߰�	: ����
		ĳ���� �ൿ : ���������
		-------------------------------------------

	����

		���ø�

		2���� : �Լ� ���ø�, Ŭ���� ���ø�
*/

/*
	�������� ����

		1. ���� ����κ�( �������̽� ) �� �������� �ʰ� �߰����� �����ϴ�.
		2. �������̽��� �߰��Ҷ��� 1���� �߰��ϸ� �ȴ�.

	�������� ����

		1.	������ �����ϴ�.
		2.	�ӵ��� ��������� ������.
*/

//	������ �����
//	�ѱ�, ����, ���� ��ü
//	�鿭��, LED, ������
#include "Lamp.h"


int main()
{
	int		input		= 0;
	bool	isPlaying	= true;
	Lamp	lamp;

	while (isPlaying)
	{
		cout << "0. ������" << endl;
		cout << "1. �ѱ�" << endl;
		cout << "2. ����" << endl;
		cout << "3. ��ü" << endl;
		cout << "4. ȭ��û��" << endl;
		cout << "�Է� : ";
		cin >> input;

		switch (input)
		{
		case 0:	lamp.Name();	break;
		case 1:	lamp.TurnOn();	break;
		case 2:	lamp.TurnOff();	break;

		case 3:
		{
			cout << "���� ���� ����" << endl;
			cout << "0. �鿭��" << endl;
			cout << "1. LED" << endl;
			cout << "2. ������" << endl;
			cout << "3. ��Ÿ��" << endl;
			cin >> input;

			lamp.ChangeBulb(input);
		}break;
		case 4: system("cls");	break;
		}
	}
	return 0;
}