#include <iostream>

using namespace std; 

template <typename T>
class Person
{
private:
	struct Info 
	{
		T *Name;
		T Kor;
		T Eng;
		T Math;
	};

	int		NumCnt = 0;
	int		StdSize = 2;
	Info	*pInfo = nullptr;
	Info	*nInfo = nullptr;


public:
	Person() {}
	~Person() 
	{
		delete pInfo[];
		delete nInfo[];
	}

	void Add();
	void Out();
	void Del();
	void Edit();
};

template <typename T>
void Person::Add()
{
	if (NumCnt == StdSize)
	{
		int Input = 0;
		cout << "용량이 꽉 찼습니다 추가 하시겠습니까? (1 = 예 / 2 = 아니오)   :";
		cin >> Input;

		if (Input == 1)
		{
			int Add = 0;
			cout << "추가 인원 입력  : ";
			cin >> Add;

			//구조체 활용 2. 
			if (nInfo == nullptr)
			{
				nInfo = new Info[StdSize + Add];
			}

			for (int i = 0; i < NumCnt; i++)
			{
				nInfo[i] = pInfo[i];
			}

			delete[] pInfo;
			StdSize += Add;

			pInfo = nInfo;
		}
		else
		{
			return;
		}

		//기본 성적표
		cout << "이름 : ";
		cin >> pInfo[NumCnt].Name;
		cout << "국어성적 : ";
		cin >> pInfo[NumCnt].Kor;
		cout << "영어성적 : ";
		cin >> pInfo[NumCnt].Eng;
		cout << "수학성적 : ";
		cin >> pInfo[NumCnt].Math;

		cout << pInfo[NumCnt].Name << " : " << pInfo[NumCnt].Kor << ", " << pInfo[NumCnt].Eng << ", " << pInfo[NumCnt].Math << " 을 추가 했습니다 " << endl;

		NumCnt++;

		int YN = 0;
		cout << "계속 추가? (1 = 예 / 2 = 노)  :";
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

template <typename T>
void Person::Out()
{
	if (NumCnt != 0)
	{
		cout.width(4);
		cout << "이름 : \t 국어, 영어, 수학" << endl;
		for (int i = 0; i < NumCnt; i++)
		{
			cout << pInfo[i].Name << " : " << pInfo[i].Kor << " , " << pInfo[i].Eng << " , " << pInfo[i].Math << endl;
		}
		cout << "출력 끝" << endl;
	}
	else
	{
		cout << "입력 된 학생이 없습니다!" << endl;
	}
	cout << endl;
}

template <typename T>
void Person:: Del() 
{
	if (NumCnt != 0)
	{
		string DelName = "";
		int DelCnt = 0;
		int DelTrk = -1;

		cout << "지금 까지 입력 된 학생 정보입니다" << endl;
		Out();

		cout << "삭제할 학생의 이름 기입 : ";
		cin >> DelName;

		while (DelCnt < NumCnt)
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
			cout << "입력된 정보를 찾을 수 없습니다 " << endl;
		}
		else
		{
			if (NumCnt == DelCnt)
			{
				pInfo[DelCnt].Name = "";
				NumCnt--;
			}
			else
			{
				for (int i = DelCnt; i < NumCnt - 1; i++)
				{
					pInfo[i] = pInfo[i + 1];
				}
				NumCnt--;
			}
			cout << DelName << "을 리스트에서 삭제 했습니다" << endl;
		}

	}
	else
	{
		cout << "입력 된 학생이 없습니다!" << endl;
	}
	cout << endl << endl;
}

template <typename T>
void Person::Edit()
{
	if (NumCnt != 0)
	{
		string ChangeName = "";
		int ChangeScore = 0;
		int ChangeCnt = 0;
		int ChangeTrk = -1;

		cout << "지금 까지 입력 된 학생 정보입니다" << endl;
		Out();

		cout << "변경할 학생의 이름 기입 : ";
		cin >> ChangeName;

		while (ChangeCnt < NumCnt)
		{
			if (pInfo[ChangeCnt].Name == ChangeName)
			{
				ChangeTrk = ChangeCnt;
				break;
			}
			ChangeCnt++;
		}

		if (ChangeTrk == -1)
		{
			cout << "입력된 정보를 찾을 수 없습니다 " << endl;
		}
		else
		{
			cout << "변경할 이름을 입력하세요 : ";
			cin >> ChangeName;
			pInfo[ChangeCnt].Name = ChangeName;
			cout << ChangeName << " 의 변경할 점수를 입력하세요(국영수 순서) : ";
			cin >> ChangeScore;
			pInfo[ChangeCnt].Kor = ChangeScore;
			cin >> ChangeScore;
			if (NumCnt != 0)
	{
		string ChangeName = "";
		int ChangeScore = 0;
		int ChangeCnt = 0;
		int ChangeTrk = -1;

		cout << "지금 까지 입력 된 학생 정보입니다" << endl;
		Out();

		cout << "변경할 학생의 이름 기입 : ";
		cin >> ChangeName;

		while (ChangeCnt < NumCnt)
		{
			if (pInfo[ChangeCnt].Name == ChangeName)
			{
				ChangeTrk = ChangeCnt;
				break;
			}
			ChangeCnt++;
		}

		if (ChangeTrk == -1)
		{
			cout << "입력된 정보를 찾을 수 없습니다 " << endl;
		}
		else
		{
			cout << "변경할 이름을 입력하세요 : ";
			cin >> ChangeName;
			pInfo[ChangeCnt].Name = ChangeName;
			cout << ChangeName << " 의 변경할 점수를 입력하세요(국영수 순서) : ";
			cin >> ChangeScore;
			pInfo[ChangeCnt].Kor = ChangeScore;
			cin >> ChangeScore;
			pInfo[ChangeCnt].Eng = ChangeScore;
			cin >> ChangeScore;
			pInfo[ChangeCnt].Math = ChangeScore;

			cout << pInfo[ChangeCnt].Name << " : " << pInfo[ChangeCnt].Kor << pInfo[ChangeCnt].Eng << pInfo[ChangeCnt].Math << "로 정보가 변경 되었습니다" << endl;
		}
	}
	else
	{
		cout << "입력 된 학생이 없습니다!" << endl;
	}
	cout << endl << endl;[ChangeCnt].Eng = ChangeScore;
			cin >> ChangeScore;
			pInfo[ChangeCnt].Math = ChangeScore;

			cout << pInfo[ChangeCnt].Name << " : " << pInfo[ChangeCnt].Kor << pInfo[ChangeCnt].Eng << pInfo[ChangeCnt].Math << "로 정보가 변경 되었습니다" << endl;
		}
	}
	else
	{
		cout << "입력 된 학생이 없습니다!" << endl;
	}
	cout << endl << endl;
}


int main(void)
{
	Person person;
	bool Is_playing = true; 

	while (Is_playing) 
	{
		if (pInfo == nullptr)
		{
			pInfo = new Info[StdSize];
		}

		int Input = 0;

		while (Is_playing)
		{
			cout << " 1. 학생 입력" << endl;
			cout << " 2. 학생 출력" << endl;
			cout << " 3. 학생 삭제" << endl;
			cout << " 4. 학생 변경" << endl;
			cout << " 5. 종료" << endl;
			cout << "원하는 번호를 선택하세요   : ";
			cin >> Input;

			switch (Input)
			{
			case 1: person.Add();  break;
			case 2: person.Out();  break;
			case 3: person.Del();  break;
			case 4: person.Edit();	break;
			case 5: Is_playing = false;				break;
			}
		}
	}


	return 0;
}