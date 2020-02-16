#include <iostream>
#include <string>
using namespace std; 



void main()
{
	//학생 최대수 5명, 과목(국영수) 점수, 학생 기본 정보
	int Count = 0;
	int Kor = 0, Eng = 0, Math = 0;

	string stdName = " ";
	string Std_Name[5] = {};
	int Kor_Result[5] = {};
	int Eng_Result[5] = {};
	int Math_Result[5] = {};

	char Answer = ' ';
	bool Continue = true;


	// 정보 입력 받기
	while (Continue)
	{
		if (Count < 5)
		{
			for (int i = 0; i < 5; i++)
			{
				cout << "학생이름을 입력하세요 : ";
				cin >> stdName;
				cout << "국어 점수 : ";
				cin >> Kor;
				cout << "영어 점수 : ";
				cin >> Eng;
				cout << "수학 점수 : ";
				cin >> Math;
				cout << stdName << " 의 점수는 국어 : " << Kor << " 영어 : " << Eng << " 수학 : " << Math << "입니다." << endl << endl;


				Count++;

				//학생 이름 및 점수 기록 저장
				Std_Name[i] = stdName;
				Kor_Result[i] = Kor;
				Eng_Result[i] = Eng;
				Math_Result[i] = Math;

				cout << "다음 학생의 점수를 기입하세요! " << endl;
		
			}
		}
		else
		{
			cout << "성적표 출력 인원 최대 5명을 초과 했습니다 계속 입력 하시겠습니까?"
				" 입력시 기존 입력된 학생들의 정보는 삭제 됩니다" << endl;

			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
			{
				cout << Count+1 << "번째 학생의 이름을 입력하세요 : ";
				cin >> stdName;
				cout << "국어 점수 : ";
				cin >> Kor;
				cout << "영어 점수 : ";
				cin >> Eng;
				cout << "수학 점수 : ";
				cin >> Math;
				cout << stdName << " 의 점수는 국어 : " << Kor << " 영어 : " << Eng << " 수학 : " << Math << "입니다." << endl;

				Count++;

				//학생 이름 및 점수 기록 삭제 
				for (int i = 0; i < 4; i++)
				{
					Std_Name[i] = Std_Name[i + 1];
					Kor_Result[i] = Kor_Result[i + 1];
					Eng_Result[i] = Eng_Result[i + 1];
					Math_Result[i] = Math_Result[i];
				}

				Std_Name[4] = stdName;
				Kor_Result[4] = Kor;
				Eng_Result[4] = Eng;
				Math_Result[4] = Math;

			}
			else
			{
				Continue = false;
			}

		}
	}


	//정보 출력
	cout << "성적표를 출력합니다" << endl << endl;
	cout << "이름 " << "	국어	 " << "		영어	" << "		수학	 "  << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << Std_Name[i] << "	" << Kor_Result[i] << "		" << Eng_Result[i] << "		" << Math_Result[i] << endl;
	}
			
}

