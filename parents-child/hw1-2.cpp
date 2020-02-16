#include <iostream>
#include <string>
using namespace std;


//1. ���α׷����� �������� ����ϴ� ���α׷��� �����.
//2. �������� On, Off, SocketChange �� 3���� ����� ����� �� �� �ִ�.
//3. ������ ������ 3������ �ִ�.


class cBulb
{
public:
	//�������Լ�
	virtual void check() = 0;

	//�������̵�
	virtual void start()
	{
		cout << "���� �����ϴ�" << endl;
	}
};

class cWhite : public cBulb
{
	void check()
	{
		cout << "�鿭�� ����" << endl;
	}

	void start()
	{
		cout << "�鿭���� �����ϴ�" << endl;
	}
};

class cLED : public cBulb
{
	void check()
	{
		cout << "LED ����" << endl;
	}
	void start()
	{
		cout << "LED�� �����ϴ�" << endl;
	}
};

class cOslam : public cBulb
{
	void check()
	{
		cout << "Oslam ����" << endl;
	}
	void start()
	{
		cout << "Oslam�� �����ϴ�" << endl;
	}
};

class cProgram
{
public:
	cWhite	White;
	cLED	Led;
	cOslam	Oslam;
	cBulb*	bulb[3] = { &White, &Led, &Oslam };
	
	bool is_on = true;

	cProgram()
	{
		cout << "���α׷� ����" << endl;
	}

	void start()
	{
		int Input = 0;

		while (is_on)
		{
			cout << " 1. ���� �ѱ�" << endl;
			cout << " 2. ���� ����" << endl;
			cout << " 3. ���� ��ü" << endl;
			cout << "���ϴ� ��ȣ�� �����ϼ���   : ";
			cin >> Input;

			switch (Input)
			{
			case 1: On();			break;
			case 2: Off();			break;
			case 3: Switch();		break;
			}
		}
	}

	void On()
	{
		cout << "������ ŵ�ϴ�" << endl<< endl;
		Select();

	}
	void Off()
	{
		cout << "������ ���ϴ�" << endl;
		is_on = false;
	}
	void Switch()
	{
		cout << "��� ���ϴ�" << endl<< endl;
		Select();
	}

	void Select()
	{
		int input = 0;
		cout << "���� ����" << endl;
		cout << "1.�鿭��" << endl;
		cout << "2.LED" << endl;
		cout << "3.Oslam" << endl;
		cout << "���ϴ� ��ȣ�� �����ϼ���   : ";
		cin >> input;

		switch (input)
		{
		case 1: bulb[input-1]->check();		bulb[input - 1]->start();	cout << endl;	break;
		case 2: bulb[input-1]->check();		bulb[input - 1]->start();	cout << endl;	break;
		case 3: bulb[input-1]->check();		bulb[input - 1]->start();	cout << endl;	break;
		}
	}

	~cProgram()
	{
		cout << "���α׷� ����" << endl;
	}
};

int main()
{

	cProgram program;
	program.start();
	
	return 0;
}