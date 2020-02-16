#include "Arrow.h"
#include <iostream>
using namespace std;


Arrow::Arrow()
{
}


Arrow::~Arrow()
{
}

void Arrow::Attack()
{
	cout << "활을 쏩니다" << endl;
}

void Arrow::Defense()
{
	cout << "활을 방어합니다" << endl;
}

//void Arrow::Throw()
//{
//	cout << "활을 던집니다" << endl;
//}