#include <iostream>
using namespace std; 

// check �Լ�ȭ �ϱ� 
//void Double_Check(Check) 
//{
//	cin >> Check; 
//}


int main ()
{
	//�⺻ ���� ���� 1.�л�	 2. ������� (++���� �ִ� ���� 100 ���� ���ϰ� ����)		3. �ִ� 5���� �л��� ����
	const	int		StdNumb = 5;
	const	int		SbjNumb = 3;
	char			Students[StdNumb] = { 'A', 'B', 'C', 'D','E' };
	int				Result[SbjNumb * StdNumb] = {};




	//���� �Է�
	int KorResult = 0, MathResult = 0, EngResult = 0;
	char Check = ' '; 

	for (int i = 0; i < StdNumb; i++)
	{
		for (int j = 0; j < SbjNumb; j++)
		{
			cout << Students[i] << "�� ������ �Է��ϼ���" << endl;
			cout << "���� ���� :";
			cin >> KorResult;
			cout << "���� ���� :";
			cin >> EngResult;
			cout << "���� ���� :";
			cin >> MathResult;
			cout << Students[i] << " �� ������ ���� :" << KorResult << "  ���� :" << EngResult << "  ���� :" << MathResult << "�� �½��ϱ�?(Y/N)" << endl;
			 
			cin >> Check;  // �Լ�ȭ ��Ű�� 
			if (Check == 'Y' || Check == 'y' || Check == 'N' || Check == 'n')
			{
				if (Check == 'Y' || Check == 'y')
				{
					cout << "���� �л��� ������ �����ϼ��� " << endl;
				}
				else
				{
					cout << Students[i] << "�� ������ '�ٽ�' �Է��ϼ���" << endl;
					cout << "���� ���� :";
					cin >> KorResult;
					cout << "���� ���� :";
					cin >> EngResult;
					cout << "���� ���� :";
					cin >> MathResult;
					cout << Students[i] << " �� ������ ���� :" << KorResult << "  ���� :" << EngResult << "  ���� :" << MathResult << "�� �½��ϱ�?(Y/N)" << endl;
					cin >> Check;
				}
			}
			else
			{
				cout << "Y / N �� �Է� �����մϴ�" << endl;
			}	

		}
		
		
	}

	bool IsStudent = true;

	// ����ǥ ���
	while (IsStudent)
	{
		cout << " ����ǥ�� ����մϴ�" << endl << endl;
		
		/*cout << "		����	����	����" << endl;			
		for (int i = 0; i < 5; i++)
		{
			cout << Students[i] << "	" << Result << endl;
		}  �׵θ��� ����� ������ �� �ȿ��ٰ� ��� �־ƾ� �ұ�?  */

		for (int i = 0; i < StdNumb; i++)
		{
			for (int j = 0; j < SbjNumb; j++)
			{
				cout << Result[StdNumb * j + i];
			}
			cout << endl;
		}

	}
		
	
	return 0;
}