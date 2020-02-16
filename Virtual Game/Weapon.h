#pragma once
#include <iostream>
using namespace std;


class Weapon 
{
public:
	virtual ~Weapon() = default;

	virtual void Attack() = 0;
	virtual void Defense() = 0;
	virtual void Throw()
	{
		cout << "���⸦ �����ϴ�" << endl;
	}
};

