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

	A = "�ȳ�";
	B.operator= (A);
	//B = "�ϼ���";

	B = A + "�ϼ���";
	C = A.operator+(B);


	C += "����";
	C += A;




	if (C == "�ȳ�")
	{
		cout << "����" << endl;
	}
	if (C != "�ϼ���")
	{
		cout << "�ٸ�" << endl;
	}
	if (C == A)
	{
		cout << "����" << endl;
	}
	if (C != A)
	{
		cout << "�ٸ�" << endl;
	}


	return 0;
}