#pragma once

template	< typename T >
struct MyVector
{
	int Size		= 0;
	int Capacity	= 1;

	T *pData = new T[Capacity];

	//	 ���� Ȯ��
	void	Expend();

	/////////////////////////////////////
	void	Push_Back(T _Input);
	void	Pop_Back();

	void	Release();
	
	//	A[3]
	T&	operator[](int _index);
};

template	< typename T >
void MyVector<T>::Expend()
{
	//	ũ�⺯���� ������Ų��.
	Capacity *= 2;

	//	������ ũ�⺯���� ���ο� ������ �Ҵ�
	T *pNew = new T[Capacity];

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

template	< typename T >
void MyVector<T>::Push_Back(T _Input)
{
	if (Size == Capacity)
	{
		Expend();
	}

	pData[Size++] = _Input;
}

template	< typename T >
void MyVector<T>::Pop_Back()
{
	if (Size > 0)
	{
		Size--;
	}
}

template	< typename T >
void MyVector<T>::Release()
{
	delete[] pData;
}

template	< typename T >
T&	MyVector<T>::operator[](int _index)
{
	return pData[_index];
}