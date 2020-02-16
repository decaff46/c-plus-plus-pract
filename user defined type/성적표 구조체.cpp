#include <iostream>
#include <string>
using namespace std;


struct Transcript
{
	string	*pName = nullptr;
	int		*pKor = nullptr;
	int		*pEng = nullptr;
	int		*pMath = nullptr;

	// 선언이 필요하다는데 이게 무슨 뜻일까?  사칙연산을 제외한 나머지는 가능 한것 아니었나?
	//if (pName == nullptr && pKor == nullptr && pEng == nullptr && pMath == nullptr)
	//{
	//	Trans.pName = new string[StdSize];
	//	Trans.pKor = new int[StdSize];
	//	Trans.pEng = new int[StdSize];
	//	Trans.pMath = new int[StdSize];
	//}
};


struct N_Trans
{
	string	*pNewName = nullptr;
	int		*pNewKor = nullptr;
	int		*pNewEng = nullptr;
	int		*pNewMath = nullptr;
};

void Program();
void Add (string *&_pName, int *&_pKor, int *&_pEng, int *&_pMath, int &_StdSize, int &_NumCnt);
void Out (string *&_pName, int *&_pKor, int *&_pEng, int *&_pMath, int &_StdSize, int &_NumCnt);
void Del (string *&_pName, int *&_pKor, int *&_pEng, int *&_pMath, int &_StdSize, int &_NumCnt);
void Edit(string *&_pName, int *&_pKor, int *&_pEng, int *&_pMath, int &_StdSize, int &_NumCnt);

void main()
{
	Program();
}


void Program()
{
	bool Playing = true;
	int NumCnt = 0;
	int StdSize = 2;
	
	//구조체 사용
	Transcript Trans;

	if (Trans.pName == nullptr && Trans.pKor == nullptr && Trans.pEng == nullptr && Trans.pMath == nullptr)
	{
		Trans.pName		= new string[StdSize];
		Trans.pKor		= new int[StdSize];
		Trans.pEng		= new int[StdSize];
		Trans.pMath		= new int[StdSize];
	}

	int Input = 0;

	while (Playing)
	{
		cout << " 1. 학생 입력" << endl;
		cout << " 2. 학생 출력" << endl;
		cout << " 3. 학생 삭제" << endl;
		cout << " 4. 학생 변경" << endl;
		cout << " 5. 종료"		<< endl;
		cout << "원하는 번호를 선택하세요   : ";
		cin >> Input;

		switch (Input)
		{
		case 1: Add (Trans.pName, Trans.pKor, Trans.pEng,Trans.pMath, StdSize, NumCnt);  break;
		case 2: Out (Trans.pName, Trans.pKor, Trans.pEng,Trans.pMath, StdSize, NumCnt);  break;
		case 3: Del (Trans.pName, Trans.pKor, Trans.pEng,Trans.pMath, StdSize, NumCnt);  break;
		case 4: Edit(Trans.pName, Trans.pKor, Trans.pEng, Trans.pMath, StdSize, NumCnt); break;
		case 5: Playing = false;														 break;
		}

		cout << endl << endl;
	}
}

void Add(string *&_pName, int *&_pKor, int *&_pEng, int *&_pMath, int &_StdSize, int &_NumCnt)
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
			
			//구조체 활용
			N_Trans NTran;

			if (NTran.pNewName == nullptr && NTran.pNewKor == nullptr && NTran.pNewEng == nullptr&& NTran.pNewMath == nullptr)
			{
				NTran.pNewName		= new string[_StdSize + Add];
				NTran.pNewKor		= new int[_StdSize + Add];
				NTran.pNewEng		= new int[_StdSize + Add];
				NTran.pNewMath		= new int[_StdSize + Add];
			}

			for (int i = 0; i < _NumCnt; i++)
			{
				NTran.pNewName[i] = _pName[i];
				NTran.pNewKor[i]  = _pKor [i];
				NTran.pNewEng[i]  = _pEng [i];
				NTran.pNewMath[i] = _pMath[i];
			}


			delete[] _pName;
			delete[] _pKor;
			delete[] _pEng;
			delete[] _pMath;


			_StdSize += Add;
			_pName	= NTran.pNewName;
			_pKor	= NTran.pNewKor;
			_pEng	= NTran.pNewEng;
			_pMath	= NTran.pNewMath;
		}
		else
		{
			return;
		}
	}


	//기본 성적표
	cout << "이름 : ";
	cin >> _pName[_NumCnt];
	cout << "국어성적 : ";
	cin >> _pKor[_NumCnt];
	cout << "영어성적 : ";
	cin >> _pEng[_NumCnt];
	cout << "수학성적 : ";
	cin >> _pMath[_NumCnt];

	cout << _pName[_NumCnt] << " : " << _pKor[_NumCnt] << ", " << _pEng[_NumCnt] << ", " << _pMath[_NumCnt] <<" 을 추가 했습니다 " << endl;
	_NumCnt++;
	cout << endl;

	int YN = 0;
	cout << "계속 추가? (1 = 예 / 2 = 노)  :";
	cin >> YN;
	if (YN == 1)
	{
		Add(_pName, _pKor,_pEng, _pMath, _StdSize, _NumCnt);
	}
	else
	{
		return;
	}

}

void Out(string *&_pName, int *&_pKor, int *&_pEng, int *&_pMath, int &_StdSize, int &_NumCnt)
{
	//입력 학생 체크 
	if (_NumCnt != 0)
	{
		
		//문자 정렬하는 법 좀 알려 주세요 !
		cout << "이름 : \t 국어, 영어, 수학" << endl;
		for (int i = 0; i < _NumCnt; i++)
		{
			cout << _pName[i] << " : " << "\t"<< _pKor[i]  <<" , "<< _pEng[i]  <<" , "<< _pMath[i] << endl;
		}
		cout << "출력 끝" << endl;
	}
	else
	{
		cout << "입력 된 학생이 없습니다!" << endl;
	}
	cout << endl;
}

void Del(string *&_pName, int *&_pKor, int *&_pEng, int *&_pMath, int &_StdSize, int &_NumCnt)
{
	//입력 학생 체크 
	if (_NumCnt != 0)
	{
		string DelName = "";
		int DelCnt = 0;
		int DelTrk = -1;

		cout << "지금 까지 입력 된 학생 정보입니다" << endl;
		Out(_pName, _pKor, _pEng, _pMath, _StdSize, _NumCnt);

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
				_pName[DelCnt] = "";
				_NumCnt--;
			}
			else
			{
				for (int i = DelCnt; i < _NumCnt - 1; i++)
				{
					_pName[i] = _pName[i + 1];
					_pKor [i] = _pKor [i + 1];
					_pEng [i] = _pEng [i + 1];
					_pMath[i] = _pMath[i + 1];

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

void Edit(string *&_pName, int *&_pKor, int *&_pEng, int *&_pMath, int &_StdSize, int &_NumCnt)
{
	//입력 학생 체크 
	if (_NumCnt != 0)
	{
		string ChangeName = "";
		int ChangeScore = 0;
		int ChangeCnt = 0;
		int ChangeTrk = -1;

		cout << "지금 까지 입력 된 학생 정보입니다" << endl;
		Out(_pName, _pKor, _pEng, _pMath, _StdSize, _NumCnt);

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
			cout << ChangeName << " 의 변경할 점수를 입력하세요(국영수 순서) : ";
			cin >> ChangeScore;
			_pKor[ChangeCnt] = ChangeScore;
			cin >> ChangeScore;
			_pEng[ChangeCnt] = ChangeScore;
			cin >> ChangeScore;
			_pMath[ChangeCnt] = ChangeScore;

			cout << _pName[ChangeCnt] << " : " << _pKor[ChangeCnt] << ",\t" << _pEng[ChangeCnt] << ",\t" << _pMath[ChangeCnt]<< "로 정보가 변경 되었습니다" << endl;
		}
	}
	else
	{
		cout << "입력 된 학생이 없습니다!" << endl;
	}
	cout << endl << endl;
}