#include <iostream>
using namespace std;

/*
const Ű����

- ���� ����ÿ� ����ϴ� Ű����
- ����Ұ� �ɼ�

- ������ ���ó�� ����� Ű����
ex) const int MAX = 10;


�����Ϳ� const �� ����

int *p;

- �־��� : *�� const �� ��ġ ����( int �� �ǹ�x )

A. const *p;		-> *p �����,	p �� ������.
B. * const p;		-> *p ����,		p �� �����.
C. const * const p; -> *p ���,		p �� �����.
*/
//	const Ű����� �������� �ڷ����� �ƴ� ������ ���̴� �����̴�.
int const a = 10;
const int b = 20;

// ?
const int const c = 30;

char const *Ment = "KOR";

void main()
{
	Ment = "USA";

	//	x
	//	Ment[2] = 'B';

	int NumA = 10;
	int const *p = &NumA;

	cout << *p << endl;

	//*p = 30;
	NumA = 30;

	cout << *p << endl;

	int NumB = 100;

	// ok
	p = &NumB;
}