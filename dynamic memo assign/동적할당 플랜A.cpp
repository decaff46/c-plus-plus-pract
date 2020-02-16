#include <iostream>
#include <string>
using namespace std; 


void Menu(int Num_Std, int Count, string *pName_Std, int *pScr_Std);


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

void Print(int &_Count,string *pName, int *pScore)
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
		else
		{
			cout << "처음 입력한 최대 인원을 초과했습니다! 기존 인원 중 삭제 해야 가능합니다" << endl;
			Del (_Count,  pName_Std,  pScr_Std);
		}
}

void Menu(int Num_Std, int Count, string *pName_Std,int *pScr_Std)
{
	int Input = 0;

	while (true)
	{
		cout << " 1.정보 입력 " << endl;
		cout << " 2.정보 출력 " << endl;
		cout << " 3.정보 변경 " << endl;
		cout << " 4.정보 삭제 " << endl;
		//cout << " 5.파일 종료 " << endl;


		cin >> Input;
		switch (Input)
		{
		case 1: Add(Num_Std, pName_Std, pScr_Std, Count); break;
		case 2: Print(Count, pName_Std, pScr_Std); break;
		case 3: Edit(Count, pName_Std, pScr_Std); break;
		case 4: Del(Count, pName_Std, pScr_Std); break;
		//case 5: cout << "시스템을 종료합니다!" << endl; break;
		}
	}
}


void main()
{	
	int Num_Std = 0;
	int Count = 0;
	string *pName_Std = nullptr;
	int *pScr_Std = nullptr;
	
	cout << " 총 학생 수를 입력 하세요 " << endl;
	cin >> Num_Std;

	cout << endl << endl;
	
	if (Num_Std == 0)
	{
		cout << "학생 수가 0일 수 없습니다" << endl;
		main();
	}
	else 
	{
		cout << Num_Std<< "명의 성적표 관리를 시작 합니다 " << endl<< endl;

		if (pName_Std == nullptr && pScr_Std == nullptr)
		{
			pName_Std = new string[Num_Std];
			pScr_Std = new int[Num_Std];
		}

		Menu(Num_Std, Count, pName_Std, pScr_Std);
	}

	delete[] pName_Std; delete[] pScr_Std;
	pName_Std = nullptr; pScr_Std = nullptr; 
}