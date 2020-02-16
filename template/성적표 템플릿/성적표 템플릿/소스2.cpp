template <typename T>
class DArray
{
	T *m_buf;
	int m_size;
	int m_capa;

public:
	DArray()
	{
		m_buf = new T[Default_Size];
		memset(m_buf, 0, Default_Size);
		m_size = 0;
		m_capa = Default_Size;
	}

	DArray(int capa)
	{
		m_buf = new T[capa];
		memset(m_buf, 0, capa);
		m_size = 0;
		m_capa = capa;
	}

	T &operator[] (int index)
	{
		return m_buf[index];
	}

	void Resize(int newCapa)
	{
		m_buf = new int[newCapa];
		T *temp = new T[newCapa];
		memcpy(temp, m_buf, sizeof(T)*m_size);
		delete[] m_buf;
		m_buf = temp;
		m_capa = capa;
	}

	void push_back(int data)
	{
		if (m_size == m_capa)
		{
			Resize(m_capa * 2);
		}
		m_buf[m_size] = data;
		m_size++
	}

	void pop_back()
	{
		m_buf[m_size] = 0;
		m_size--;
	}

	int getSize()
	{
		return m_size;
	}

	int getCapa()
	{
		return this->m_capa;
	}
	~DArray()
	{
		delete[] m_buf;
	}
};
class Person
{
private:
	Darray<Person> darr;
	
	struct Info
	{
		char	*Name;
		int		Kor;
		int		Eng;
		int		Math;
	};

	int Size = Default_Size; 
	int Count = 0;;
	Info *pInfo = nullptr;

	void Add();
	void Print();
	void Del();
	void Edit();
};


int main()
{
	bool is_playing = true;
	Person person;
	while (is_playing)
	{
		int Input = 0;

		while (is_playing)
		{
			cout << " 1. �л� �Է�" << endl;
			cout << " 2. �л� ���" << endl;
			cout << " 3. �л� ����" << endl;
			cout << " 4. �л� ����" << endl;
			cout << " 5. ����" << endl;
			cout << "���ϴ� ��ȣ�� �����ϼ���   : ";
			cin >> Input;

			switch (Input)
			{
			case 1: person.Add();  break;
			case 2: person.Print();  break;
			case 3: person.Del();  break;
			case 4: person.Edit();	break;
			case 5: is_playing = false;				break;
			}
		}
	}



	return 0;
}

void Person::Add()
{
	pInfo = darr.DArray;
	
	cout << "�л� �߰�" << endl;
	cout << " �̸�, ����, ����, ���� ������ �Է�" << endl;
	cin >> 
}