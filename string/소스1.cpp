#include <iostream>
using namespace std;

void main()
{
	int firstvalue, secondvalue;
	int * mypointer;

	mypointer = &firstvalue;
	*mypointer = 10;
	mypointer = &secondvalue;

	// secondvalue = 20;
	*mypointer = 20;

	cout << "firstvalue is " << firstvalue << '\n';
	cout << "secondvalue is " << secondvalue << '\n';
	
	// cout << secondvalue << '\n';
	cout << *mypointer << '\n';


	int numbers[5];
	int * ptr;
	ptr = numbers;

	// numbers[0]
	*ptr = 10;

	ptr++;

	// numbers[1]
	*ptr = 20;

	ptr = &numbers[2];
	*ptr = 30;

	ptr = numbers + 3;
	*ptr = 40;

	// &(numbers[0])
	ptr = numbers;

	*(ptr + 4) = 50;

	for (int n = 0; n<5; n++)
		cout << numbers[n] << ", ";
}
