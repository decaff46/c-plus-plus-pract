#include <iostream>
#include <string>  // 스트링을 쓰는데 있어서 이게 왜 꼭 필요 할까?
using namespace std;

string  Rec_Name[5] = {};
int Rec_Scr[5] = {};
int Count = 0;
bool Isplaying = true;
int choice = 0;


void Add();
void Printout();
void Delete();
void Out();


void Menu()
{

		cout << "학생 명부 입니다" << endl;
		cout << "1. 입력" << endl;
		cout << "2. 출력" << endl;
		cout << "3. 삭제" << endl;
		cout << "4. 종료" << endl;
		cout << "선택 : ";

		cin >> choice;

		if (choice == 1)
		{
			Add();
		}
		if (choice == 2)
		{
			Printout();
		}
		if (choice == 3)
		{
			Delete();
		}
		if (choice == 4)
		{
			Out();
		}
		
		cout << endl;
	
}


void Add()
{
	string student;
	int Result = 0;
	string Answer;

	if (Count < 5)
	{
		cout << "입력할 학생 이름을 넣으세요 :";
		cin >> student;
		Rec_Name[Count] = student;
		cout << "학생의 성적을 기입하세요 : ";
		cin >> Result;
		Rec_Scr[Count] = Result;
		Count++;
		cout << "새로운 학생이 입력 되었습니다 !" << endl << endl;  
	}
	else
	{
		cout << "입력 가능한 최대 인원 5명을 초과 했습니다. 더 입력을 원할 경우 삭제해야 합니다" << endl;
		cout << "삭제 하시겠습니까? (예/아니오) 삭제하지 않을 경우 바로 출력합니다. ";
		cin >> Answer;
		if (Answer == "예")
		{
			Delete();
		}
		if (Answer == "아니오")
		{
			Printout();
		}
		/*else
		{
			cout << "\"예 / 아니오\"만 선택가능 합니다" << endl;
		}*/
	}
}


void Printout()
{
		int input = 0;

		if (Count != 0)
		{
			cout << "성적표를 출력합니다" << endl;
			for (int i = 0; i < Count; i++)
			{
				cout << Rec_Name[i] << " : " << Rec_Scr[i] << endl;
			}
		}
		else
		{
			cout << "입력 된 학생의 정보가 없습니다" << endl;
			cout << "학생의 정보를 입력하시려면 1번을 누르세요; 종료는 4번입니다. " << endl;
			cin >> input;
			if (input == 1)
			{
				Add();
			}
			if (input == 4)
			{
				Out();
			}
		}
}


void Delete()
{
	string Del_Name;
	int Del_Numb = -1;
	int DelCtr = 0;

	if (Count != 0)
	{
		cout << "지금까지 입력 된 학생 아이디 입니다. " << endl;
		for (int i = 0; i < Count; i++)
		{
			cout << Rec_Name[i] << ", ";
		}
		cout << endl;

		cout << " 삭제할 ID를 입력하세요 : ";
		cin >> Del_Name;


		while (DelCtr < Count)
		{
			if (Rec_Name[DelCtr] == Del_Name)
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
				Rec_Name[Del_Numb] = " ";
				Count--;
			}
			else
			{
				for (int i = Del_Numb; i < Count-1; i++)
				{
					Rec_Name[i] = Rec_Name[i + 1];
					Rec_Scr[i] = Rec_Scr[i + 1];
				}
				Count--;
			}
			cout << "삭제 했습니다" << endl;
		}

	}
	else
	{
		cout << "입력된 정보가 없습니다" << endl;
	}

	cout << endl;
}


void Out()
{
	cout << " 종료합니다 " << endl;
	Isplaying = false;
}


int main()
{
	while (Isplaying)
	{
		Menu();
	}
	return 0;
}
