# include <iostream>
# include <string.h>
# include <stdio.h>

using namespace std;

//���ڿ��Լ�
//
//���ڿ�����			strlen
//���ڿ�����			strcpy
//���ڿ��̾���̱�		strcat
//���ڿ���			strcmp


void main()
{
	
	char Song[20] = "let it be";
	char Singer[10] = { 'b', 'e', 'a','t','l','e','s' };

#pragma region 	//���ڿ� ����
	const int length = strlen(Song);
	const int length2 = strlen(Singer);
	
	cout << strlen(Song) << endl;
	cout << strlen("let it be") << endl;
	

	cout << strlen(Singer) << endl; 
	cout << strlen("beatles") << endl;

	if (strlen(Song) == strlen("Singer"))
	{
		cout << "�ΰ��� ���̴� �����ϴ�! ���̴� " <<  length << endl;
		
		if (strcmp(Song, "let it be") == 0)
		{
			cout << "�ΰ��� ���� ���� �Դϴ�" << endl; 
		}
	}
	else
	{
		cout << "�ΰ��� ���̴� �ٸ��ϴ�" << endl;
		cout << "Song�� ���̴� " << strlen(Song) << " '\n'Singer�� ���̴� " << strlen(Singer) << endl;
	}

	cout << endl;

#pragma endregion


#pragma region ����
	/*do    do while �ٽ� �ѹ� ���� ��Ź 
	{
		cout << "song �� singer�� ���̸� ���մϴ�" << endl;
	}

	while ((strlen(Song) != 0) && (strlen(Singer) != 0));
	
	if (strcmp(Song, Singer) == 0)
	{
		cout << "�ΰ��� ���̴� �����ϴ�" << endl;
	}
	else
	{
		cout << "�ΰ��� ���̴� �ٸ��ϴ�" << endl;
	}*/
#pragma endregion 



#pragma region 	//���ڿ� ����

	char *copy = new char[length + 1]; //  == char copy[10]
	char *copy2 = new char[length2 + 10]; // char copy2[17]

	strcpy(copy, Song);
	cout << "Song= " << Song << endl;
	cout << "copied string = " << copy << endl; 

	cout << endl;

	strcpy_s(copy2, length+20, Singer);
	cout << "Singer= " << Singer << endl;
	cout << "new copied string = " << copy2 << endl << '\n';

	cout << strncpy(copy, Song, sizeof(copy)) << '\n'; 
	cout << strncpy(copy2, Singer, 3) << '\n';

	cout << endl;

#pragma endregion


#pragma region	//���ڿ� �̾�پ� �ֱ� // �̰� �� �ȵ���???
	char cpypast[100] = {}; // [length + length2 + 1]�� ����� �� �־�� �Ѵٸ鼭 �ȵȴٴµ� �ֱ׷���?
	strcat(cpypast, Song);
	strcat(cpypast, " 's singer is ");
	strcat(cpypast, Singer);
	cout << cpypast << endl;

	cout << endl;
#pragma endregion


#pragma region  //���ڿ� ��
	
	cout << strcmp(Song, Singer) << endl;   //Song[]>Singer[] 
	cout << strcmp(Singer, Song) << endl; 
	cout << strcmp(Song, "let it be") << endl; 
	cout << strcmp(Singer, "Beatles") << endl; // �̰� ���� �� 1? ��ҹ��� ������ 0 �� �ƴѰ� �˰ڴµ� �� �׷��� singer�� ũ��?
	
	cout << endl;
	
	char key[80] = "";
	int count = 0;

	while (count < 5)  
	{
		cout << "whos the singer of Let it Be :";
		cin >> key;

		strcmp(key, Singer);

		if (strcmp(key, Singer) == 0)
		{
			cout << "Right!" << endl;
			break;
		}
		else
		{
			cout << "Wrong" << endl;
			count++;
		}
	}
	cout << " Games' up !! The Answer is " << Singer << endl;
#pragma endregion


}

