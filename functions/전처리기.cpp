#include <iostream>
using namespace std;

#pragma region MyRegion


#pragma endregion

/*
	�ڵ��ۼ� - ������ - ��ŷ - �������ϻ���

	��ó����

		���������� ó���ϴ� ����

	��ó���� Ư¡

		�տ� #�� �ٴ´�.
		���ٿ��� �ϳ��� ��ó���⸸ ����

		\ �����ڸ� ����ؼ� �ϳ��� ��ó���Ⱑ ������ ����

		���� ;�� ����.

	��ó���� ����

		#include 

		#define

		#if, #ifdef, #endif,...

		#error

		#line

		#pragma

	////////////////////////////////////////////

	#include 
		�ٿ��ֱ�

		<> , ""

	#define

		��ũ��

	��ũ�� ���

		#define MAX 10

	��ũ�� �Լ�

		#define ADD(x) (x+=10)

	��ũ�� ����

		#define	KMK
*/

#pragma region �����ε�

#define MAX 10
#define ADD(x)		(x+=10)
#define SIZEOF(x)	(sizeof(x))
//#define KMK

#pragma endregion


void main()
{
#ifdef KMK
	cout << "KMK���ǵǾ���." << endl;
#else
	cout << "KMK���Ǿȉ��." << endl;
#endif

	cout << "MAX" << endl;
	cout << MAX << endl;

	int Num = 0;

	//Num += 10;
	ADD(Num);

	
	cout << sizeof(Num) << endl;
	cout << SIZEOF(int) << endl;
}