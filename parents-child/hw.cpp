#include<iostream>
#include<string>
using namespace std;

class Flash
{
	string socket;
	bool is_fit;

public: 
	Flash() 
	{
		cout << "������ ���ϴ�" << endl;
		cout << endl;
	}

	/*void set_type(const string s)
	{ 
		if (socket == s)
		{
			is_fit = true;
			on();
		}
		else
		{
			is_fit = false;
		}
	}*/

	void on()
	{
		cout << "������ ŵ�ϴ�" << endl;
	}

	void off()
	{
		cout << "������ ���ϴ�" << endl;
	}

	~Flash()
	{
		cout << endl;
		cout << "������ ���ϴ�" << endl;
	}
};

class Bulb
{
public:
	//�������Լ�
	virtual void check () = 0;
	
	//�������̵�
	virtual void start()
	{
		cout << "���� �����ϴ�" << endl;
	}
};

class cWhite : public Bulb
{
	void check()
	{
		cout << "�鿭��" << endl;
	}

	void start()
	{
		cout << "�鿭���� �����ϴ�" << endl;
	}
};

class cLED : public Bulb
{
	void check()
	{
		cout << "LED" << endl;
	}
	void start()
	{
		cout << "LED�� �����ϴ�" << endl;
	}
};

class cOslam : public Bulb
{
	void check()
	{
		cout << "Oslam" << endl;
	}
	void start()
	{
		cout << "Oslam�� �����ϴ�" << endl;
	}
};


int main()
{
	Flash		lamp;
	cWhite		White;
	cLED		LED;
	cOslam		Oslam;

	lamp.on();
	Bulb* types[3] = { &White , &LED ,&Oslam };

	for (int i = 0; i < 3; i++)
	{
		types[i]->check();
		types[i]->start();
	}



	return 0;
}
