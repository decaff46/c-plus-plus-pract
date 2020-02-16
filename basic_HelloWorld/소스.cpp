#include<iostream>
using namespace std;


int main()
{
	for (int score = 100; score >= 80; score -= 5) 
	{
		cout << "당신의 점수는 : " << score << endl << endl;
	}

	int data = 89;
	char grade;

	for (int data = 89; data > 0; data -= 11) 
	{
		if (data > 90) 
		{
			grade = 'A';
			cout << "당신의 점수는 : " << data << "이고 학점은 A 입니다." << endl;
		}
		else if (data > 80)
		{
			grade = 'B';
			cout << "당신의 점수는 : " << data << "이고 학점은 B 입니다." << endl;
		}
		else if (data > 70) 
		{
			grade = 'C';

			cout << "좀더 분발 하세요  !!" << endl;
		}
		else 
		{
			cout << "걍 때려쳐!! 걍 통과 시켜 줄테니까" << endl;
			//data = 100;
		}
	} //** 여기서 89 -- 11 좀 돌다가 다시 되는 법은 없나요?

	cout << endl;
	cout << endl;

	// do while loop 연습
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

