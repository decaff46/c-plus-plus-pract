#include "MyString.h"


MyString::MyString() {}
MyString::MyString(DataType str)
{
	strBuf = new DataType[1];
	strBuf[0] = str;
	len = 1;
	capa = 1;
}
MyString::MyString(const DataType *str)
{
	len = strlen(str);
	capa = len + 1;
	strBuf = new DataType[len + 1];
	strcpy_s(strBuf, len + 1, str);
}
//:MyString(DataType *str)  이거 방법이 어떻게 됐지?
MyString::MyString(const MyString &_other)
{
	len = _other.len;
	strBuf = new DataType[len + 1];
	strcpy_s(strBuf, len + 1, _other.strBuf);
}
MyString::~MyString()
{
	delete[] strBuf;
}

int MyString::Length()
{
	return len;
}
int MyString::Capacity()
{
	return capa;
}
void MyString::Out()
{
	for (int i = 0; i < len; i++)
	{
		cout << strBuf[i];
	}
	cout << endl;
}


MyString& MyString::operator= (const MyString &_right)
{
	if (_right.len > capa)
	{
		delete[] strBuf;
		strBuf = new DataType[_right.len];
		capa = _right.len;
	}
	len = _right.len;
	strcpy_s(strBuf, len + 1, _right.strBuf);

	return *this;
}
// 위에꺼 그대로 사용하는 방법이 뭐였지?
MyString& MyString::operator= (const DataType *s)
{
	int str_len = strlen(s);
	if (str_len > capa)
	{
		delete[] strBuf;
		capa = str_len + 1;
		strBuf = new DataType[capa];
	}
	len = str_len;
	strcpy_s(strBuf, len + 1, s);

	return *this;
}

MyString& MyString::operator+=(const MyString &_right)
{
	len += _right.len;

	capa = len;
	DataType *Temp = new DataType[len + 1];
	strcpy_s(Temp, len + 1, strBuf);
	delete[] strBuf;
	strcat_s(Temp, len + 1, _right.strBuf);
	strBuf = Temp;
	capa = len;

	return *this;
}
MyString& MyString::operator+=(const DataType *s)
{
	len += strlen(s);
	capa = len;
	DataType *Temp = new DataType[len + 1];
	strcpy_s(Temp, len + 1, strBuf);
	delete[] strBuf;
	strcat_s(Temp, len + 1, s);
	strBuf = Temp;
	capa = len;

	return *this;
}

MyString  MyString::operator+ (const MyString &_right)
{
	len += _right.len;
	DataType *temp = new DataType[len + 1];
	strcpy_s(temp, strlen(strBuf), strBuf);
	strcat_s(temp, _right.len, _right.strBuf);
	MyString result(temp);
	return result;
}
MyString  MyString::operator+ (const DataType *s)
{
	len += strlen(s);
	DataType *temp = new DataType[len + 1];
	strcpy_s(temp, len + 1, strBuf);
	strcat_s(temp, len + 1, s);
	MyString result(temp);
	return result;
}

bool MyString:: operator == (const MyString &_right)
{
	return strcmp(strBuf, _right.strBuf) == 0;
}
bool MyString:: operator != (const MyString &_right)
{
	return strcmp(strBuf, _right.strBuf) != 0;
}


MyString operator+(const DataType *_left, MyString &_right)
{
	MyString	Result;

	Result = _left;
	Result += _right;

	return Result;
}
std::ostream&	operator << (std::ostream &_cout, MyString &_right)
{
	cout << _right.strBuf;

	return _cout;
}
std::istream&   operator >> (std::istream &_cin, MyString &_right)
{
	char temp[256];
	_cin >> temp;
	_right = MyString(temp);
	return _cin;
}


DataType & MyString::operator[](int n)
{
	return strBuf[n];
}
