#include <iostream>
using namespace std; 

int main()
{
	int count = 0;

	int my_hp = 100;
	int you_hp = 100;
	int you_atk = 4;
	
	
	/*int atk = 0;
	int crit = 0;
	while (crit <= 3)
	{
	
		cout << "������ ����Ʈ�� �Է��ϼ��� (1: ũ��- ������10, 2: �Ϲ�- ������ 5)"; 
		cout << "ũ�� �������� �ִ� 3���� ��� �����մϴ�: << endl;
		cin >> atk; 
		if (crit > 3)
		{
		cout << "ũ���� �ִ��� ����Ͽ����ϴ�! �Ϲ� ������ ���ϰڽ��ϴ�. " << endl;
		atk == 2; 
		}
	
		switch (atk)
		{
		case 1: 
			crit++;

			cout << "���濡�� ������ ������ ���մϴ� " << endl;
			you_hp = you_hp - 10; 
			cout << "������ ���� ü���� " << you_hp << "�Դϴ� " << endl;
			break; 
		case 2:
			cout << "���濡�� �Ϲ� ������ ���մϴ�." << endl;
			you_hp = you_hp - 10;
			cout << "������ ���� ü���� " << you_hp << "�Դϴ� " << endl;
			break;
		default: 
			cout << "1,2 ���� �ϳ��� �����ϼ���!!" << endl;
			break;
		}
	}*/
	
	// Ȧ���϶� ���� ���� ¦���϶� ��밡 ����

	int my_atk = 5;
	
	while (my_hp > 0 || you_hp > 0)
	{
		for (count = 0; count <= 25; count++) // ���⼭ 25 ���� �ٸ� ����� �������? 
		{
			count = count % 2;
			if (count != 0)
			{
				cout << "���� �����մϴ�" << endl;
				you_hp = you_hp - my_atk;
				cout << "������ HP�� " << you_hp << "�Դϴ�" << endl << endl;
			}
			else {
				cout << "���� �����մϴ�" << endl;
				my_hp = my_hp - you_atk;
				cout << "���� HP �� " << my_hp << "�Դϴ�" << endl << endl;
			}
		}
	}

			/* switch (count) 
			{
			case 0 :
				cout << "���� �����մϴ�" << endl;
				you_hp = you_hp - my_atk;
				cout << "������ HP�� " << you_hp << "�Դϴ�" << endl;
				break;
			case 1 :
				cout << "���� �����մϴ�" << endl;
				my_hp = my_hp - you_atk;
				cout << "���� HP �� " << my_hp << "�Դϴ�" << endl;
				break;
			default :
				break;
			}*/ //�̷��� �ϴ� ��븸 �����ϰ� �ǳ׿� ... �Ф�

		return 0;
}
