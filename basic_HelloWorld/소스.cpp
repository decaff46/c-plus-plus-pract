#include<iostream>
using namespace std;


int main()
{
	for (int score = 100; score >= 80; score -= 5) 
	{
		cout << "����� ������ : " << score << endl << endl;
	}

	int data = 89;
	char grade;

	for (int data = 89; data > 0; data -= 11) 
	{
		if (data > 90) 
		{
			grade = 'A';
			cout << "����� ������ : " << data << "�̰� ������ A �Դϴ�." << endl;
		}
		else if (data > 80)
		{
			grade = 'B';
			cout << "����� ������ : " << data << "�̰� ������ B �Դϴ�." << endl;
		}
		else if (data > 70) 
		{
			grade = 'C';

			cout << "���� �й� �ϼ���  !!" << endl;
		}
		else 
		{
			cout << "�� ������!! �� ��� ���� ���״ϱ�" << endl;
			//data = 100;
		}
	} //** ���⼭ 89 -- 11 �� ���ٰ� �ٽ� �Ǵ� ���� ������?

	cout << endl;
	cout << endl;

	// do while loop ����
	/*
	int a = 6;
	int i = -10;
	do
	{
		i++;
		a--;

		if (a<i || a + i == 1) {
			cout << "a value: " << a << "     i value : " << i << endl;
			break;
		}
	} while (a > -100);
	cout << "a value: " << a << "     i value : " << i << endl;
	*/


	return 0;
}

