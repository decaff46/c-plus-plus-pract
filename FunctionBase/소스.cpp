#include <iostream>
using namespace std;

/*
	�Լ�

		����� ����ü

	�Լ��� ����

		main�Լ�		:	���α׷��� ����
		ǥ���Լ�		:	rand�� srand ó��. �̹� ������� �Լ�
		����������Լ�	:	���� ����� �Լ�

	�Լ��� ����

		��ȯ�ڷ���		(�Լ�ȣ��Ծ�)		�Լ���( �Ű�������....  )
		{
			�Լ��� ��ü
		}

	�Լ��� ���

		�Լ���(�Ű������ʱ�ȭ��);

	return 

		�Լ��� ����, ��ȯ�ڷ����� ���� ��� return �ڿ� ���� ����� �Ѵ�.
*/

int Add(int a, int b)
{
	cout << "Add�Լ�" << endl;
	return a + b;
}

void Pow2(int a)
{
	a *= a;
}

// �迭���� ������ �迭��Ҹ� �����ϴ� ���� �����ϴ�.
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