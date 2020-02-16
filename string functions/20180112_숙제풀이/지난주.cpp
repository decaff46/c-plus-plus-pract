#include <iostream>
using namespace std;

/*
	이 표준함수를 보고,
	같은 기능을 수행할 수 있게 직접 구현해라.
	
	strlen

	strcpy

	strcat

	strcmp
*/

errno_t Mystrcpy_s(char *_Src, size_t _SrcSize, const char *_Dev)
{
	int DevLen = strlen(_Dev);

	if (DevLen >= _SrcSize)
	{
		cout << "에러";
		return 0;
	}
		
	for (int i = 0; i < DevLen+1; i++)
	{
		_Src[i] = _Dev[i];
	}

	return 1;
}
char *Mystrcpy(char *First, char *Second) 
{
	//int i = 0;
	//char *Temp = First;

	//while (Second[i] != '\0')
	//{
	//	*(Temp + i) = *(Second + i);
	//	//Temp[i] = Second[i];
	//	i++;
	//}

	//*(Temp + i) = '\0';
	////Temp[i] = '\0';
	///////////////////////////////////////////////
	int Size = strlen(Second) + 1;

	for (int i = 0; i < Size; i++)
	{
		First[i] = Second[i];
	}

	return First;
}

//cout << "StringC 의 길이 : " << 9 << endl << endl << endl;

int Mystrlen(char const *_Str)
{
	int i = 0;

	while (_Str[i] != '\0')
	{
		i++;
	}

	return i;
}


char *Mystrcat(char *First, char *Second) 
{
	//char *Temp =	First;

	//while (*First != '\0')
	//{
	//	First++;
	//}
	//while (*Second != '\0')
	//{
	//	*First++ = *Second++;
	//}
	//*First = '\0';

	//return Temp;
	/////////////////////////////////////
	int SrcLen = strlen(First);
	int DevLen = strlen(Second);

	// "kor" 길이3	[3] : 4번째 0,1,2,3	NULL
	//	문자열에서 문자열길이를 배열인덱스로 사용하면, NULL 문자 위치

	for (int i = 0; i < DevLen + 1; i++)
	{
		First[SrcLen + i] = Second[i];
	}

	return First;
}


int Mystrcmp(char const *First, char const *Second)
{
	////int result = 0;

	////	"kor" vs "korea"
	//while (*First != '\0' && *Second !='\0')
	//{
	//	if (*First < *Second)
	//	{
	//		result = -1;
	//		break;
	//	}
	//	else if (*First > *Second)
	//	{
	//		result = 1;
	//		break;
	//	}
	//	else
	//	{
	//		First++;	  // 음..... 이걸 굳이 할 이유가 있을까?
	//		Second++;	  //
	//		result = 0;
	//		//break;
	//	}
	//}

	//// result 0
	//return result;

	int Len = strlen(First);

	for (int i = 0; i < Len + 1; i++)
	{
		if (First[i] == Second[i])	continue;

		if (First[i] > Second[i])	return +1;
		else						return -1;
	}

	return 0;
}


// 전체적으로 왜 cout 을 했을때만 되는지 이해가 안되고 있습니다. 다 return 값으로 돌려놔서 나오게 했는데.. 
// 이해가 되지 않는건 말씀하신데로 했을때는 return값을 포함해서 답도 나오는데.. 왜 cout이 없을때는 아예 안나오는 걸까요?

/*
	strlen 함수들은 해당 기능만 한다. ( 문자열의 길이를 구해서 반환한다. )
*/

void main()
{
	char StringA[40] = "안녕";
	char StringB[40] = "잘가";
	char StringC[40] = "안되겠니?";

	int Len = Mystrlen(StringC);
	cout << "StringC 의 길이 : " << Len << endl << endl << endl;

	return;


	cout << "원본" << endl;
	cout << "StringA : " << StringA << endl;
	cout << "StringB : " << StringB << endl << endl << endl;
	

	// A = B;
	
	cout << "strcpy" << endl;
	cout << "StringA : " << StringA << endl;
	cout << "StringB : " << StringB << endl;

	Mystrcpy(StringA, StringB);

	cout << "복사된 문자열 :" << StringA << endl << endl << endl;

	//	A = B; A는 변수여야만 한다. B는 변수든, 상수든 값이면 된다.
	//	strcpy( A, B );	A = B;	"what" = "up";
	//cout << Mystrcpy(StringA, "up") << endl; //이건 왜 안되는 거지??


	//Mystrlen("hihihihih"); 

	cout << "Strlen" << endl;
	cout << "StringC : " << StringC << endl; 

	Len = Mystrlen(StringC);

	cout << "StringC 의 길이 : " << Len << endl << endl << endl;


	//Mystrcat(StringA, StringB);

	// "what" += "up";
	//Mystrcat(StringA, "up"); //이런 형태는 왜 안될까? leng의 경우"오옹"이런 것도 가능한데 

	cout << "strcat" << endl;
	cout << "StringA : " << StringA << endl;
	cout << "StringC : " << StringC << endl;

	Mystrcat(StringA, StringC);

	cout << "이어 붙인 결과 : " << StringA << endl << endl;



	Mystrcmp(StringA, StringB); 

	cout << "Strcmp" << endl;
	cout << "StringA 와 StringB 같은지 비교" << endl;
	if (Mystrcmp(StringA, StringB) == 0)
	{
		cout << "둘은 같은 글자 입니다" << endl;
	}
	else
	{
		cout << "다른 글자입니다" << endl;
	}

	Mystrcmp("hey", "hey");

}