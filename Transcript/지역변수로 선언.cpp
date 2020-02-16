#include <iostream>
#include <string>
using namespace std;

//애들은 정말 지역 변수로 함수화 시키는 법을 모르겠습니다 ㅎㅎ 
string Rec_std[5] = {};
int Rec_scr[5] = {};
int Count = 0;
bool Isplaying = true;

void Del();
void Print();
void Add();
void Students();
void Edit();
void Menu();
void Change(int &_changectr, string &_Nname, int &_Nscr); 
void Ask(string &_input); //오버로드라고 뜨는데 이건 뭘까요? 

void Ask(string &_input)
{
	cout << "입력 된 학생의 정보가 없습니다 학생 정보를 입력하시겠습니까? 예/아니오. 입력하지 않을 경우 메뉴로 돌아 갑니다.";
	cin >> _input;

	if (_input == "예")
	{
		Add();
	}
	if (_input == "아니오")
	{
		Menu();
	}
	cout << endl;
}

void Change(int &_changectr, string &_Nname, int &_Nscr)
{
	cout << "변경할 이름을 입력하세요 : ";
	cin >> _Nname;
	Rec_std[_changectr] = _Nname;
	cout << _Nname <<  " 의 변경할 점수를 입력하세요 : " ;
	cin >> _Nscr;
	Rec_scr[_changectr] = _Nscr;

	cout << Rec_std[_changectr] << " : " << Rec_scr[_changectr] << "로 정보가 변경 되었습니다" << endl;
}

#pragma region  Out(); 의미 없음 
//void Out()
//{
//	cout << "시스템을 종료합니다" << endl;
//	Isplaying = false;
//	
//} // 왜 꺼지지 않지??? ㅎㅎㅎ 
#pragma endregion

void Edit()
{

	string change_std;
	string new_name;
	int new_scr;
	int change_scr = 0;
	int changectr = 0;
	int editctr = -1;
	string input;
	
	if (Count != 0)
	{
		Print(); 
		cout << endl;

		cout << "변경을 원하는 학생의 이름을 입력하세요 : ";
		cin >> change_std;

		while (changectr < Count)
		{
			if (Rec_std[changectr] == change_std)
			{
				editctr = changectr;
				break;
			}
			changectr++;
		}
		
		if (editctr == -1)
		{
			cout << "학생 정보를 찾을 수 없습니다" << endl;
			Edit();
		}
		else
		{
			Change(changectr, new_name, new_scr);
		}

		cout << endl;
	}
	else
	{
		Ask(input);
	}	
}

void Del() // 왜 지금 삭제를 하는데 삭제가 앞에서 부터 일어 나는거지? 분명 동일하게 한것 같은데;; 
{
	string Del_Name;
	int Del_Numb = -1;
	int DelCtr = 0;

	if (Count != 0)
	{
		cout << "지금까지 입력 된 학생 입니다. " << endl;
		for (int i = 0; i < Count; i++)
		{
			cout << Rec_std[i] << ", ";
		}
		cout << endl;

		cout << " 삭제할 이름을 입력하세요 : ";
		cin >> Del_Name;


		while (DelCtr < Count)
		{
			if (Rec_std[DelCtr] == Del_Name)
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
			if (Count == Del_Numb)
			{
				Rec_std[Del_Numb] = " ";
				Count--;
			}
			else
			{
				for (int i = Del_Numb; i < Count-1; i++)
				{
					Rec_std[i] = Rec_std[i + 1];
					Rec_scr[i] = Rec_scr[i + 1];
				}
				Count--;
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

void Print()
{
	string input;

	if (Count != 0)
	{
		cout << "학생 정보를 출력합니다" << endl << endl;
		for (int i = 0; i < Count; i++)
		{
			cout << Rec_std[i] << " : " << Rec_scr[i] << endl;
		}
		cout << endl;
		cout << "입력 된 학생의 정보를 모두 출력하였습니다" << endl << endl;
	}
	else
	{
		Ask(input);
	}
}

void Add()
{
	string students; 
	int score = 0;
	string input;
	
	if (Count < 5)
	{
		cout << "새롭게 입력할 학생의 이름과 성적을 기입하세요" << endl;
		cout << "학생 이름 : ";
		cin >> students;
		Rec_std[Count] = students;
		cout << "점수 : ";
		cin >> score;
		Rec_scr[Count] = score;
		Count++;

		cout << "새로운 학생의 정보가 입력 되었습니다" << endl;
		cout << "계속 등록 하시겠습니까?" << endl;
		cin >> input;
		if (input == "예")
		{
			Add();
		}
		if (input == "아니오")
		{
			Students();
		}
	}
	else
	{
		cout << "입력 최대 학생수 (5명)을 초과 했습니다 더 입력을 원할 경우 삭제 해야 합니다" << endl;
		cout << "삭제 하시겠습니까? (예/아니오) 삭제 하지 않을 경우 지금까지 입력된 정보를 출력합니다";
		cin >> input;
		if (input == "예")
		{
			Del();
		}
		if (input == "아니오")
		{
			Print();
		}
		cout << endl;
	}	
}

void Students()
{

	while (true)
	{
		int choice = 0;
		cout << " 원하는 숫자를 입력하세요 " << endl;
		cout << "1. 정보 입력" << endl;
		cout << "2. 정보 변경" << endl;
		cout << "3. 정보 삭제" << endl;
		cout << "4. 정보 출력" << endl;
		cout << "5. 매뉴 가기" << endl;
		cout << " >> ";
		cin >> choice;

		if (choice == 1)
		{
			Add();
		}
		if (choice == 2)
		{
			Edit();
		}
		if (choice == 3)
		{
			Del();
		}
		if (choice == 4)
		{
			Print();
		}
		if (choice == 5)
		{
			break;
		}
	}	
	cout << endl;
	
}

void Menu()
{
	int choice = 0;
	while (true) // 여기서 3번을 누르면 break를 걸고 while을 나가서 꺼질 수는 없나? 
	{
		cout << "성적표 숙제 지역변수 함수화 도전!!!" << endl;
		cout << "1. 학생 정보" << endl;
		cout << "2. 정보 출력" << endl;
		cout << "3. 종료" << endl;
		cout << " >> ";
		cin >> choice;

		if (choice == 1)
		{
			Students();
		}
		if (choice == 2)
		{
			Print();
		}
		if (choice == 3)
		{
			cout << "시스템을 종료합니다" << endl;
			break;
		}
	}
}


void main()
{
	while (Isplaying)
	{
		Menu();
	}
}