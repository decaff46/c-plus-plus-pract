#pragma once

template	< typename T >
struct MyVector
{
	int Size		= 0;
	int Capacity	= 1;

	T *pData = new T[Capacity];

	//	 공간 확장
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
	//	크기변수를 증가시킨다.
	Capacity *= 2;

	//	증가된 크기변수로 새로운 공간을 할당
	T *pNew = new T[Capacity];

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