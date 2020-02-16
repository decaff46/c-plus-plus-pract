#include <iostream>
using namespace std;

//"a"(2), "sdad"(5), "asdkjhasjdhsa"
//		strBuf[256] �� strBuf �����ͷ� ���� �����Ҵ��� ����ض�
//		��������( ���Կ�����, ��������� )




//���� 1. �����ڿ��� �Ź� �����Ҵ��� ���� �ϰ� �� �ʿ䰡 �ֳ�?
//���� 2. 10+ A���°� �ɹ� �Լ��� �� �� ���� ����
//���� 3. cout << _right.m_strBuf �ٽ� �ѹ� ����
//���� 4. 	C = A + B; �� MyString &_Right�� �ƴ� char *pInput��, ������ ���·� �������� ������ ����?
//���� 5. strcpy_s�� �� ��� �Ѵٰ�?
//���� 6. 		result = new char[m_len-1];//�� -1??��
//���� 7. return *this �� ��ü �ڽ��� �����Ѵ�>
class MyStringB
{
public:	
	char	*m_strBuf = nullptr;
	int		m_len = 0;
	
public:
	
	//������ ���� �� �����Ҵ�
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

	//���� ������ 
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

	//���Կ����� ����
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
		result = new char[m_len-1];//�� -1??
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

// ���� �и� ����µ� ~ �̰� �ɹ� �Լ��� �� �� ���� ������ ����>
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

	(A = "�ȳ�") += "�ϼ���";

	//cout << A << endl;
	A.Out();
	//	�ȳ��ϼ��� ������
	B = A + " ������";
	B.Out();

	//	������ �ȳ��ϼ���
	B = "������ " + A;

	B.Out();

	C = "�ȳ�";
	C += B;

	int			a;

	(a = 10) += 20;

	cout << a << endl;

	(a += 10) += 20;

	cout << a << endl;



	A = "�ȳ�";

	B = A;	//	��������, �⺻���Կ�����

	B = A + "�ϼ���";
	C = A + B;


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