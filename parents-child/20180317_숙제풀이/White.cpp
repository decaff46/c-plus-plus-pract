#include "White.h"
#include <iostream>
using namespace std;


White::White()
{
}


White::~White()
{
}

void White::TurnOn()
{
	cout << "백열등이 켜졌다." << endl;
}

void White::TurnOff()
{
	cout << "백열등이 꺼졌다." << endl;
}

void White::Name()
{
	cout << "백열등" << endl;
} 
