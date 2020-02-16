#include <iostream>
using namespace std;

class MyString
{
public:
	char	strBuf[256] = "";
	int		len = 0;

	void Out()
	{
		for (int i = 0; i != len; i++)
		{
			cout << strBuf[i];
		}
	}

	MyString operator=(char *Input)
	{
		strcpy(strBuf, Input);
	}

	MyString operator+(char *Input)
	{
		strcat(strBuf, Input);
	}

	MyString operator+=(char *Input)
	{
		strcat(strBuf, Input);
	}


	MyString operator==(char *Input)
	{
		strcmp(strBuf, Input);
	}

	MyString operator!=(char *Input)
	{
		strcmp(strBuf, Input);
	}

};


int main()
{
	MyString	A;
	MyString	B;
	MyString	C;

	A = "안녕";
	B.operator= (A);
	//B = "하세요";

	B = A + "하세요";
	C = A.operator+(B);


	C += "ㅇㅋ";
	C += A;




	if (C == "안녕")
	{
		cout << "같음" << endl;
	}
	if (C != "하세요")
	{
		cout << "다름" << endl;
	}
	if (C == A)
	{
		cout << "같음" << endl;
	}
	if (C != A)
	{
		cout << "다름" << endl;
	}


	return 0;
}