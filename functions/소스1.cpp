#include <iostream>
using namespace std;

int TestA()
{
	cout << "TestAÇÔ¼ö" << endl;

	return 10;
}

void TestB(int Num)
{
	//	int Num;

	for (int i = 1; i < 10; i++)
	{
		cout << Num << " * " << i << " = " << Num * i << endl;
	}
	cout << endl;
}