#include <iostream>
using namespace std;

int main()
{

	// �� �⺻ ����
	int mAtk = 0;
	int mHP = 100;
	int mDef = 100;
	//int max_mAtk = 120; ���Ǹ� �ʹ����� �ߴٰ� ���ͼ��� ���� �ý��ϴ� 
	//int min_mAtk = 110;  ���� �� ���� 
	
	// �� �⺻ ����
	int yAtk = 110;
	int yHP = 100;
	int yDef = 80;
	
	
	do
	{
		int mHP = mHP - (mDef - yAtk);
		cout << "��밡 �����մϴ�" << endl;
		cout << "����� ü���� " << int mHP << "�������� ���� ��븦" << mAtk << "���ظ� �������ϴ�" << endl;
		cout << "����� ü���� " << int yHP << endl;
		cout << "���� ����Ʈ 110, 120 ���� �ϳ� �����ϼ��� (1: ũ��_�ִ� 3�� ��� ; 2: �Ϲ�) ";
		cin >> mAtk;
		//switch (mAtk)
		switch (mAtk)
		{
		case 120:
			//int mAtk = max_mAtk;
			int yHP = mHP + (mDef - yAtk);
			int crit = 0;
			for (crit == 0; crit <= 3; crit++)
			{
				if (crit > 3)
				{
					cout << " ũ���� �ִ��� ����߽��ϴ�" << endl;
				}
				else
				{
					cout << "ũ���� ����Ͽ����ϴ�. �ִ� ���ġ 120�� �����մϴ�. ���� ũ�� ���� " << 3 - crit << endl;
				}
			}
			break;

		case 110:
			//int mAtk = min_mAtk;
			cout << "�Ϲ� ������ ����Ͽ����ϴ�. �ִ� ����� 110. ���� ũ�� ���� " << 3 - crit << endl;
			break;

		default:
			cout << " 1 // 2 ���� �ϳ��� ��� �����մϴ�" << endl;
			break;
		}
	}
	while (mHP > 0 || yHP > 0)
	{
		if (mATk == 120 || mAtk == 110)
		{
			
		}
	}

	

	

	return 0;
}