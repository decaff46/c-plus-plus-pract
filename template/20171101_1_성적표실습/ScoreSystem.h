#pragma once

#include <iostream>
using namespace std;

#include "MyVector.h"

//�����
const	int		MAXCOUNT = 5;

struct ScoreSystem
{
	struct StdInfo
	{
		int Id;
		int Score;
	};

	//������
	bool	IsPlaying = true;
	int		Input = 0;

	//	�л� ����
	//StdInfo	StdData[MAXCOUNT];
	MyVector<StdInfo>	StdData;

	int		NowStudentCount = 0;

	//	���ο����� ���
	void MenuOutput();
	void MenuInput();

	void InfoInput();
	void InfoDelete();
	void InfoOutput();

	//	�ܺο��� ���
	void Strat();
};

void ScoreSystem::MenuOutput()
{
	cout << "1. �Է�" << endl;
	cout << "2. ���" << endl;
	cout << "3. ����" << endl;
	cout << "4. ����" << endl;
}

void ScoreSystem::MenuInput()
{
	cout << "���� : ";
	cin >> Input;

	//	����ϰ� ���̰� �; ���� �� ����
	cout << endl;
}

void ScoreSystem::InfoInput()
{
	StdInfo	Input;

	cout << "ID �Է� : ";
	cin >> Input.Id;

	cout << "���� �Է� : ";
	cin >> Input.Score;

	//	������ �Է�
	StdData.Push_Back(Input);

	// �Է� ������ ���� �� ����ϰ�
	cout << endl;
}

void ScoreSystem::InfoDelete()
{
	int		DelID = 0;
	int		DelIndex = -1;

	if (StdData.Size == 0)
	{
		cout << "������ ������ �����ϴ�." << endl << endl;
	}
	else
	{
		//	������ ID �Է¹ޱ� 
		cout << "������ ID �Է� : ";
		cin >> DelID;

		//	������ ID�� ã�´�.
		for (int i = 0; i < StdData.Size; i++)
		{
			if (StdData[i].Id == DelID)
			{
				DelIndex = i;
				break;
			}
		}

		//	��ã����
		if (DelIndex == -1)
		{
			cout << "������ ID�� �����ϴ�." << endl;
		}
		else
		{
			//	����
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
	cout << "�������" << endl;

	for (int i = 0; i < StdData.Size; i++)
	{
		cout << StdData[i].Id << " : " << StdData[i].Score << endl;
	}

	cout << "�������" << endl << endl;
}

void ScoreSystem::Strat()
{
	//�ݺ�������
	while (IsPlaying)
	{
		//�޴����
		MenuOutput();
		//�޴�����(�Է�)
		MenuInput();

		//ó��(�б⹮)
		switch (Input)
		{
		case 1:	//	�Է�
			InfoInput();
			break;

		case 2:	//	���
			InfoOutput();
			break;

		case 3:	//	����
			InfoDelete();
			break;
		case 4:
			IsPlaying = false;
			break;
		}
	}
}