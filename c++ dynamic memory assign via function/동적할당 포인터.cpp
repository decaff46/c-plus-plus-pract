#include <iostream>
using namespace std;

void	Func(int *_p)
{
	//	int *_p = p;
	_p = new int;

	cout << "&_p : " << &_p << endl;
	cout << "_p : " << _p << endl;
}

//	포인터를 사용해서 함수 외부변수의 값을 변경하려면
//	변경하려는 변수의 주소값을 대입해야한다.

void	FuncV(int _a)
{
	// int _a = a; C by V
	_a = 10;
}

void	FuncA(int **_p2)
{
	// int **_p2 = &p;	
	//	*_p2 = new int;	==	p = new int;
	*_p2 = new int;
}
void	FuncR(int  *&_rp)
{
	// int* &_rp = p;
	_rp = new int;
}

int main()
{
	int *p = nullptr;
	//Func(p);
	//FuncA(&p);
	FuncR(p);

	cout << "&p : " << &p << endl;
	cout << "p : " << p << endl;


	int a = 0;
	FuncV(a);

	return 0;
}