#include <iostream>
#include <string>
using namespace std;



///흠 string으로 구현 했을때는 성공했습니다! (아마도) 그런데 문자열로 하려고 하니 한글 입력시 실패 합니다 
///처음에는 아 사이즈가 부족해서 그렇구나 해서 사이즈를 늘렸는데도 그렇네요 왜그럴까요?? 
///오류 발생시 Program()이 한번 돌고 ?로 끝나는데 이건 무슨 의밀까요?


void Program();
void Add (char *&_pName, int *&_pScore, int &_StdSize,int &_NumCnt);
void Out (char *&_pName, int *&_pScore, int &_StdSize, int &_NumCnt);
void Del (char *&_pName, int *&_pScore, int &_StdSize, int &_NumCnt);
void Edit(char *&_pName, int *&_pScore, int &_StdSize, int &_NumCnt);

void main()
{
	Program();
}

void Program()
{
	bool Playing = true;
	int NumCnt = 0;
	int StdSize = 2;

	//string *pName = nullptr;  
	char *pName  = nullptr;
	int  *pScore = nullptr;

	if (pName == nullptr && pScore == nullptr)
	{
		pName	= new char[StdSize];
		pScore	= new int [StdSize];
	}

	int Input = 0;
	while (Playing)
	{
		
		cout << endl << " 1. 학생 입력" << endl;
		cout << " 2. 학생 출력" << endl;
		cout << " 3. 학생 삭제" << endl;
		cout << " 4. 학생 변경" << endl;
		cout << " 5. 종료" << endl;
		cout << "원하는 번호를 선택하세요   : ";
		cin >> Input;

		switch (Input)
		{
		case 1: Add (pName, pScore, StdSize, NumCnt); break;
		case 2: Out (pName, pScore, StdSize, NumCnt); break;
		case 3: Del (pName, pScore, StdSize, NumCnt); break;
		case 4: Edit(pName, pScore, StdSize, NumCnt); break;
		case 5: Playing = false;					  break;
		}
	}
}

void Add (char *&_pName, int *&_pScore, int &_StdSize, int &_NumCnt)
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

			char *pNewName  = nullptr;
			int  *pNewScore = nullptr;

			if (pNewName == nullptr && pNewScore == nullptr)
			{
				pNewName	= new char[_StdSize + Add];
				pNewScore	= new int [_StdSize + Add];
			}

			for (int i = 0; i < _NumCnt; i++)
			{
				pNewName[i] = _pName[i];
				pNewScore[i]= _pScore[i];
			}

			delete[] _pName;
			delete[] _pScore;
			
			_StdSize += Add;
			_pName  = pNewName;
			_pScore = pNewScore;
		}	
		else
		{
			return;
		}
	}
	
	//기본 성적표
	cout << "이름 : ";
	cin >> _pName[_NumCnt];
	cout << "성적 : ";
	cin >> _pScore[_NumCnt];

	cout << _pName[_NumCnt] << " : " << _pScore[_NumCnt] << " 을 추가 했습니다 " << endl;
	_NumCnt++;

	int YN = 0;
	cout << "계속 추가? (1 = 예 / 2 = 노)  :";
	cin >> YN;
	if (YN == 1)
	{
		Add(_pName, _pScore, _StdSize, _NumCnt);
	}
	else
	{
		return;
	}
	cout << endl << endl;
}
		 
void Out (char *&_pName, int *&_pScore, int &_StdSize, int &_NumCnt)
{
	//입력 학생 체크 
	if (_NumCnt != 0)
	{
		for (int i = 0; i < _NumCnt; i++)
		{
			cout << _pName[i] << " : " << _pScore[i] << endl;
		}
		cout << "출력 끝" << endl;
	}
	else
	{
		cout << "입력 된 학생이 없습니다!" << endl;
	}
	cout << endl << endl;
}
		  
void Del (char *&_pName, int *&_pScore, int &_StdSize, int &_NumCnt)
{
	//입력 학생 체크 
	if (_NumCnt != 0)
	{
		char DelName = '\n';
		int DelCnt = 0;
		int DelTrk = -1;
		
		cout << "지금 까지 입력 된 학생 정보입니다" << endl;
		Out(_pName, _pScore, _StdSize, _NumCnt);

		cout << "삭제할 학생의 이름 기입 : ";
		cin >> DelName;

		while (DelCnt < _NumCnt)
		{
			if (_pName[DelCnt] == DelName)
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
				_pName[DelCnt] = '\n';
				_NumCnt--;
			}
			else
			{
				for (int i = DelCnt; i < _NumCnt - 1; i++)
				{
					_pName[i] = _pName[i + 1];
					_pScore[i] = _pScore[i + 1];
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
		  
void Edit(char *&_pName, int *&_pScore, int &_StdSize, int &_NumCnt)
{
	//입력 학생 체크 
	if (_NumCnt != 0)
	{
		char ChangeName = '\n';
		int ChangeScore = 0;
		int ChangeCnt = 0;
		int ChangeTrk = -1;

		cout << "지금 까지 입력 된 학생 정보입니다" << endl;
		Out(_pName, _pScore, _StdSize, _NumCnt);

		cout << "변경할 학생의 이름 기입 : ";
		cin >> ChangeName;

		while (ChangeCnt < _NumCnt)
		{
			if (_pName[ChangeCnt] == ChangeName)
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
			_pName[ChangeCnt] = ChangeName;
			cout << ChangeName << " 의 변경할 점수를 입력하세요 : ";
			cin >> ChangeScore;
			_pScore[ChangeCnt] = ChangeScore;

			cout << _pName[ChangeCnt] << " : " << _pScore[ChangeCnt] << "로 정보가 변경 되었습니다" << endl;
		}
	}
	else
	{
		cout << "입력 된 학생이 없습니다!" << endl;
	}
	cout << endl << endl;
}