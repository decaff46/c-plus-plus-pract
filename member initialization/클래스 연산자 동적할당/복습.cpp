#include "MyString.h"


int main()
{			  
	MyString A;
	MyString B;
	MyString C;

	(A = "¾È³ç") += "ÇÏ¼¼¿ä";

	A.Out();
	//	¾È³çÇÏ¼¼¿ä ¼±»ý´Ô
	B = A + " ¼±»ý´Ô";
	B.Out();

	//	¼±»ý´Ô ¾È³çÇÏ¼¼¿ä
	C = "¼±»ý´Ô " + A;

	cout << C << endl;
	return 0;
}