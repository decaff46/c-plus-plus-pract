#include <iostream>
using namespace std;

/*
	�б⹮

		�ش� ������ �б��Ͽ� �����ϴ� ����

	switch( �������� ) 
	{
	case ��1:
		break;

	case ��2:

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
		cout << "�ſ� ����." << endl;
		cout << "����" << endl;
		break;

	case 2:
		cout << "2�� �Ǿ���." << endl;

	case 3:
		cout << "���" << endl;

	default:
		cout << "4�̻�" << endl;
	}

	int Score = 0;

	cout << "���� : ";
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