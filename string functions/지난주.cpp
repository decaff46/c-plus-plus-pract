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

	//cout << i << endl;  �̰� ��� �� ���� ��� �� ?? StingA : FUCK  /4 /StirngA�� ���� : 4 ��� ����� ���ñ�?  �� �߰��� �ִ� 4�� ��??

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
			First++;	  // ��..... �̰� ���� �� ������ ������?
			Second++;	  //
			result = 0;
			break;
		}
	}
	return result;
}


// ��ü������ �� cout �� �������� �Ǵ��� ���ذ� �ȵǰ� �ֽ��ϴ�. �� return ������ �������� ������ �ߴµ�.. 
// ���ذ� ���� �ʴ°� �����Ͻŵ��� �������� return���� �����ؼ� �䵵 �����µ�.. �� cout�� �������� �ƿ� �ȳ����� �ɱ��?

void main()
{
	char StringA[40] = "�ȳ�";
	char StringB[40] = "�߰�";
	char StringC[40] = "�ȵǰڴ�?";
	
	cout << "����" << endl;
	cout << "StringA : " << StringA << endl;
	cout << "StringB : " << StringB << endl << endl << endl;
	

	Mystrcpy(StringA, StringB);
	cout << "strcpy" << endl;
	cout << "StringA : " << StringA << endl;
	cout << "StringB : " << StringB << endl;
	cout << "����� ���ڿ� :" << Mystrcpy(StringA, StringB) << endl << endl << endl;
	//cout << Mystrcpy("what", "up") << endl; //�̰� �� �ȵǴ� ����??


	//Mystrlen("hihihihih"); 

	cout << "Strlen" << endl;
	cout << "StringC : " << StringC << endl; 
	cout << "StringC �� ���� : " << Mystrlen(StringC) << endl << endl << endl;


	//Mystrcat(StringA, StringB);
	//Mystrcat("what","up"); //�̷� ���´� �� �ȵɱ�? leng�� ���"����"�̷� �͵� �����ѵ� 

	cout << "strcat" << endl;
	cout << "StringA : " << StringA << endl;
	cout << "StringC : " << StringC << endl;
	cout << "�̾� ���� ��� : " << Mystrcat(StringA, StringC) << endl << endl;  



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