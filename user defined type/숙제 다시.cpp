#include <iostream>
#include <string>
using namespace std;


struct Transcript
{
	string	Name;
	int		Kor;
	int		Eng;
	int		Math;
};



void Add ( Transcript *&_pTrans,  int &_StdSize, int &_NumCnt);
void Out ( Transcript *&_pTrans,  int &_StdSize, int &_NumCnt);
void Del ( Transcript *&_pTrans,  int &_StdSize, int &_NumCnt);
void Edit( Transcript *&_pTrans,  int &_StdSize, int &_NumCnt);



void main()
{
	bool Playing = true;
	int NumCnt = 0;
	int StdSize = 2;

	//구조체 활용 동적할당
	Transcript *pTrans = nullptr;
	if (pTrans == nullptr)
	{
		pTrans = new Transcript[StdSize];
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
		case 1: Add (pTrans, StdSize, NumCnt);  break;
		case 2: Out (pTrans, StdSize, NumCnt);  break;
		case 3: Del (pTrans, StdSize, NumCnt);  break;
		case 4: Edit(pTrans, StdSize, NumCnt);	break;
		case 5: Playing = false;				break;
		}
	}
}

void Add(struct Transcript *&_pTrans, int &_StdSize, int &_NumCnt)
{
	//용량 체크 
	if (_NumCnt == _StdSize)
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
			Transcript *pNTrans = nullptr;
			if (pNTrans == nullptr)
			{
				pNTrans = new Transcript[_StdSize+Add];
			}
			//새로운 변수에 기존 값 대입 
			//pNTrans = _pTrans; 왜 이렇게 했을때는 오작동을 일으키는 거지?
			for (int i = 0; i < _NumCnt; i++)
			{
				//pNTrans[i].Name = _pTrans[i].Name;
				//pNTrans[i].Kor = _pTrans[i].Kor;
				//pNTrans[i].Eng = _pTrans[i].Eng;
				//pNTrans[i].Math = _pTrans[i].Math;
				
				pNTrans[i] = _pTrans[i];
			}

			delete[] _pTrans;
			_StdSize += Add;

			//기존 배열 삭제 후, 새로운 배열에 복사 된 값 재 복사
			_pTrans = pNTrans;			
			//delete[] pNTrans;  왜 여기서 pNTrans를 삭제하면 안되지? 누수가 일어 나느거 아닌가?
		}
		else
		{
			return;
		}
	}
	//기본 성적표
	cout << "이름 : ";
	cin >> _pTrans[_NumCnt].Name;
	cout << "국어성적 : ";
	cin >> _pTrans[_NumCnt].Kor;
	cout << "영어성적 : ";
	cin >> _pTrans[_NumCnt].Eng;
	cout << "수학성적 : ";
	cin >> _pTrans[_NumCnt].Math;

	cout << _pTrans[_NumCnt].Name << " : " << _pTrans[_NumCnt].Kor << ", " << _pTrans[_NumCnt].Eng << ", " << _pTrans[_NumCnt].Math << " 을 추가 했습니다 " << endl;

	_NumCnt++;
	
	int YN = 0;
	cout << "계속 추가? (1 = 예 / 2 = 노)  :";
	cin >> YN;
	if (YN == 1)
	{
		Add(_pTrans, _StdSize, _NumCnt);
	}
	else
	{
		return;
	}
}

void Out (struct Transcript *&_pTrans, int &_StdSize, int &_NumCnt)
{
	//입력 학생 체크 
	if (_NumCnt != 0)
	{
		cout.width(4);
		cout << "이름 : \t 국어, 영어, 수학" << endl;
		for (int i = 0; i < _NumCnt; i++)
		{
			cout << _pTrans[i].Name << " : "  << _pTrans[i].Kor << " , " << _pTrans[i].Eng << " , " << _pTrans[i].Math << endl;
		}
		cout << "출력 끝" << endl;
	}
	else
	{
		cout << "입력 된 학생이 없습니다!" << endl;
	}
	cout << endl;
}

void Del (struct Transcript *&_pTrans, int &_StdSize, int &_NumCnt)
{
	//입력 학생 체크 
	if (_NumCnt != 0)
	{
		string DelName = "";
		int DelCnt = 0;
		int DelTrk = -1;

		cout << "지금 까지 입력 된 학생 정보입니다" << endl;
		Out(_pTrans, _StdSize, _NumCnt);

		cout << "삭제할 학생의 이름 기입 : ";
		cin >> DelName;

		while (DelCnt < _NumCnt)
		{
			if (_pTrans[DelCnt].Name == DelName)
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
			if (_NumCnt == DelCnt)
			{
				_pTrans[DelCnt].Name = "";
				_NumCnt--;
			}
			else
			{
				for (int i = DelCnt; i < _NumCnt - 1; i++)
				{
					//_pTrans[i].Name		= _pTrans[i + 1].Name;
					//_pTrans[i].Kor		= _pTrans[i + 1].Kor;
					//_pTrans[i].Eng		= _pTrans[i + 1].Eng;
					//_pTrans[i].Math		= _pTrans[i + 1].Math;
					_pTrans[i] = _pTrans[i+1];
				}
				_NumCnt--;
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

void Edit(struct Transcript *&_pTrans, int &_StdSize, int &_NumCnt)
{
	//입력 학생 체크 
	if (_NumCnt != 0)
	{
		string ChangeName = "";
		int ChangeScore = 0;
		int ChangeCnt = 0;
		int ChangeTrk = -1;

		cout << "지금 까지 입력 된 학생 정보입니다" << endl;
		Out(_pTrans, _StdSize, _NumCnt);

		cout << "변경할 학생의 이름 기입 : ";
		cin >> ChangeName;

		while (ChangeCnt < _NumCnt)
		{
			if (_pTrans[ChangeCnt].Name == ChangeName)
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
			_pTrans[ChangeCnt].Name = ChangeName;
			cout << ChangeName << " 의 변경할 점수를 입력하세요(국영수 순서) : ";
			cin >> ChangeScore;
			_pTrans[ChangeCnt].Kor = ChangeScore;
			cin >> ChangeScore;
			_pTrans[ChangeCnt].Eng = ChangeScore;
			cin >> ChangeScore;
			_pTrans[ChangeCnt].Math = ChangeScore;

			cout << _pTrans[ChangeCnt].Name << " : " << _pTrans[ChangeCnt].Kor  << _pTrans[ChangeCnt].Eng  << _pTrans[ChangeCnt].Math << "로 정보가 변경 되었습니다" << endl;
		}
	}
	else
	{
		cout << "입력 된 학생이 없습니다!" << endl;
	}
	cout << endl << endl;
}