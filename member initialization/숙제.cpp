#include <iostream>
using namespace std;

class MyString
{
public:
	char	strBuf[256] = "";
	int		len = 0;
	
	void Out()
	{
		cout << strBuf << endl;
	}

	MyString operator=(char *Input)
	{
		//strcpy(strBuf,Input)
		MyString result; 
		int len = strlen(Input);
		for (int i = 0; i < len; i++)
		{
			result.strBuf[i] = Input[i];
		}
		return result;
	}

	MyString operator+(char *Input)
	{
		//strcat(strBuf,Input)
		MyString result;
		int len = strlen(Input);
		int mylen = strlen(strBuf);
		for (int i = 0; i < len + 1; i++)
		{
			strBuf[mylen + 1] = Input[i];
		}
		return result;
	}

	MyString operator+=(char *Input)
	{
		//strcat(strBuf,Input)
		MyString result;
		int len = strlen(Input);
		int mylen = strlen(strBuf);
		for (int i = 0; i < len + 1; i++)
		{
			strBuf[mylen + 1] = Input[i];
		}
		return result;
	}

	
	MyString operator==(char *Input)
	{
		//strcmp(strBuf,Input)
		MyString result;
		int len = strlen(strBuf);
		for (int i = 0; i < len + 1; i++)
		{
			if (result.strBuf[i] == Input[i])	continue;

			if (result.strBuf[i] > Input[i])	return +1;
			else								return -1;
		}
	}
	
	MyString operator!=(char *Input)
	{
		//strcmp(strBuf,Input)
		MyString result;
		int len = strlen(strBuf);
		for (int i = 0; i < len + 1; i++)
		{
			if (result.strBuf[i] == Input[i])	continue;

			if (result.strBuf[i] > Input[i])	return +1;
			else								return -1;
		}
	}

};


int main()
{
	MyString	A;
	MyString	B;
	MyString	C;

	A = "�ȳ�";
	B = A;

	B = A + "�ϼ���";
	C = A+B;


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