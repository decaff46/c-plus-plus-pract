#include <iostream>
using namespace std;

/*
	�θ��� ����Ҹ���

		- �θ������Ϳ� �ڽ� �����Ҵ� ��ü�� ����� ��
		- �θ������ͷ� delete �� �����ؾ� �� ��

		- �θ� �Ҹ��ڿ� virtual �� �ٿ��� �ڽ��� �Ҹ��ڰ� ȣ��ȴ�.
*/

class Top
{
public:
	Top()	
	{
		cout << "Top ������" << endl;
	}
	virtual ~Top()
	{
		cout << "Top �Ҹ���" << endl;
	}
};
class  Bottom : public Top
{
public:
	Bottom()
	{
		cout << "Bottom ������" << endl;
	}
	~Bottom()
	{
		cout << "Bottom �Ҹ���" << endl;
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