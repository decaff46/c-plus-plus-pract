#include <iostream>
using namespace std;

/*
	부모의 가상소멸자

		- 부모포인터에 자식 동적할당 객체를 사용할 때
		- 부모포인터로 delete 를 실행해야 할 때

		- 부모 소멸자에 virtual 을 붙여야 자식의 소멸자가 호출된다.
*/

class Top
{
public:
	Top()	
	{
		cout << "Top 생성자" << endl;
	}
	virtual ~Top()
	{
		cout << "Top 소멸자" << endl;
	}
};
class  Bottom : public Top
{
public:
	Bottom()
	{
		cout << "Bottom 생성자" << endl;
	}
	~Bottom()
	{
		cout << "Bottom 소멸자" << endl;
	}
};

int main()
{
	//Bottom	*p = new Bottom;
	//delete p;

	Top	*pp = new Bottom;

	delete pp;
	
	return 0;
}