#include <iostream>
using namespace std;

/*
	���ڿ�
		asdfgh

		char�� �迭

	NULL ����

	���ڿ� �Է�, ����� �� �迭�̸��� ����ó�� ����.
	���ڿ��� ���� �˷��ִ� ��Ŀ 0

	char name[10] = {};

	cout << name << endl;

	"korea" -> 'k' 'o' 'r' 'e' 'a' '\0'
*/
/*
	// cstring
	// string.h

	���ڿ��Լ�

		���ڿ�����			strlen
		���ڿ�����			strcpy
		���ڿ��̾���̱�	strcat
		���ڿ���			strcmp
*/
void main()
{
	char String[2] = "K";
	char String2[10] = { 'u', 's', 'a' };

	cout << strlen(String) << endl;
	cout << strlen("����") << endl;

	// String = String2;
	//strcpy(String, String2);
	strcpy_s(String, 2, String2);

	cout << String << endl;

	return;

	char Buf[1024] = "";
	cout << "�Է� : ";
	cin >> Buf;
	cout << Buf << endl;
	
	cin >> Buf;
	cout << Buf << endl;

	cin >> Buf;
	cout << Buf << endl;

	//cout << String << endl;

	// "kor" == "kkk"
	// name = "����";
}