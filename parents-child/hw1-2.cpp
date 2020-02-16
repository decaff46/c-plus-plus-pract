#include <iostream>
#include <string>
using namespace std;


//1. 프로그램으로 손전등을 사용하는 프로그램을 만든다.
//2. 손전등은 On, Off, SocketChange 의 3가지 기능을 사용을 할 수 있다.
//3. 전구의 종류는 3가지가 있다.


class cBulb
{
public:
	//순가상함수
	virtual void check() = 0;

	//오버라이딩
	virtual void start()
	{
		cout << "불이 켜집니다" << endl;
	}
};

class cWhite : public cBulb
{
	void check()
	{
		cout << "백열구 선택" << endl;
	}

	void start()
	{
		cout << "백열구가 켜집니다" << endl;
	}
};

class cLED : public cBulb
{
	void check()
	{
		cout << "LED 선택" << endl;
	}
	void start()
	{
		cout << "LED가 켜집니다" << endl;
	}
};

class cOslam : public cBulb
{
	void check()
	{
		cout << "Oslam 선택" << endl;
	}
	void start()
	{
		cout << "Oslam이 켜집니다" << endl;
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
		cout << "프로그램 시작" << endl;
	}

	void start()
	{
		int Input = 0;

		while (is_on)
		{
			cout << " 1. 전등 켜기" << endl;
			cout << " 2. 전등 끄기" << endl;
			cout << " 3. 전구 교체" << endl;
			cout << "원하는 번호를 선택하세요   : ";
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
		cout << "전등을 킵니다" << endl<< endl;
		Select();

	}
	void Off()
	{
		cout << "전등을 끕니다" << endl;
		is_on = false;
	}
	void Switch()
	{
		cout << "전등를 갑니다" << endl<< endl;
		Select();
	}

	void Select()
	{
		int input = 0;
		cout << "전구 선택" << endl;
		cout << "1.백열구" << endl;
		cout << "2.LED" << endl;
		cout << "3.Oslam" << endl;
		cout << "원하는 번호를 선택하세요   : ";
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
		cout << "프로그램 종료" << endl;
	}
};

int main()
{

	cProgram program;
	program.start();
	
	return 0;
}