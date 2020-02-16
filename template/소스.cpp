#include <iostream>
using namespace std;

void output(int a)
{
	cout << "일반함수" << endl;
}

template < typename T >
void output( T a )
{
	cout << "템플릿" << endl;
}

//	템플릿 특수화
template <>
void	output<int>(int a)
{
	cout << "특수템플릿" << endl;
}

//	함수 호출 우선순위
//	일반함수 > 특수화템플릿 > 템플릿

int main()
{
	output(1);
	//output(1.0f);
	//output('a');

	return 0;
}

/*
	동적 배열

	템플릿으로 만든다.

	int 형 동적배열
	float 형 동적배열..


	1. 학생 성적표.... 동적배열.... 템플릿 동적배열로 만든 후... 작동
	2. 함수포인터 <- 조사
*/