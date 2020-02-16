#include <iostream>
using namespace std;

/*
	문자열
		asdfgh

		char형 배열

	NULL 문자

	문자열 입력, 출력할 때 배열이름을 변수처럼 쓰자.
	문자열의 끝을 알려주는 마커 0

	char name[10] = {};

	cout << name << endl;

	"korea" -> 'k' 'o' 'r' 'e' 'a' '\0'
*/
/*
	// cstring
	// string.h

	문자열함수

		문자열길이			strlen
		문자열복사			strcpy
		문자열이어붙이기	strcat
		문자열비교			strcmp
*/
void main()
{
	char String[2] = "K";
	char String2[10] = { 'u', 's', 'a' };

	cout << strlen(String) << endl;
	cout << strlen("김명길") << endl;

	// String = String2;
	//strcpy(String, String2);
	strcpy_s(String, 2, String2);

	cout << String << endl;

	return;

	char Buf[1024] = "";
	cout << "입력 : ";
	cin >> Buf;
	cout << Buf << endl;
	
	cin >> Buf;
	cout << Buf << endl;

	cin >> Buf;
	cout << Buf << endl;

	//cout << String << endl;

	// "kor" == "kkk"
	// name = "김명길";
}