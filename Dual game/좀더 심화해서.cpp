#include <iostream>
using namespace std;

int main()
{
	int count = 0;

	int my_hp = 100;
	int you_hp = 100;
	int you_atk = 4;
	int my_atk = 0;

	while (my_hp > 0 && you_hp > 0)
	{
			if (count % 2 != 0)
			{
				cout << "���� �����մϴ�" << endl;
				cout << "1 �Ǵ� 2�� �����ϼ��� 1: ũ�� (�ִ� 3��) 2: �븻   :   ";  // �� �ڽ����� ���� ���� ������?
				cin >> my_atk;
				
				int c = 0;

				switch (my_atk)
				{
				case 1:
					
					c++;  // ���⼭ ũ���� �ִ� 3���� �ϴ°� �ȵǳ׿� �Ф�  ���� .. ���� ���� �ߴµ�  ���� ȭ�����Դϴ�
					if (c <= 3)
					{
						cout << "ũ���� �����߽��ϴ� ������ ������'10'�� ���մϴ�." << endl;
						cout << 3 - c << "�� ũ�� ���� ���ҽ��ϴ�" << endl;
						you_hp = you_hp - 10;
						cout << "����� hp�� " << you_hp << "���ҽ��ϴ�" << endl << endl;
					}
					else  
					{
						cout << "ũ���� �ִ� ����߽��ϴ� �Ϲ� ������ �մϴ�" << endl << endl;
						you_hp = you_hp - 5;
					}
					break;
				
				case 2:
				
					cout << "�Ϲ� ������ ���մϴ� " << endl;
					you_hp = you_hp - 5;
					cout << "����� hp�� " << you_hp << "���ҽ��ϴ�" << endl << endl;
					break;
				
				default:
					cout << "1 �Ǵ� 2�� �����ϴٰ�" << endl;
					break;
				}

				if (you_hp <= 0)
				{
					cout << "��밡 �׾����ϴ� " << endl << endl;
					break;
				}
				else
				{
					cout << "������ HP�� " << you_hp << "�Դϴ�" << endl << endl;
				}
			}
			else
			{
				cout << "���� �����մϴ�" << endl;
				my_hp = my_hp - you_atk;
				if (my_hp <= 0)
				{
					cout << "���� �׾����ϴ� " << endl;
					break;
				}
				else
				{
					cout << "���� HP�� " << my_hp << "�Դϴ�" << endl << endl;
				}
			}
		
	}

	return 0;
}
