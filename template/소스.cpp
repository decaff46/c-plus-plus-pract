#include <iostream>
using namespace std;

void output(int a)
{
	cout << "�Ϲ��Լ�" << endl;
}

template < typename T >
void output( T a )
{
	cout << "���ø�" << endl;
}

//	���ø� Ư��ȭ
template <>
void	output<int>(int a)
{
	cout << "Ư�����ø�" << endl;
}

//	�Լ� ȣ�� �켱����
//	�Ϲ��Լ� > Ư��ȭ���ø� > ���ø�

int main()
{
	output(1);
	//output(1.0f);
	//output('a');

	return 0;
}

/*
	���� �迭

	���ø����� �����.

	int �� �����迭
	float �� �����迭..


	1. �л� ����ǥ.... �����迭.... ���ø� �����迭�� ���� ��... �۵�
	2. �Լ������� <- ����
*/