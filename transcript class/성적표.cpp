#include "MyString.h"


class Transcript
{
private:

	struct Info
	{
		DataType *Name;
		int Kor;
		int Eng;
		int Math;
	};

	bool Playing = true;
	int NumCnt = 0;
	int StdSize = 2;
	Info *pTrans = nullptr;
	Info *pNTrans = nullptr;

public:
	Transcript()
	{
		pTrans = new Info[StdSize];
	}
	~Transcript()
	{
		cout << "프로그램 종료" << endl;
		delete[] pTrans;
	}
	void start();
	void Add();
	void Out();
	void Del();
	void Edit();

};

void Transcript::start()
{
	if (pTrans == nullptr)
	{
		pTrans = new Info [StdSize];
	}

	int Input = 0;

	while (Playing)
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
		case 1: Add();  break;
		case 2: Out();  break;
		case 3: Del();  break;
		case 4: Edit();	break;
		case 5: Playing = false;				break;
		}
	}
}

void Transcript::Add()
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

			if (pNTrans == nullptr)
			{
				pNTrans = new Info[StdSize + Add];
			}

			for (int i = 0; i < NumCnt; i++)
			{
				pNTrans[i] = pTrans[i];
			}

			delete[] pTrans;
			StdSize += Add;

			pTrans = pNTrans;
		}
		else
		{
			return;
		}
		//기본 성적표
		cout << "이름 : ";
		cin >> pTrans[NumCnt].Name;
		cout << "국어성적 : ";
		cin >> pTrans[NumCnt].Kor;
		cout << "영어성적 : ";
		cin >> pTrans[NumCnt].Eng;
		cout << "수학성적 : ";
		cin >> pTrans[NumCnt].Math;

		cout << pTrans[NumCnt].Name << " : " << pTrans[NumCnt].Kor << ", " << pTrans[NumCnt].Eng << ", " << pTrans[NumCnt].Math << " 을 추가 했습니다 " << endl;

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

void Transcript::Out()
{
	if (NumCnt != 0)
	{
		cout.width(4);
		cout << "이름 : \t 국어, 영어, 수학" << endl;
		for (int i = 0; i < NumCnt; i++)
		{
			cout << pTrans[i].Name << " : " << pTrans[i].Kor << " , " << pTrans[i].Eng << " , " << pTrans[i].Math << endl;
		}
		cout << "출력 끝" << endl;
	}
	else
	{
		cout << "입력 된 학생이 없습니다!" << endl;
	}
	cout << endl;
}

void Transcript::Del()
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
			if (pTrans[DelCnt].Name == DelName)
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
				pTrans[DelCnt].Name = "";
				NumCnt--;
			}
			else
			{
				for (int i = DelCnt; i < NumCnt - 1; i++)
				{
					pTrans[i] = pTrans[i + 1];
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

void Transcript::Edit()
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
			if (pTrans[ChangeCnt].Name == ChangeName)
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
			pTrans[ChangeCnt].Name = ChangeName;
			cout << ChangeName << " 의 변경할 점수를 입력하세요(국영수 순서) : ";
			cin >> ChangeScore;
			pTrans[ChangeCnt].Kor = ChangeScore;
			cin >> ChangeScore;
			pTrans[ChangeCnt].Eng = ChangeScore;
			cin >> ChangeScore;
			pTrans[ChangeCnt].Math = ChangeScore;

			cout << pTrans[ChangeCnt].Name << " : " << pTrans[ChangeCnt].Kor << pTrans[ChangeCnt].Eng << pTrans[ChangeCnt].Math << "로 정보가 변경 되었습니다" << endl;
		}
	}
	else
	{
		cout << "입력 된 학생이 없습니다!" << endl;
	}
	cout << endl << endl;
}
