#include <iostream>
using namespace std;

/*
	상속

		기존의 클래스로 새로운 클래스를 만드는 문법

	상속에 활용

		1.	확장
			ex) 2D용 좌표 클래스(x,y) -> 3D용 좌표 클래스(x,y,z)

		2.	세분화
			ex) 인간, 개, 고양이, 말 => 동물클래스, 인간클래스, 개클래스

		3. .........
*/

/*
	1.	함수 오버라이딩
	2.	부모클래스 포인터
	3.	가상함수
	--------------------------------------------------

	1.	독립적인 클래스를 작성하고 싶다. ( 인간, 개, 말, 고양이 )

		- 여기는 자료형이 다 달라..

	2.	관리는 일괄적으로 하고 싶다.
		
		- 자료형이 똑같았으면 좋겠다.
		- 해결책	: 부모클래스 포인터
		- 다시문제	: 자식껄 쓸 수가 없다...
		- 부모포인터로.. 자식꺼를 쓰고 싶다...
		- 함수오버라이딩과 가상함수.
		- 일괄적인 관리 + 독립적 구성으로 실행
		

	for( int i = 0; i < size; i++ )
	{
		animal[i].update();
	}

	부모클래스 포인터

		1. 기본적으로 부모클래스 객체의 주소를 저장할 수 있다.
		2. 자식클래스 객체의 주소도 저장할 수 있다.

*/

class Top
{
public:
	int m_num = 0;

	void A_Test()
	{
		cout << "부모" << endl;
	}
};

class BottomA : public Top
{
public:
	int m_bottomNum = 10;

	void A_Test()
	{
		cout << "자식" << endl;
	}
};
class BottomB : public Top
{
public:
	int m_bottomNum = 10;
};

int main()
{
	BottomA	a;
	BottomB b;

	// 동적 바인딩 - 가상함수테이블을 확인하고 호출

	// 정적 바인딩 - 함수호출 상태 고정
	b.A_Test();

	a.A_Test();
	a.Top::A_Test();

	return 0;
}