#include <iostream>
using namespace std;

struct MyVector
{
	int Size		= 0;
	int Capacity	= 1;

	int *pData		= new int[Capacity];

	//	 ���� Ȯ��
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
	//	ũ�⺯���� ������Ų��.
	Capacity *= 2;

	//	������ ũ�⺯���� ���ο� ������ �Ҵ�
	int *pNew = new int[Capacity];

	//	���� ������ ���
	for (int i = 0; i < Size; ++i)
	{
		pNew[i] = pData[i];
	}
	//memmove(pNew, pData, sizeof(int)*Size);

	//	���� ������ ����
	delete[] pData;

	//	�ּҰ� ����
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
	cout << "��� : ";
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
