#include <iostream>
#include <string>
using namespace std;

void Record () // �Լ������� ~ �̰� ���� ��� ���� �ɱ��? �� �ܾ�ٰ� ����⸸ ������ ���ϴ� ��� 
			   // Record(����)�� ����� ���� �ؾ� �� �� �𸣰ڳ׿� �� 
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
		cout << "�л��̸��� �Է��ϼ��� : ";
		cin >> stdName;
		cout << "���� ���� : ";
		cin >> Kor;
		cout << "���� ���� : ";
		cin >> Eng;
		cout << "���� ���� : ";
		cin >> Math;
		cout << stdName << " �� ������ ���� : " << Kor << " ���� : " << Eng << " ���� : " << Math << "�Դϴ�." << endl << endl;


		Count++;

		//�л� �̸� �� ���� ��� ����
		Std_Name[i] = stdName;
		Kor_Result[i] = Kor;
		Eng_Result[i] = Eng;
		Math_Result[i] = Math;

		cout << "���� �л��� ������ �����ϼ���! " << endl;

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

	cout << "����ǥ�� ����մϴ�" << endl << endl;
	cout << "�̸� " << "	����	 " << "		����	" << "		����	 " << endl;
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

	// ���� �Է� �ޱ�
	while (Continue)  // ���⼭ while ���� ���� ���� ������ ���ϴ°� �и� Count ���� ���ο����� �ݿ��� �ȵǼ� �׷��� ������ ....
	{
		if (Count < 5)
		{
			Record();
		}
		else
		{
			cout << "����ǥ ��� �ο� �ִ� 5���� �ʰ� �߽��ϴ� ��� �Է� �Ͻðڽ��ϱ�?"
				" �Է½� ���� �Էµ� �л����� ������ ���� �˴ϴ�" << endl;
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
			{
				cout << Count + 1 << "��° �л��� �̸��� �Է��ϼ��� : ";
				Record();
			}
			else
			{
				Continue = false;
			}
		}
	}


	//���� ���
	Printout();

}

