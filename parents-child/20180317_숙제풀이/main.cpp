#include <iostream>
using namespace std;

/*
	숙제

		캐릭터

			공격, 방어

		무기

			검, 활, 창


		무기 추가	: 도끼
		캐릭터 행동 : 무기던지기
		-------------------------------------------

	조사

		템플릿

		2가지 : 함수 템플릿, 클래스 템플릿
*/

/*
	다형성의 장점

		1. 실제 실행부분( 인터페이스 ) 를 변경하지 않고 추가삭제 가능하다.
		2. 인터페이스를 추가할때도 1개만 추가하면 된다.

	다형성의 단점

		1.	구조가 복잡하다.
		2.	속도가 상대적으로 느려요.
*/

//	손전등 만들기
//	켜기, 끄기, 전구 교체
//	백열등, LED, 오슬람
#include "Lamp.h"


int main()
{
	int		input		= 0;
	bool	isPlaying	= true;
	Lamp	lamp;

	while (isPlaying)
	{
		cout << "0. 전구명" << endl;
		cout << "1. 켜기" << endl;
		cout << "2. 끄기" << endl;
		cout << "3. 교체" << endl;
		cout << "4. 화면청소" << endl;
		cout << "입력 : ";
		cin >> input;

		switch (input)
		{
		case 0:	lamp.Name();	break;
		case 1:	lamp.TurnOn();	break;
		case 2:	lamp.TurnOff();	break;

		case 3:
		{
			cout << "전구 종류 선택" << endl;
			cout << "0. 백열등" << endl;
			cout << "1. LED" << endl;
			cout << "2. 오슬람" << endl;
			cout << "3. 신타입" << endl;
			cin >> input;

			lamp.ChangeBulb(input);
		}break;
		case 4: system("cls");	break;
		}
	}
	return 0;
}