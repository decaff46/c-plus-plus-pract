#include <iostream>
#include <string>
using namespace std;



void main()
{
	//�л� �ִ�� 5��, ����(������) ����, �л� �⺻ ����
	int Count = 0;
	const int Std_Max = 5;
	const int Scr_Max = 100;
	int Kor = 0, Eng = 0, Math = 0;

	string stdName = " ";
	string Std_Name[5] = {};
	int Kor_Result[5] = {};
	int Eng_Result[5] = {};
	int Math_Result[5] = {};

	char Answer = ' ';
	bool Continue = true;


	while (Continue)
	{
		if (Count < Std_Max)
		{
			for (int i = 0; i < Std_Max; i++)
			{
				cout << "�л��̸��� �Է��ϼ��� : ";
				cin >> stdName;
				cout << "���� ���� : ";
				cin >> Kor;
				if (Kor <= Scr_Max)
				{
					cout << "���� ���� : ";
					cin >> Eng;

					if (Eng <= Scr_Max)
					{
						cout << "���� ���� : ";
						cin >> Math;

						if (Math <= Scr_Max)
						{
							cout << stdName << " �� ������ ���� : " << Kor << " ���� : " << Eng << " ���� : " << Math << "�Դϴ�." << endl;
						}
						else
						{
							cout << "������ Ȯ���ϼ���! �ִ� " <<  Scr_Max;
							cin >> Math;
						}
					}
					else
					{
						cout << "������ Ȯ���ϼ���! �ִ� " << Scr_Max;
						cin >> Eng;
					}
				}
				else
				{
					cout << "������ Ȯ���ϼ���! �ִ� " << Scr_Max;
					cin >> Kor;
				}


				Count++;
				//�л� �̸� �� ���� ��� ����
				Std_Name[i] = stdName;
				Kor_Result[i] = Kor;
				Eng_Result[i] = Eng;
				Math_Result[i] = Math;

				cout << "���� �л��� ������ ����Ͻðڽ��ϱ�? (Y/N)";
				cin >> Answer;
				if (Answer == 'y' || Answer == 'Y')
				{
					Continue = true;
					Answer = ' ';
				}
				else
				{
					cout << "���ݱ��� " << Count << " ���� �л��� ������ �Է��߽��ϴ�." << endl;  
					
					////���⼭ ����ǥ�� ����ϰڴٴ� ����� ���� ������ ��ġ�� ����

					cout << "����ǥ�� ��� �Ͻðڽ��ϱ�?" << endl;
					cin >> Answer;
					if (Answer == 'y' || Answer == 'Y')
					{
						Continue = false;
					}
					else
					{
						Continue = true;
					}
				}
				cout << endl;
			}
		}
		else
		{
			cout << "����ǥ ��� �ο� �ִ� 5���� �ʰ� �߽��ϴ� ��� �Է� �Ͻðڽ��ϱ�?  �Է½� ���� �Էµ� �л����� ������ ���� �˴ϴ�" << endl;
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
			{
				cout << Count + 1 << "��° �л��� �̸��� �Է��ϼ��� : ";
				cin >> stdName;
				cout << "���� ���� : ";
				cin >> Kor;
				if (Kor <= Scr_Max)
				{
					cout << "���� ���� : ";
					cin >> Eng;

					if (Eng <= Scr_Max)
					{
						cout << "���� ���� : ";
						cin >> Math;

						if (Math <= Scr_Max)
						{
							cout << stdName << " �� ������ ���� : " << Kor << " ���� : " << Eng << " ���� : " << Math << "�Դϴ�." << endl;
						}
						else
						{
							cout << "������ Ȯ���ϼ���! �ְ� 100��" << endl;
							cout << "������ �Է��ϼ���! ���� ���� : ";
							cin >> Math;
						}
					}
					else
					{
						cout << "������ Ȯ���ϼ���! �ְ� 100��" << endl;
						cout << "������ �Է��ϼ���! ���� ���� : ";
						cin >> Eng;
					}
				}
				else
				{
					cout << "������ Ȯ���ϼ���! �ְ� 100��";
					cout << "������ �Է��ϼ���! ���� ���� : ";
					cin >> Kor;
				}


				Count++;

				//�л� �̸� �� ���� ��� ���� 
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


	//���� ���
	cout << "����ǥ�� ����մϴ�" << endl << endl;
	cout << "�̸� " << "	����	" << "����	 " << "����	 " << endl;
	for (int i = 0; i < Std_Max; i++)
	{
		cout << Std_Name[i] << "	" << Kor_Result[i] << "		" << Eng_Result[i] << "		" << Math_Result[i] << endl;
	}

}

