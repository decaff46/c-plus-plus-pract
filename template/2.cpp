#include <iostream>
using namespace std;
#define Default_Size 5

template <typename T>
class Array
{
	T *m_buf;
	T m_size;
	T m_capa;

public:
	Array()
	{
		m_buf = new T[Default_Size];
		memset(m_buf, 0, Default_Size);
		m_size = 0;
		m_capa = Default_Size;
	}

	Array(int capa)
	{
		m_buf = new T[capa];
		memset(m_buf, 0, capa);
		m_size = 0;
		m_capa = capa;
	}

	int operator[] (int index)
	{
		return m_buf[index];
	}

	void Resize(T newCapa)
	{
		m_buf = new T[newCapa];
		int *temp = new T[newCapa];
		memcpy(temp, m_buf, sizeof(int)*m_size);
		delete[] m_buf;
		m_buf = temp;
		m_capa = capa;
	}

	void push_back(T data)
	{
		if (m_size == m_capa)
		{
			Resize(m_capa * 2);
			m_buf[m_size] = data;
			m_size++
		}
	}

	void pop_back()
	{
		m_buf[m_size] = 0;
		m_size--;
	}

	T getSize()
	{
		return m_size;
	}
};