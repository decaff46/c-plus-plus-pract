#include <iostream>
using namespace std;


void main()
{
	int a[] = { 1, 2, 3, 4 };
	int k = 1;

	for (int i = 0; i < 100; i++)
	{
		if (a[i] == k)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	

}
