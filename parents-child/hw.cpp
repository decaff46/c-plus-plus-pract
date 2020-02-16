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
		cout << "전구를 낍니다" << endl;
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
		cout << "전등을 킵니다" << endl;
	}

	void off()
	{
		cout << "전등을 끕니다" << endl;
	}

	~Flash()
	{
		cout << endl;
		cout << "전구를 뺍니다" << endl;
	}
};

class Bulb
{
public:
	//순가상함수
	virtual void check () = 0;
	
	//오버라이딩
	virtual void start()
	{
		cout << "불이 켜집니다" << endl;
	}
};

class cWhite : public Bulb
{
	void check()
	{
		cout << "백열구" << endl;
	}

	void start()
	{
		cout << "백열구가 켜집니다" << endl;
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
		cout << "LED가 켜집니다" << endl;
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
		cout << "Oslam이 켜집니다" << endl;
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
