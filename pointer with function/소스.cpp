#include <iostream>
using namespace std;

/*
	�Լ� ������ -> funtion<> -> �ڶ��ٽ�

	�Լ� ������

		- ������ ����	: �ּ� ���� ����,������ �� �ִ� �޸� ����
		- �Լ� ������	: �Լ��� �ּ� ���� �����ϴ� ������
		- �Լ� ȣ��	: �Լ���(��) <- �Լ��� == �Լ�������

	�Լ� ������ �����

		��ȯ�ڷ���	(*�Լ������͸�)(�Ű������ڷ���.... );

		ex) 
		int Add( int a, int b );
		int (*Func)(int,int);
		Func = Add;

	�Լ� ������ ����

		�Ϲ� �Լ� ������
		Ŭ���� �Լ� ������ : ����Լ� �Լ�������

	�Լ� �������� ���

	
	������ ������ ������

		1. ����

		iut *p = &a;

		int(*Func)(int,int) = Add;
		Func = Add;


		2. ���
		//	*p == a;
		*p = 10;

		Func(10, 20);
	//////////////////////////////////////////////////////

		�Լ��������� ���

			1.	���� �ڵ带 ����ȭ ��Ű�� ���� => �ڵ� �帧�� ����˰����� �и�
				���ο� �ڵ��� ����, Ȯ�忡 �����ϴ�.

			2.	�ڵ��� �Ǹ� or ����
				���۱� : ���ӽ����̽�(std) + ���̺귯��(lib, dll)

				�ڵ� ������ �Ұ��� + ������� �ڵ� ����

		�Լ��������� Ȱ��о�

			�ھ����α׷� ������, �ü�� ������

	//////////////////////////////////////////////////////

	�Լ��������� ����� typedef �� �����ϱ� ���� ǥ��

	functional ���

	function<��ȯ�ڷ���(�Ű�����)>		�Լ��������ڷ���;

	///////////////////////////////////////////////////////

	������

		- 1ȸ�뿡 ������� �Լ�ȭ
		- ���� ó���� ������
			a.	Ŭ���� �������,����Լ��� ���ǹ�ȭ
			b.	�Լ������� Ŀ���͸���¡ �Ұ�

	������ �ذ�å : ���ٽ�

		- ���ٽ� : �̸��� ���� �Լ�, �ν���Ʈ �Լ�, �ڵ�� �Լ� ����

		- ���ٽ�
*/

#include <functional>

function<void(void)>	f;

//	
void	Kor()
{
	cout << "�ȳ��ϼ���" << endl;
}
void	Eng()
{
	cout << "Hello" << endl;
}
void	Cha()
{
	cout << "????" << endl;
}
void	Jan()
{
	cout << "������" << endl; 
}

void	Meet(int _type)
{
	switch(_type)
	{
	case 0:	Kor(); break;
	case 1:	Eng(); break;
	case 2: Cha(); break;
	case 3: Jan(); break;
	}
}
void	NewMeet(void(*_func)(void))
{
	_func();
}
void	NewMeetB(function<void(void)>	_f)
{
	_f();
}

/*
	dll ����

	*.cpp -> dll
	
*/

typedef	void(*FUNC)(void);

int Add(int a, int b)
{
	return a + b;
}

int main()
{
	if(false)
	{
		//	���� �� �ʱ�ȭ
		int(*Func)(int, int) = Add;
		//	����
		Func = Add;

		//	���
		int a = Func(10, 10);
	}
	
	Meet(0);

	/////////////////////////////////////////////

	FUNC	list[4]			= { Kor, Eng, Cha, Jan };
	void(*func[3])(void)	= { Kor, Eng, Cha };
	
	NewMeet(list[3]);

	func[3]();

	//////////////////////////////////////////////
	function<int(int, int)>	cf		= Add;
	function<void(void)>	f[4]	= { Kor, Eng, Cha, Jan };

	cout << cf(10, 20) << endl;

	NewMeetB(f[3]);

	return 0;
}