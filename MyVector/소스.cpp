#include <iostream>
using namespace std;

struct MyVector
{
	int Size		= 0;
	int Capacity	= 1;

	int *pData		= new int[Capacity];

	//	 공간 확장
	void	Expend();

	/////////////////////////////////////
	void	Push_Back(int _Input);
	void	Pop_Back();

	void	Output();

	void	Release();
};

void main()
{
	MyVector	Sample;

	Sample.Push_Back(1);
	Sample.Output();

	Sample.Push_Back(2);
	Sample.Output();

	Sample.Push_Back(3);
	Sample.Output();

	Sample.Push_Back(4);
	Sample.Output();

	Sample.Push_Back(5);
	Sample.Output();

	Sample.Push_Back(6);
	Sample.Output();

	Sample.Pop_Back();
	Sample.Output();

	Sample.Pop_Back();
	Sample.Output();

	Sample.Pop_Back();
	Sample.Output();

	Sample.Pop_Back();
	Sample.Output();

	Sample.Pop_Back();
	Sample.Output();

	Sample.Release();
}

void MyVector::Expend()
{
	//	크기변수를 증가시킨다.
	Capacity *= 2;

	//	증가된 크기변수로 새로운 공간을 할당
	int *pNew = new int[Capacity];

	//	기존 데이터 백업
	for (int i = 0; i < Size; ++i)
	{
		pNew[i] = pData[i];
	}
	//memmove(pNew, pData, sizeof(int)*Size);

	//	기존 공간을 해제
	delete[] pData;

	//	주소값 갱신
	pData = pNew;
}

void MyVector::Push_Back(int _Input)
{
	if (Size == Capacity)
	{
		Expend();
	}

	pData[ Size++ ] = _Input;
}

void MyVector::Pop_Back()
{
	if (Size > 0)
	{
		Size--;
	}
}

void MyVector::Output()
{
	cout << "Size : " << Size << endl;
	cout << "Capa : " << Capacity << endl;
	cout << "출력 : ";
	for (int i = 0; i < Size; ++i)
	{
		cout << pData[i] << '\t';
	}
	cout << endl << endl;
}

void MyVector::Release()
{
	delete[] pData;
}
