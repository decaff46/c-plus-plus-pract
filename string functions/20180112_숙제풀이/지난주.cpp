#include <iostream>
using namespace std;

/*
	�� ǥ���Լ��� ����,
	���� ����� ������ �� �ְ� ���� �����ض�.
	
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
		cout << "����";
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

//cout << "StringC �� ���� : " << 9 << endl << endl << endl;

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

	// "kor" ����3	[3] : 4��° 0,1,2,3	NULL
	//	���ڿ����� ���ڿ����̸� �迭�ε����� ����ϸ�, NULL ���� ��ġ

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
	//		First++;	  // ��..... �̰� ���� �� ������ ������?
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


// ��ü������ �� cout �� �������� �Ǵ��� ���ذ� �ȵǰ� �ֽ��ϴ�. �� return ������ �������� ������ �ߴµ�.. 
// ���ذ� ���� �ʴ°� �����Ͻŵ��� �������� return���� �����ؼ� �䵵 �����µ�.. �� cout�� �������� �ƿ� �ȳ����� �ɱ��?

/*
	strlen �Լ����� �ش� ��ɸ� �Ѵ�. ( ���ڿ��� ���̸� ���ؼ� ��ȯ�Ѵ�. )
*/

void main()
{
	char StringA[40] = "�ȳ�";
	char StringB[40] = "�߰�";
	char StringC[40] = "�ȵǰڴ�?";

	int Len = Mystrlen(StringC);
	cout << "StringC �� ���� : " << Len << endl << endl << endl;

	return;


	cout << "����" << endl;
	cout << "StringA : " << StringA << endl;
	cout << "StringB : " << StringB << endl << endl << endl;
	

	// A = B;
	
	cout << "strcpy" << endl;
	cout << "StringA : " << StringA << endl;
	cout << "StringB : " << StringB << endl;

	Mystrcpy(StringA, StringB);

	cout << "����� ���ڿ� :" << StringA << endl << endl << endl;

	//	A = B; A�� �������߸� �Ѵ�. B�� ������, ����� ���̸� �ȴ�.
	//	strcpy( A, B );	A = B;	"what" = "up";
	//cout << Mystrcpy(StringA, "up") << endl; //�̰� �� �ȵǴ� ����??


	//Mystrlen("hihihihih"); 

	cout << "Strlen" << endl;
	cout << "StringC : " << StringC << endl; 

	Len = Mystrlen(StringC);

	cout << "StringC �� ���� : " << Len << endl << endl << endl;


	//Mystrcat(StringA, StringB);

	// "what" += "up";
	//Mystrcat(StringA, "up"); //�̷� ���´� �� �ȵɱ�? leng�� ���"����"�̷� �͵� �����ѵ� 

	cout << "strcat" << endl;
	cout << "StringA : " << StringA << endl;
	cout << "StringC : " << StringC << endl;

	Mystrcat(StringA, StringC);

	cout << "�̾� ���� ��� : " << StringA << endl << endl;



	Mystrcmp(StringA, StringB); 

	cout << "Strcmp" << endl;
	cout << "StringA �� StringB ������ ��" << endl;
	if (Mystrcmp(StringA, StringB) == 0)
	{
		cout << "���� ���� ���� �Դϴ�" << endl;
	}
	else
	{
		cout << "�ٸ� �����Դϴ�" << endl;
	}

	Mystrcmp("hey", "hey");

}