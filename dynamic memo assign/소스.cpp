#include <iostream>
using namespace std;

/*
	메모리영역	:	코드, 데이터, 스택, 힙

	정적할당	:	지금까지 썼던 변수 선언
					프로그램이 실행시 용량이 확정이 되는 변수들
					스택에 저장된다, 해당 지역이 종료되면 죽는다.

	동적할당	:	런타임시에 동적으로 할당받아서 사용하는 변수
					힙에 저장된다.
					할당에 실패할 수 있다.( Window 는 거의 신경안써도 된다. )
					해제를 직접 해줘야한다.( 누수 원인이 될 수 있다. )
*/

/*
	//	C 형 동적할당
	//	C형 동적할당 확장용 함수가 존재

	C++형 동적할당

		new,	new[]
		delete, delete[]
*/

/*
	성적표 동적할당 컨텐츠 추가

		A.	처음시작할때 총 학생수가 몇인지 입력받아서 동적할당

		B.	아예 무제한 입력이 가능
			- 일정공간을 미리 확보해서 입력을 받는다.
			- 입력공간이 꽉차면 더 큰공간을 확보해서 데이터를 이동시킨다.
*/

int main()
{
	//	인트형 변수를 하나 동적할당하고, 그 위치를 반환한다.
	int *pNum = new int;

	*pNum = 100;
	cout << *pNum << endl;

	//	동적메모리 해제
	delete pNum;
	///////////////////////////////////////////////////

	int ArraySize = 0;

	cout << "배열 개수 입력 :";
	cin >> ArraySize;

	
	// 인트형 변수 ArraySize개짜리 메모리다.
	int *pArray = nullptr;
	
	// 좋은 습관( 메모리 누수나 포인터 사용에 관한 )
	if (pArray == nullptr)
	{
		pArray = new int[ArraySize];
	}
	
	for (int i = 0; i < ArraySize; i++)
	{
		pArray[i] = i;
		cout << pArray[i] << endl;
	}

	// 좋은 습관
	delete[] pArray;
	pArray = nullptr;

	return 0;
}