#include <iostream>
using namespace std; 

int main() 
{
	
	// �� �⺻ ����
	int mAtk = 0;
	int mHP = 100; 
	int mDef = 100; 
	int max_mAtk = 120;
	int min_mAtk = 110;


	// �� �⺻ ����
	int yAtk = 110;
	int yHP = 100;
	int yDef = 80;

	/*   ����� hp�� ���� �� ���� ġ��Ÿ�� ������ �;��µ� �𸣰ڳ׿� ~ ����
	int max_mAtk = 130;
	*/

	

	// ����� �ѹ� �� �����Ѵ�

	while (mHP > 0 || yHP > 0)
	{
		cout << "1,2�� �����ϼ��� (1: ũ�� (�ִ� 3�� ��밡��) ; 2: �Ϲ�)  ";
		cin >> mAtk;
				
			switch (mAtk)
			{
			case 1:
				int mAtk = max_mAtk;
				cout << "1�� �����ϼ̽��ϴ� �����ϰڽ��ϴ�" << endl;
				int crit = 3; 
				if (crit == 3; crit == 0; crit--) //crit�� �ִ� 3���� ����ϰ� �ͽ��ϴ�
				break;
			case 2:
				int mAtk = min_mAtk;
				cout << "2�� �����ϼ̽��ϴ�. �����ϰڽ��ϴ�" << endl;
				break;
			default:
				cout << "1�� 2 �� ���� �ϳ��� �����϶��!" << endl;
				break;
			}
		}

		int mHP = mHP + (mDef - yAtk);
		int yHP = yHP + (yDef - mAtk);

	}
	
	return 0;
}