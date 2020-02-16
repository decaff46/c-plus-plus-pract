#include <iostream>
using namespace std;

//"a"(2), "sdad"(5), "asdkjhasjdhsa"
//		strBuf[256] 를 strBuf 포인터로 놓고 동적할당을 사용해라
//		깊은복사( 대입연산자, 복사생성자 )




//질문 1. 연선자에서 매번 동적할당을 제거 하고 할 필요가 있나?
//질문 2. 10+ A형태가 맴버 함수가 될 수 없는 이유
//질문 3. cout << _right.m_strBuf 다시 한번 설명
//질문 4. 	C = A + B; 가 MyString &_Right이 아닌 char *pInput즉, 포인터 형태로 했을때는 오류가 난다?
//질문 5. strcpy_s를 꼭 써야 한다고?
//질문 6. 		result = new char[m_len-1];//왜 -1??ㄹ
//질문 7. return *this 가 객체 자신을 리턴한다>
class MyStringB
{
public:	
	char	*m_strBuf = nullptr;
	int		m_len = 0;
	
public:
	
	//생정자 생성 및 동적할당
	MyStringB();
	MyStringB(const char *pInput)
	{
		m_len = strlen(pInput)+1;
		m_strBuf = new char[m_len];
		strcpy_s(m_strBuf, m_len, pInput);
	}
	~MyStringB()
	{
		delete[] m_strBuf;
	}

	//복사 생성자 
	MyStringB(const MyStringB &other)
	{
		//m_len = other.m_len;
		m_len = strlen(other.m_strBuf);
		m_strBuf = new char[m_len];
		strcpy_s(m_strBuf, m_len, other.m_strBuf);
	}
	void Out()
	{
		cout << m_strBuf << endl;
	}

	//대입연산자 구연
	MyStringB& operator=(const MyStringB &_Right)
	{
		delete[] m_strBuf;
		m_len = strlen(_Right.m_strBuf);
		m_strBuf = new char[m_len];
		strcpy_s(m_strBuf, m_len, _Right.m_strBuf);

		return *this;
	}

	MyStringB operator+(const MyStringB &_Right)
	{
		m_len += strlen(_Right.m_strBuf);
		char *result;
		result = new char[m_len-1];//왜 -1??
		strcpy_s(result,m_len, m_strBuf);
		strcat_s(result,m_len, _Right.m_strBuf);
		MyStringB Result(result);
		delete[] result;
		return Result;
	}

	MyStringB& operator+=(const MyStringB &_Right)
	{
		m_len += strlen(_Right.m_strBuf);
		char *result = new char[m_len-1];
		strcpy_s(result, m_len, m_strBuf);
		delete[] m_strBuf;
		strcat_s(result, m_len, _Right.m_strBuf);
		m_strBuf = result;
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

// 어제 분명 들었는데 ~ 이게 맴버 함수가 될 수 없는 이유가 뭐지>
MyStringB	operator+(const char *_left, MyStringB &_right)
{
	MyStringB	Result;

	Result = _left;
	Result += _right;

	return Result;
}

std::ostream&	operator<< (std::ostream &_cout, const MyStringB &_right)
{
	cout << _right.m_strBuf;
	return _cout;
}

//std::istream&	operator>> (std::istream &_cin, MyStringB &_RIght)
//{
//	/*int temp_len = strlen(_RIght.m_strBuf);
//	char *temp = new char[temp_len];*/
//	char str[100];
//	cin >> str;
//	_RIght = MyStringB();
//	return cin;
//}



int main()
{

	MyStringB	A;
	MyStringB	B;
	MyStringB	C;

	(A = "안녕") += "하세요";

	//cout << A << endl;
	A.Out();
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
	C = A + B;


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