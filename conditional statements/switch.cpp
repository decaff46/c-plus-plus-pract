#include <iostream>
using namespace std;

/*
	분기문

		해당 정수로 분기하여 실행하는 문법

	switch( 정수변수 ) 
	{
	case 값1:
		break;

	case 값2:

	default:
		break;
	}
*/
void function(int array[], int k)
{
	int size = sizeof(array);
	for (int i = 0; i < size; i++)
	{
		if (k == array[i])
		{
			cout << "YES" << endl;
		}
		cout << "NO" << endl;
	}
}

void main()
{
	int Num = 0;
	cin >> Num;

	int array[] = {1,2,3,4,5 };
	int k = 5; 
	function(array, k);




	switch (Num)
	{
	case 0:
	case 1:
		cout << "매우 낮다." << endl;
		cout << "실패" << endl;
		break;

	case 2:
		cout << "2는 되었다." << endl;

	case 3:
		cout << "삼삼" << endl;

	default:
		cout << "4이상" << endl;
	}

	int Score = 0;

	cout << "점수 : ";
	cin >> Score;
	
	switch (Score / 10)
	{
	case 10:
	case 9:
		cout << "A" << endl;
		break;

	case 8:
		cout << "B" << endl;
		break;

	case 7:
		cout << "C" << endl;
		break;

	default:
		cout << "F" << endl;
	}

}