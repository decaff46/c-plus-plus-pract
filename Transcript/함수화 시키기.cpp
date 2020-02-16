#include <iostream>
#include <string>
using namespace std;

void Record () // 함수에서요 ~ 이거 정말 어떻게 쓰는 걸까요? 걍 긁어다가 만들기만 했을뿐 원하는 모양 
			   // Record(변수)의 모양은 어찌 해야 할 지 모르겠네요 ㅎ 
{
	int Count = 0;
	int Kor = 0, Eng = 0, Math = 0;

	string stdName = " ";
	string Std_Name[5] = {};
	int Kor_Result[5] = {};
	int Eng_Result[5] = {};
	int Math_Result[5] = {};

	char Answer = ' ';



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

void Printout()
{
	int Count = 0;
	int Kor = 0, Eng = 0, Math = 0;

	string stdName = " ";
	string Std_Name[5] = {};
	int Kor_Result[5] = {};
	int Eng_Result[5] = {};
	int Math_Result[5] = {};
	char Answer = ' ';

	cout << "성적표를 출력합니다" << endl << endl;
	cout << "이름 " << "	국어	 " << "		영어	" << "		수학	 " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << Std_Name[i] << "	" << Kor_Result[i] << "		" << Eng_Result[i] << "		" << Math_Result[i] << endl;
	}
}

void main()
{
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
	while (Continue)  // 여기서 while 룹을 빠져 나갈 생각을 안하는건 분명 Count 값이 메인에서는 반영이 안되서 그런거 같은데 ....
	{
		if (Count < 5)
		{
			Record();
		}
		else
		{
			cout << "성적표 출력 인원 최대 5명을 초과 했습니다 계속 입력 하시겠습니까?"
				" 입력시 기존 입력된 학생들의 정보는 삭제 됩니다" << endl;
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
			{
				cout << Count + 1 << "번째 학생의 이름을 입력하세요 : ";
				Record();
			}
			else
			{
				Continue = false;
			}
		}
	}


	//정보 출력
	Printout();

}

