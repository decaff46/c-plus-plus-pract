#include <iostream>
#include <string>
using namespace std;
#define Default_Size 5

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
		m_capa = newCapa;
		T *temp = new T[newCapa];
		memcpy(temp, m_buf, sizeof(T)*m_size);
		delete[] m_buf;
		m_buf = temp;
	}

	void push_back(T data)
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
	struct Info
	{
		char *Name;
		int Kor;
		int Eng;
		int Math;
	};

	int		Count = 0;
	int		Size = Default_Size;
	Info	*pInfo = nullptr;
	Info	*nInfo = nullptr;


public:
	Person() { }
	~Person()
	{
		delete[] pInfo;
		delete[] nInfo;
	}
	DArray<Info*> darray;
	void Add();
	void Print();
	void Del();
	//void Edit();
};


void Person::Add()
{
	if (Count == Size)
	{
		int Input = 0;
		cout << "�뷮�� �� á���ϴ� �߰� �ο� ���� :";
		cin >> Input;

		pInfo = new DArray<Info>[Size + Input]
			if (nInfo == nullptr)
			{
				nInfo = new Info[Size + Add];
			}

			for (int i = 0; i < Count; i++)
			{
				nInfo[i] = pInfo[i];
			}

			delete[] pInfo;
			Size += Add;

			pInfo = nInfo;
		}
		else
		{
			return;
		}

		//�⺻ ����ǥ
		cout << "�̸� : ";
		cin >> pInfo[Count].Name;
		cout << "����� : ";
		cin >> pInfo[Count].Kor;
		cout << "����� : ";
		cin >> pInfo[Count].Eng;
		cout << "���м��� : ";
		cin >> pInfo[Count].Math;

		cout << pInfo[Count].Name << " : " << pInfo[Count].Kor << ", " << pInfo[Count].Eng << ", " << pInfo[Count].Math << " �� �߰� �߽��ϴ� " << endl;

		Count++;

		int YN = 0;
		cout << "��� �߰�? (1 = �� / 2 = ��)  :";
		cin >> YN;
		if (YN == 1)
		{
			Add();
		}
		else
		{
			return;
		}
	}
}

void Person::Print()
{
	if (Count != 0)
	{
		cout << "�̸� : ����, ����, ����" << endl;
		for (int i = 0; i < Count; i++)
		{
			cout << pInfo[i].Name << " : " << pInfo[i].Kor << " , " << pInfo[i].Eng << " , " << pInfo[i].Math << endl;
		}
		cout << "��� ��" << endl;
	}
	else
	{
		cout << "�Է� �� �л��� �����ϴ�!" << endl;
	}
	cout << endl;
}

void Person::Del()
{
	if (Count != 0)
	{
		string DelName = "";
		int DelCnt = 0;
		int DelTrk = -1;

		cout << "���� ���� �Է� �� �л� �����Դϴ�" << endl;
		Print();

		cout << "������ �л��� �̸� ���� : ";
		cin >> DelName;

		while (DelCnt < Count)
		{
			if (pInfo[DelCnt].Name == DelName)
			{
				DelTrk = DelCnt;
				break;
			}
			DelCnt++;
		}

		if (DelTrk == -1)
		{
			cout << "�Էµ� ������ ã�� �� �����ϴ� " << endl;
		}
		else
		{
			if (Count == DelCnt)
			{
				pInfo[DelCnt].Name = "";
				Count--;
			}
			else
			{
				for (int i = DelCnt; i < Count - 1; i++)
				{
					pInfo[i] = pInfo[i + 1];
				}
				Count--;
			}
			cout << DelName << "�� ����Ʈ���� ���� �߽��ϴ�" << endl;
		}

	}
	else
	{
		cout << "�Է� �� �л��� �����ϴ�!" << endl;
	}
	cout << endl << endl;
}

//void Person::Edit()
//{
//	if (Count != 0)
//	{
//		string ChangeName = "";
//		int ChangeScore = 0;
//		int ChangeCnt = 0;
//		int ChangeTrk = -1;
//
//		cout << "���� ���� �Է� �� �л� �����Դϴ�" << endl;
//		Print();
//
//		cout << "������ �л��� �̸� ���� : ";
//		cin >> ChangeName;
//
//		while (ChangeCnt < Count)
//		{
//			if (pInfo[ChangeCnt].Name == ChangeName)
//			{
//				ChangeTrk = ChangeCnt;
//				break;
//			}
//			ChangeCnt++;
//		}
//
//		if (ChangeTrk == -1)
//		{
//			cout << "�Էµ� ������ ã�� �� �����ϴ� " << endl;
//		}
//		else
//		{
//			cout << "������ �̸��� �Է��ϼ��� : ";
//			cin >> ChangeName;
//			pInfo[ChangeCnt].Name = ChangeName;
//			cout << ChangeName << " �� ������ ������ �Է��ϼ���(������ ����) : ";
//			cin >> ChangeScore;
//			pInfo[ChangeCnt].Kor = ChangeScore;
//			cin >> ChangeScore;
//			pInfo[ChangeCnt].Eng = ChangeScore;
//			cin >> ChangeScore;
//			pInfo[ChangeCnt].Math = ChangeScore;
//
//			cout << pInfo[ChangeCnt].Name << " : " << pInfo[ChangeCnt].Kor << pInfo[ChangeCnt].Eng << pInfo[ChangeCnt].Math << "�� ������ ���� �Ǿ����ϴ�" << endl;
//		}
//	}
//	else
//	{
//		cout << "�Է� �� �л��� �����ϴ�!" << endl;
//	}
//	cout << endl << endl;
//}

int main()
{
	DArray<Person> darray;
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
			//case 4: person.Edit();	break;
			case 5: is_playing = false;				break;
			}
		}
	}


	return 0;
}