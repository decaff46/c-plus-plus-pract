#include <iostream>
#include <string>
using namespace std;

/*
성적표 동적할당 컨텐츠 추가

B.	아예 무제한 입력이 가능
- 일정공간을 미리 확보해서 입력을 받는다.
- 입력공간이 꽉차면 더 큰공간을 확보해서 데이터를 이동시킨다.
*/

bool Playing = true;

void Menu(int Num_Std, int Count, string *pName_Std, int *pScr_Std);
void Del(int &_Count, string *pName, int *pScore);
void Print(int &_Count, string *pName, int *pScore);
void Edit(int &_Count, string *pName, int *pScore);
void Add(int Num_Std, string *pName_Std, int *pScr_Std, int &_Count);

void Del(int &_Count, string *pName, int *pScore)
{
	string Del_Name;
	int Del_Numb = -1;
	int DelCtr = 0;

	if (_Count != 0)
	{
		cout << "지금까지 입력 된 학생 입니다. " << endl;
		for (int i = 0; i < _Count; i++)
		{
			cout << pName[i] << ", ";
		}
		cout << endl;

		cout << " 삭제할 이름을 입력하세요 : ";
		cin >> Del_Name;


		while (DelCtr < _Count)
		{
			if (pName[DelCtr] == Del_Name)
			{
				Del_Numb = DelCtr;
				break;
			}
			DelCtr++;
		}


		if (Del_Numb == -1)
		{
			cout << "삭제할 학생의 정보를 찾을 수 없습니다" << endl;
		}
		else
		{
			if (_Count == Del_Numb)
			{
				pName[Del_Numb] = " ";
				_Count--;
			}
			else
			{
				for (int i = Del_Numb; i < _Count - 1; i++)
				{
					pName[i] = pName[i + 1];
					pScore[i] = pScore[i + 1];
				}
				_Count--;
			}
			cout << Del_Name << "을 리스트에서 삭제 했습니다" << endl;
		}

	}
	else
	{
		cout << "입력된 정보가 없습니다" << endl;
	}

	cout << endl;
}

void Print(int &_Count, string *pName, int *pScore)
{
	if (_Count != 0)
	{
		cout << _Count << "명 학생의 정보를 출력합니다" << endl << endl;
		for (int i = 0; i < _Count; i++)
		{
			cout << pName[i] << " : " << pScore[i] << endl;
		}
		cout << endl;
		cout << "입력 된 학생의 정보를 모두 출력하였습니다" << endl << endl;
	}
	else
	{
		cout << "입력 된 정보가 없습니다 " << endl << endl;
	}
}

void Edit(int &_Count, string *pName, int *pScore)
{
	string change_std;
	string new_name;
	int new_scr = 0;
	int change_scr = 0;
	int changectr = 0;
	int editctr = -1;
	int Choice = 0;

	if (_Count != 0)
	{
		Print(_Count, pName, pScore);
		cout << endl;

		cout << "변경을 원하는 학생의 이름을 입력하세요 : ";
		cin >> change_std;

		while (changectr < _Count)
		{
			if (pName[changectr] == change_std)
			{
				editctr = changectr;
				break;
			}
			changectr++;
		}

		if (editctr == -1)
		{
			cout << "학생 정보를 찾을 수 없습니다" << endl;
			Edit(_Count, pName,  pScore);
		}
		else
		{
			cout << "변경할 이름을 입력하세요 : ";
			cin >> new_name;
			pName[changectr] = new_name;
			cout << new_name << " 의 변경할 점수를 입력하세요 : ";
			cin >> new_scr;
			pScore[change_scr] = new_scr;

			cout << pName[changectr] << " : " << pScore[changectr] << "로 정보가 변경 되었습니다" << endl;
		}

		cout << endl;
	}
}

void Add(int Num_Std, string *pName_Std, int *pScr_Std, int &_Count)
{
	string Names;
	int Score = 0;
	int Choice = 0;
	int Addmore = 0;

	if (_Count < Num_Std )
	{
		cout << "새롭게 입력할 학생의 이름과 성적을 기입하세요" << endl;
		cout << "학생 이름 : ";
		cin >> Names;
		pName_Std[_Count] = Names;
		cout << "점수 : ";
		cin >> Score;
		pScr_Std[_Count] = Score;

		_Count++;

		cout << "새로운 학생의 정보가 입력 되었습니다" << endl;
		cout << "계속 등록 하시겠습니까? (예 = 1 // 아니오 = 2) ";
		cin >> Choice;

		cout << endl << endl;

		switch (Choice)
		{
		case 1: Add(Num_Std, pName_Std, pScr_Std, _Count); break;
		case 2: Menu(Num_Std, _Count, pName_Std, pScr_Std); break;
		}
	}

	//추가 인원 발생시 초과 인원을 더 받아서 용량 늘리기 
	else
	{
		// 1. 초과 인원을 입력 받음 
		cout << "처음 입력한 최대 인원을 초과했습니다! 초과 인원을 입력하세요 ";
		cin >> Addmore; 

		// 2. 기존의 정보 복사하기 위한 배열 생성
		string *pNew_Std = nullptr;
		int *pNew_Scr = nullptr;
	

		if (pNew_Std == nullptr && pNew_Scr == nullptr)
		{
			pNew_Std = new string[Num_Std + Addmore];
			pNew_Scr = new int[Num_Std + Addmore];
		}

		// 3. 기존 정보 복사 
		for (int i = 0; i < Num_Std ; i++)
		{
			pNew_Std[i]  = pName_Std[i];
			pNew_Scr[i]  = pScr_Std[i];
		}


		// 4. 기존 정보 용량 늘리기 
		pName_Std = new string[Num_Std + Addmore];
		pScr_Std  = new int[Num_Std + Addmore];


		// 5. 기존 용량에 다시 붙여 넣기 
		for (int i = 0; i < Num_Std; i++)
		{
			pName_Std[i] = pNew_Std[i];
			pScr_Std[i] = pNew_Scr[i];
		}

		Num_Std += Addmore;


		cout << "초과 인원에 따른 용량을 추가했습니다 계속 입력하겠습니까? (예 = 1/ 아니요 =2)" << endl;
		cin >> Choice;
		switch (Choice)
		{
		case 1: Add(Num_Std, pName_Std, pScr_Std, _Count);
		case 2: Menu(Num_Std, _Count, pName_Std, pScr_Std);
		}

	}
}


// 왜 여기서 while (true)를 하면 안꺼지지... ㅠㅠ
void  Menu(int Num_Std, int Count, string *pName_Std, int *pScr_Std)
{
	int Input = 0;

	while (Playing)
	{
		cout << " 1.정보 입력 " << endl;
		cout << " 2.정보 출력 " << endl;
		cout << " 3.정보 변경 " << endl;
		cout << " 4.정보 삭제 " << endl;
		cout << " 5.파일 종료 " << endl;


		cin >> Input;
		switch (Input)
		{
		case 1: Add(Num_Std, pName_Std, pScr_Std, Count); break;
		case 2: Print(Count, pName_Std, pScr_Std); break;
		case 3: Edit(Count, pName_Std, pScr_Std); break;
		case 4: Del(Count, pName_Std, pScr_Std); break;
		case 5: cout << "시스템을 종료합니다!" << endl; Playing = false;  break;
		}
	}
}


void main()
{
	int Num_Std = 0;
	int Count = 0;
	string *pName_Std = nullptr;
	int *pScr_Std = nullptr;

	cout << "총 학생 수를 입력 하세요 " << endl;
	cin >> Num_Std;

	cout << endl << endl;

	while (Playing)
	{
		if (Num_Std <= 0)
		{
			cout << "학생 수가 0일 수 없습니다" << endl;
			main();
		}
		else
		{
			cout << Num_Std << "명의 성적표 관리를 시작 합니다 " << endl << endl;

			if (pName_Std == nullptr && pScr_Std == nullptr)
			{
				pName_Std = new string[Num_Std];
				pScr_Std = new int[Num_Std];
			}

			Menu(Num_Std, Count, pName_Std, pScr_Std);
		}
	}
	delete[] pName_Std; delete[] pScr_Std;
	pName_Std = nullptr; pScr_Std = nullptr;
}