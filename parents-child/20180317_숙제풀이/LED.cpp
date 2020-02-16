#include "LED.h"
#include <iostream>
using namespace std;

LED::LED()
{
}


LED::~LED()
{
}

void LED::TurnOn()
{
	cout << "LED 가 켜졌다." << endl;
}

void LED::TurnOff()
{
	cout << "LED 가 꺼졌다." << endl;
}

void LED::Name()
{
	cout << "LED" << endl;
}
