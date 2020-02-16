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


char *Mystrcpy(char *First, char *Second) 
{
	int i = 0;
	char *Temp = First;
	while (Second[i] != '\0')
	{
		*(Temp + i) = *(Second + i);
		//Temp[i] = Second[i];
		i++;
	}
	*(Temp + i) = '\0';
	//Temp[i] = '\0';

	return Temp;
}


int Mystrlen(char const *_Str)
{
	int i = 0;

	while (_Str[i] != NULL)
	{
		i++;
	}

	//cout << i << endl;  이게 들어 가 있을 경우 왜 ?? StingA : FUCK  /4 /StirngA의 길이 : 4 라는 결과가 나올까?  저 중간에 있는 4는 왜??

	return i;
}


char *Mystrcat(char *First, char *Second) 
{
	char *Temp =	First;

	while (*First != '\0')
	{
		First++;
	}
	while (*Second != '\0')
	{
		*First++ = *Second++;
	}
	*First = '\0';

	return Temp;
}


int Mystrcmp(char const *First, char const *Second)
{
	int result = 0;

	while (*First != '\0' && *Second !='\0')
	{
		if (*First < *Second)
		{
			result = -1;
			break;
		}
		else if (*First > *Second)
		{
			result = 1;
			break;
		}
		else
		{
			First++;	  // 음..... 이걸 굳이 할 이유가 있을까?
			Second++;	  //
			result = 0;
			break;
		}
	}
	return result;
}


// 전체적으로 왜 cout 을 했을때만 되는지 이해가 안되고 있습니다. 다 return 값으로 돌려놔서 나오게 했는데.. 
// 이해가 되지 않는건 말씀하신데로 했을때는 return값을 포함해서 답도 나오는데.. 왜 cout이 없을때는 아예 안나오는 걸까요?

void main()
{
	char StringA[40] = "안녕";
	char StringB[40] = "잘가";
	char StringC[40] = "안되겠니?";
	
	cout << "원본" << endl;
	cout << "StringA : " << StringA << endl;
	cout << "StringB : " << StringB << endl << endl << endl;
	

	Mystrcpy(StringA, StringB);
	cout << "strcpy" << endl;
	cout << "StringA : " << StringA << endl;
	cout << "StringB : " << StringB << endl;
	cout << "복사된 문자열 :" << Mystrcpy(StringA, StringB) << endl << endl << endl;
	//cout << Mystrcpy("what", "up") << endl; //이건 왜 안되는 거지??


	//Mystrlen("hihihihih"); 

	cout << "Strlen" << endl;
	cout << "StringC : " << StringC << endl; 
	cout << "StringC 의 길이 : " << Mystrlen(StringC) << endl << endl << endl;


	//Mystrcat(StringA, StringB);
	//Mystrcat("what","up"); //이런 형태는 왜 안될까? leng의 경우"오옹"이런 것도 가능한데 

	cout << "strcat" << endl;
	cout << "StringA : " << StringA << endl;
	cout << "StringC : " << StringC << endl;
	cout << "이어 붙인 결과 : " << Mystrcat(StringA, StringC) << endl << endl;  



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