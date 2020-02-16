#pragma once
template <typename T>
class MyVector
{
	int Size = 0; 
	int Capacity = 1; 

	T *pData = new[Capacity];

	void Expand();
	void Push_Back(T _Input);
	void Pop_Back();
	void Release();

	T& Operator[](int _Index)
};

template <typename T>
void MyVector<T> ::Expand()
{
	Capacity *= 2; 

	T *pNew = new[Capacity];


	//여기서 왜 Size가 될까?? 
	for (int i = 0; i < Size; i++)
	{
		pNew[i] = pData[i];
	}

	delete[] pData; 
	pData = pNew;
}

template <typename T>
void MyVector<T> ::Push_Back(T _Input)
{
	if (Size == Capacity)
	{
		Expand();
	}
	pData[lengh(Size) + 1] = _Input;
	//pData[Size++] = _Input; 이라고 하셨는데 왜 SIze++?
}

template <typename T>
void MyVecotr<T> ::Pop_Back()
{

}

