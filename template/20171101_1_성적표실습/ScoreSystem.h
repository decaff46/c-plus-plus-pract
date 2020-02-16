#pragma once

#include <iostream>
using namespace std;

#include "MyVector.h"

//상수들
const	int		MAXCOUNT = 5;

struct ScoreSystem
{
	struct StdInfo
	{
		int Id;
		int Score;
	};

	//변수들
	bool	IsPlaying = true;
	int		Input = 0;

	//	학생 정보
	//StdInfo	StdData[MAXCOUNT];
	MyVector<StdInfo>	StdData;

	int		NowStudentCount = 0;

	//	내부에서만 사용
	void MenuOutput();
	void MenuInput();

	void InfoInput();
	void InfoDelete();
	void InfoOutput();

	//	외부에서 사용
	void Strat();
};

void ScoreSystem::MenuOutput()
{
	cout << "1. 입력" << endl;
	cout << "2. 출력" << endl;
	cout << "3. 삭제" << endl;
	cout << "4. 종료" << endl;
}

void ScoreSystem::MenuInput()
{
	cout << "선택 : ";
	cin >> Input;

	//	깔끔하게 보이고 싶어서 한줄 더 개행
	cout << endl;
}

void ScoreSystem::InfoInput()
{
	StdInfo	Input;

	cout << "ID 입력 : ";
	cin >> Input.Id;

	cout << "점수 입력 : ";
	cin >> Input.Score;

	//	데이터 입력
	StdData.Push_Back(Input);

	// 입력 끝나고 한줄 띄어서 깔끔하게
	cout << endl;
}

void ScoreSystem::InfoDelete()
{
	int		DelID = 0;
	int		DelIndex = -1;

	if (StdData.Size == 0)
	{
		cout << "삭제할 정보가 없습니다." << endl << endl;
	}
	else
	{
		//	삭제할 ID 입력받기 
		cout << "삭제할 ID 입력 : ";
		cin >> DelID;

		//	삭제할 ID를 찾는다.
		for (int i = 0; i < StdData.Size; i++)
		{
			if (StdData[i].Id == DelID)
			{
				DelIndex = i;
				break;
			}
		}

		//	못찾은거
		if (DelIndex == -1)
		{
			cout << "삭제할 ID가 없습니다." << endl;
		}
		else
		{
			//	삭제
			for (int i = DelIndex; i < StdData.Size-1; i++)
			{
				StdData[i] = StdData[i + 1];
			}

			StdData.Pop_Back();
		}
	}
}

void ScoreSystem::InfoOutput()
{
	cout << "성적출력" << endl;

	for (int i = 0; i < StdData.Size; i++)
	{
		cout << StdData[i].Id << " : " << StdData[i].Score << endl;
	}

	cout << "출력종료" << endl << endl;
}

void ScoreSystem::Strat()
{
	//반복문시작
	while (IsPlaying)
	{
		//메뉴출력
		MenuOutput();
		//메뉴선택(입력)
		MenuInput();

		//처리(분기문)
		switch (Input)
		{
		case 1:	//	입력
			InfoInput();
			break;

		case 2:	//	출력
			InfoOutput();
			break;

		case 3:	//	삭제
			InfoDelete();
			break;
		case 4:
			IsPlaying = false;
			break;
		}
	}
}