#include <iostream>
using namespace std;

int Add(int a, int b);

void main()
{
	printf("%d 원\n", 'a');
	printf("%c 글자\n", 97);

	cout << Add(1, 2) << endl;

	return;


	char Input = '\0';

	cout << "입력 : ";
	cin >> Input;

	switch (Input)
	{
	case 'Y':
	case 'y':		
		
		break;

	case 'N':
	case 'n':

		break;
	}
		
}

/*
		1. %d .... 서식문자

			a. 가변인자 : 매개변수의 개수가 변하는 매개변수
			b. ...
			c. 문자열안에 있는 서식문자의 개수

			"%d : %f", a, b

			printf 출력함수 == cout

			printf( 문자열, 가변인자들... );

			printf("HelloWorld\n");
			printf("%d 원", 1000 );

		서식문자 ( 문자열에서 %가 붙어있다. )

			%d : 정수로 표현
			%f : 실수로 표현
			%c : 문자로 표현
			.
			.
			.

		\n

		이스케이프 시퀀스

		문자를 통해서 기능을 수행한다.

		\n	: 개행
		\t	: 탭
		\a	: 메인보드에있는 스피커 경고음
		\r	: 캐리지리턴( HOME )
		\v	: 세로 탭
		..
		\"	: " 문자
		\'	: ' 문자
		\\	: \ 문자
*/

/*
	2. switch 에 문자

		정수만 들어간다. ( 팩트 )

		char 저장을 정수값으로 저장
			 출력을 해당 숫자와 상응하는 문자

			 48 == '0'

			 65 == 'a'

			 아스키코드

				숫자, 영대소문자, 키보드 특문, 기능키
				127개.. 0~127

			그 외의 영어가 아닌 외국어들 -128 ~ -1

			조합체

				2바이트로 상응되는 문자를 표현
				한글 == 2바이트
	
	
*/

/*
	3. 헤더파일

		헤더파일 종류

		#include <- 전처리기
		<>
		""

		파일분할

		소스파일 : *.cpp , *.c	컴파일시에 포함
		헤더파일 : *.h			컴파일시에 포함이 안된다.

		#include 가 - Ctrl + V
*/

/*
	함수 파일분할

		1. 함수를 다른 파일에 옮겨놓는다.
		2. 사용할 곳에 프로토타입을 선언한다.

		원리

			컴파일시에 모든 소스파일이 하나의 파일로.
			파일로 변환되면 떨어졌던 함수들이 한자리로

			코딩시에 필요한건 프로토타입뿐...

		주의점 cpp 끼리 진짜 하나도 모른다.

		다른파일에서 출력하고 싶으면 거기에도 iostream
*/