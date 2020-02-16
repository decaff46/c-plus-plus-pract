#include <iostream>
using namespace std;


// 1. ����� �Ǵµ� ���ġ�� �ϳ��� �ȳ����� ������ ����??
class MyStringB
{
public:
	char *strBuf = nullptr;
	int len = 0;


	// �ɹ� �Լ� ����
	MyStringB(const char *str)
	{
		len = strlen(str);
		strBuf = new char[len];
		strcpy_s(strBuf,len, str);
	}
	//���� ������
	MyStringB(const MyStringB& other)
	{
		len = strlen(other.strBuf);
		strBuf = new char[len];
		strcpy_s(strBuf,len, other.strBuf);
	}
	~MyStringB()
	{
		delete[] strBuf;
	}
	
	//������ ����
	MyStringB& operator=(const char *str)
	{
		len = strlen(str);
		strBuf = new char[len];
		strcpy_s(strBuf,len, str);

		return *this;
	}
	MyStringB& operator=(const MyStringB &str)
	{
		len = str.len;
		strBuf = new char[len];
		strcpy_s(strBuf, len, str.strBuf);

		return *this;
	}
	MyStringB& operator+=(const char *str)
	{
		len += strlen(str);
		char *Tmpstr = new char[len];
		strcpy_s(Tmpstr,len, strBuf);
		strcat_s(Tmpstr,len, str);
		delete[] strBuf;
		strBuf = Tmpstr;

		return *this;
	}
	MyStringB& operator+=(const MyStringB &str)
	{
		len += str.len;
		char *Tmpstr = new char[len];
		strcpy_s(Tmpstr, len, strBuf);
		strcat_s(Tmpstr, len, str.strBuf);
		delete[] strBuf;
		strBuf = Tmpstr;

		return *this;
	}
	MyStringB  operator+(const char *str)
	{
		len += strlen(str);
		char *Tmpstr = new char[len];
		strcpy_s(Tmpstr, len, strBuf);
		strcat_s(Tmpstr, len, str);
		MyStringB Result(Tmpstr);
		delete[] Tmpstr;

		return Result;
	}
	MyStringB  operator+(const MyStringB &str)
	{
		len += str.len;
		char *Tmpstr = new char[len];
		strcpy_s(Tmpstr, len, strBuf);
		strcat_s(Tmpstr, len, str.strBuf);
		MyStringB Result(Tmpstr);
		delete[] Tmpstr;

		return Result;
	}
	bool operator==(const char *str)
	{
		return (strcmp(strBuf, str) == 0);
	}
	bool operator==(const MyStringB &str)
	{
		return (strcmp(strBuf, str.strBuf) == 0);
	}
	bool operator!=(const char *str)
	{
		return (strcmp(strBuf, str) != 0);
	}
	bool operator!=(const MyStringB &str)
	{
		return (strcmp(strBuf, str.strBuf) != 0);
	}
};

std::ostream&	operator<< (std::ostream &_cout, const MyStringB &_right)
{
	cout << _right.strBuf;
	return _cout;
}

//std::istream&	operator>> (std::istream &_cin, MyStringB &_right)
//{
//	char str[100];
//	_cin >> str;
//	_right = MyStringB(strBuf);
//	return _cin;
//}


int main()
{

	MyStringB A = "Hey";
	MyStringB B = "What";
	MyStringB C = A + B;

	cout << A << endl;
	cout << B << endl;
	cout << C << endl;

	A += B;
	if (A == C)
	{
		cout << "same" << endl;
	}
	else 
	{
		cout << "No" << endl;
	}

	return 0;
}