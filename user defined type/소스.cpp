#include <iostream>
using namespace std;

/*
	�Լ��� ����

		1. main�Լ�
		2. ǥ���Լ�
		3. ��������� �Լ�

	��������� �ڷ���

		1. ǥ�� : int, short...
		2. ���� ����� �ڷ���
		3. ����� ������ �ϳ��� �ڷ������� ���´�.

	����ü

		1. ����� �ɺ��� ����� ����	const int MAX = 10;
		2. ������, ���Ӽ�

	enum	����ü��(��������)
	{ 
		INPUT,		//	���� ���� �����Ǹ� 0����
		DEL,		//	�������� +1
		ON,
		MODI = 3,	//	�����ϸ� �� ������
		OUT,		//	�������� +1
		END
	};

	//	���������� ���Ǽ��� ������ ���


	/////////////////////////////////////////////////

	����ü

		1. ���� ����, ���� ����
		2. ������ ���� ����, �Լ�(X) <- C...

	struct ����ü��
	{	
		int a;
		int b;
		shot c;
		float d;
		.
		.
	};

	����ü ����

		����ü��	������;
	�ʱ�ȭ
		����ü��	������ = { ������� �� ����, , , };

	����ü ��������� ���

		. ������

			������.��������� = ��;

		-> ������

			����ü ������ �����϶�

			(*������).��������� = ��;
			������->��������� = ��;

	����ü�� ũ��

		���� ū ������ ũ�� ������ �ڽ�ó�� �Ѵ�.
		�� ����(�е���Ʈ)�� �߻��� �� �ִ�.

	�е���Ʈ ó��

		�е���Ʈ�� ������ §��.
		����ü�� ������ �����.
		�����Ͽɼ����� �е���Ʈ�� �����Ѵ�.

/////////////////////////////////////////////////
	����ü

		����ü�� ���� �Ȱ�����, �޸� ����

*/

union IP_Add
{
	int		Num;

	char	Add[4];
};

union Score
{
	struct
	{
			int Kor;
			int Math;
			int Eng;
	};

	int		Array[3];
};

enum EMENU
{
	INPUT = 0,
	OUTPUT,
	DELETE,
	MODI,
	END
};

struct Sample
{
	int		a;
	float	b;
	string	c;
	char	d[10];
};

struct SizeA
{
	int a;
};
struct SizeB
{
	int		a;	//4
	short	b;	//4
};

struct SizeC
{
	int		a;	//4
	short	b;	//4
	int		c;	//4
};

struct SizeD
{
	int		a;	//4
	short	b;	//4(2)
	char	c;	//4(1)
	int		d;	//4
};

struct SizeF 
{
};

struct SizeE
{
	int		a;	//4
	short	b;	//4(2)
	int		d;	//4
	char	c;	//4(1)
};

int main()
{
	cout << sizeof(SizeE) << endl;

	return 1;

	Score	Std;

	for (int i = 0; i < 3; i++)
	{
		cout << Std.Array[i] << "\t";
	}
	cout << endl;

	Std.Kor		= 100;
	Std.Math	= 93;

	////////////////////////////
	Sample	e;

	e.a = 10;

	cout << e.a << endl;

	return 0;

	EMENU	a;
	a = EMENU::INPUT;

	int Menu[END] = {};

	switch (a)
	{
	case INPUT:
		break;
	case OUTPUT:
		break;
	}

	return 0;
}