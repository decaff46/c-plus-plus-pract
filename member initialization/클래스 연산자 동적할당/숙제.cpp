#include <iostream>
using namespace std;

//"a"(2), "sdad"(5), "asdkjhasjdhsa"
//		strBuf[256] 를 strBuf 포인터로 놓고 동적할당을 사용해라
//		깊은복사( 대입연산자, 복사생성자 )

class MyStringB
{
public:
	char	*m_strBuf	= nullptr;
	int		m_len		= 0;

	MyStringB ()
	{
		if (m_strBuf == nullptr)
		{
			m_strBuf = new char[m_len];
		}
	}
	
	MyStringB (const char *pInput)
	{
		m_len = strlen(pInput)+1;
		strcpy(m_strBuf, pInput);
	}
	
	MyStringB (const MyStringB &other)
	{
		m_len = other.m_len;
		strcpy(m_strBuf, other.m_strBuf);
	}
	
	~MyStringB()
	{
		delete[] m_strBuf;
	}

	void Out()
	{
		cout << m_strBuf << endl;
	}


	MyStringB& operator=(const MyStringB &_Right)
	{
		m_len = strlen(_Right.m_strBuf);
		strcpy(m_strBuf, _Right.m_strBuf);

		return *this;
	}

	MyStringB operator+(const char *Input)
	{
		MyStringB result;

		result.m_len = strlen(m_strBuf) + strlen(Input);

		strcpy(result.m_strBuf, m_strBuf);
		strcat(result.m_strBuf, Input);

		return result;
	}

	MyStringB& operator+=(const MyStringB &_Right)
	{
		m_len += strlen(_Right.m_strBuf);
		strcat(m_strBuf, _Right.m_strBuf);

		return *this;
	}

	bool operator==(const MyStringB &_Right)
	{
		return (strcmp(m_strBuf, _Right.m_strBuf) == 0);
	}

	bool operator!=(const MyStringB &_Right)
	{
		return (strcmp(m_strBuf, _Right.m_strBuf) != 0);
	}

};

class MyString
{
public:
	char	strBuf[256] = "";
	int		len = 0;
	
	void Out()
	{
		cout << strBuf << endl;
	}

	//	(a별명) += 10;
	//	a == 20
	//	a.operator=(10)
	MyString& operator=(const char *Input)
	{
		len = strlen(Input);
		strcpy_s(strBuf, 256, Input);

		return *this;
	}
	//	기본지원	A = B
	MyString& operator=(const MyString &_right)
	{
		len = strlen(_right.strBuf);
		strcpy_s(strBuf, 256, _right.strBuf);

		return *this;
	}


	//	1+2(3)
	//	a+b+d
	//	 c
	//	 c +d
	MyString operator+(const char *Input)
	{
		//strcat(strBuf,Input)
		MyString result;

		result.len = strlen(strBuf) + strlen(Input);
		
		strcpy_s(result.strBuf, 256, strBuf);
		strcat_s(result.strBuf, 256, Input);
		
		return result;
	}
	MyString operator+(const MyString &_right)
	{
		//strcat(strBuf,Input)
		MyString result;

		result.len = strlen(strBuf) + strlen(_right.strBuf);

		strcpy_s(result.strBuf, 256, strBuf);
		strcat_s(result.strBuf, 256, _right.strBuf);

		return result;
	}

	MyString& operator+=(const char *Input)
	{
		len += strlen(Input);
		strcat_s(strBuf, 256, Input);
		
		return *this;
	}
	MyString& operator+=(const MyString &_right)
	{
		len += strlen(_right.strBuf);
		strcat_s(strBuf, 256, _right.strBuf);

		return *this;
	}

	
	//	if( num == "kor" )
	bool operator==(const char *Input)
	{
		return (strcmp(strBuf, Input) == 0);
	}

	//	if( A == B )
	//bool operator==(MyString _right)
	bool operator==(const MyString &_right)
	{
		return (strcmp(strBuf, _right.strBuf) == 0);
		//return *this == _right.strBuf;
	}
	
	bool operator!=(const char *Input)
	{
		return (strcmp(strBuf, Input) != 0);
	}
	bool operator!=(const MyString &_right)
	{
		return (strcmp(strBuf, _right.strBuf) != 0);
	}
};

//	A+10 == 10+A
//	"선생님" + A
MyString	operator+(const char *_left, MyString &_right)
{
	MyString	Result;

	Result = _left;
	Result += _right;

	return Result;
}
//	cout << A
std::ostream&	operator<< (std::ostream &_cout, MyString &_right)
{
	cout << _right.strBuf;

	return _cout;
}

//void	DeleteSample() = delete;

int main()
{
	//DeleteSample();


	MyString	A;
	MyString	B;
	MyString	C;

	(A = "안녕") += "하세요";


	//A.Out();
	cout << A << endl;

	//	안녕하세요 선생님
	B = A + " 선생님";
	B.Out();

	//	선생님 안녕하세요
	B = "선생님 " + A;

	B.Out();

	C = "안녕";
	C += B;

	int			a;

	(a = 10) += 20;

	cout << a << endl;

	(a += 10) += 20;

	cout << a << endl;

	A = "안녕";

	B = A;	//	얕은복사, 기본대입연산자

	B = A + "하세요";
	C = A+B;


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

	//string	Temp = "kor";
	//char	strTemp[10] = "usa";
	//cout << strTemp << endl;
	////cout.operator<<(strTemp);
	//cout << strTemp;

	cout << 1 << 2 << 3 << endl;

	cout.operator<<(1).operator<<(2).operator<<(3);

	


	return 0;
}