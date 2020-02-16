#include <iostream>
using namespace std;

int main()
{
	int		a[5];

	//	int	a int*


	char	String[10]		= "";
	char	StrArr[5][10]	= {};

	// char*	char**
	char	**ppStr = nullptr;

	ppStr = new char*[5];
	for (int i = 0; i < 5; i++)
	{
		ppStr[i] = new char[10];
	}

	////////////////////////////////////
	for (int i = 0; i < 5; i++)
	{
		delete[] ppStr[i];
	}
	delete[] ppStr;

	return 0;
}