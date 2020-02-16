#include <iostream>
#include <string>
using namespace std;


void Menu()
{
	cout << "1. 입력" << endl;
	cout << "2. 출력" << endl;
	cout << "3. 삭제" << endl;
	cout << "4. 종료" << endl;
	cout << "선택 : ";
}





void main()
{
	int Input = 0;
	int ID = 0;
	int Scr = 0;
	int Rec_Id[5] = {};
	int Rec_Scr[5] = {};
	const int Max = 5; 
	int Count = 0;
	bool Isplaying = true;
	string Answer;
	int Del_Id = -1;
	

	while (Isplaying)
	{

		Menu();
		cin >> Input;

		cout << endl << endl;

		switch (Input)
		{
		case 1:
			cout << "ID 입력 : ";
			cin >> ID;
			cout << "점수 입력 : "; // 국영수 나중에  세분화
			cin >> Scr;

			if (Count+1 < Max)
			{
				Rec_Id[Count] = ID;
				Rec_Scr[Count] = Scr;
				Count++; 
			}
			else
			{
				cout << " 최대 입력 인원 (5명)을 초과했습니다" << endl;
				cout << " 더 입력 하기 위해선 삭제 해야 합니다. 삭제 하시겠습니까? " << endl;
				cin >> Answer;

				if (Answer == "예")
				{
					Input = 3;
					break;
				}
				else
				{
					cout << "다섯명의 성적표를 출력합니다" << endl;
					Input = 2; 
					break;
				}
			}
			
			cout << endl;
			break;

		case 2:
			if (Count != 0)
			{
				cout << "성적 출력" << endl;
				for (int i = 0; i < Count; i++)
				{
					cout << Rec_Id[i] << " : " << Rec_Scr[i] << endl;
				}
				cout << "출력 완료!" << endl;

			}
			else
			{
				cout << "출력 정보 없음" << endl;
			}

			cout << endl;
			break;

		case 3:
			//int Del_Id = -1;  왜 여깄으면 안되는 걸까??
			if (Count != 0)
			{
				cout << "지금까지 입력 된 학생 아이디 입니다. " << endl;
				for (int i = 0; i < Count; i++)
				{
					cout << Rec_Id[i] << ", " ;
				}
				cout << endl;
				cout << " 삭제할 ID를 입력하세요 : ";
				cin >> Del_Id;
				
				int Del_Count = 0;
				while (Del_Count < Count)
				{
					if (Rec_Id[Del_Count] == Del_Id) 
					{
						Del_Id = Del_Count; 
						break;
					}
					Del_Count ++ ;
				}
				if (Del_Id == -1)
				{
					cout << "학생의 정보를 찾을 수 없습니다" << endl;
				}
				else
				{
					if (Count == Del_Id)
					{
						Count--;
						Rec_Id[Del_Id]= NULL;
					}
					else
					{
						for (int i = Del_Id; i < Count; i++)
						{
							Rec_Id[i] = Rec_Id[i + 1];
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
			break;

		case 4: 
			cout << "종료" << endl;
			Isplaying = false;

			cout << endl;
			break;

		default: 
			cout << " 1,2,3,4 중에서 선택하세요 ";
			cout << endl << endl;
			break;
		}

	}
	
}
