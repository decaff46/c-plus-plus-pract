#include "MyString.h"


int main()
{			  
	MyString A;
	MyString B;
	MyString C;

	(A = "�ȳ�") += "�ϼ���";

	A.Out();
	//	�ȳ��ϼ��� ������
	B = A + " ������";
	B.Out();

	//	������ �ȳ��ϼ���
	C = "������ " + A;

	cout << C << endl;
	return 0;
}