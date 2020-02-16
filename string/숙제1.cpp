# include <iostream>
# include <string.h>
# include <stdio.h>

using namespace std;

//문자열함수
//
//문자열길이			strlen
//문자열복사			strcpy
//문자열이어붙이기		strcat
//문자열비교			strcmp


void main()
{
	
	char Song[20] = "let it be";
	char Singer[10] = { 'b', 'e', 'a','t','l','e','s' };

#pragma region 	//문자열 길이
	const int length = strlen(Song);
	const int length2 = strlen(Singer);
	
	cout << strlen(Song) << endl;
	cout << strlen("let it be") << endl;
	

	cout << strlen(Singer) << endl; 
	cout << strlen("beatles") << endl;

	if (strlen(Song) == strlen("Singer"))
	{
		cout << "두개의 길이는 같습니다! 길이는 " <<  length << endl;
		
		if (strcmp(Song, "let it be") == 0)
		{
			cout << "두개는 같은 문자 입니다" << endl; 
		}
	}
	else
	{
		cout << "두개의 길이는 다릅니다" << endl;
		cout << "Song의 길이는 " << strlen(Song) << " '\n'Singer의 길이는 " << strlen(Singer) << endl;
	}

	cout << endl;

#pragma endregion


#pragma region 질문
	/*do    do while 다시 한번 설명 부탁 
	{
		cout << "song 과 singer의 길이를 비교합니다" << endl;
	}

	while ((strlen(Song) != 0) && (strlen(Singer) != 0));
	
	if (strcmp(Song, Singer) == 0)
	{
		cout << "두개의 길이는 같습니다" << endl;
	}
	else
	{
		cout << "두개의 길이는 다릅니다" << endl;
	}*/
#pragma endregion 



#pragma region 	//문자열 복사

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


#pragma region	//문자열 이어붙어 넣기 // 이게 왜 안되지???
	char cpypast[100] = {}; // [length + length2 + 1]는 상수값 이 있어야 한다면서 안된다는데 왜그렇지?
	strcat(cpypast, Song);
	strcat(cpypast, " 's singer is ");
	strcat(cpypast, Singer);
	cout << cpypast << endl;

	cout << endl;
#pragma endregion


#pragma region  //문자열 비교
	
	cout << strcmp(Song, Singer) << endl;   //Song[]>Singer[] 
	cout << strcmp(Singer, Song) << endl; 
	cout << strcmp(Song, "let it be") << endl; 
	cout << strcmp(Singer, "Beatles") << endl; // 이거 값이 왜 1? 대소문자 때문에 0 이 아닌건 알겠는데 왜 그래도 singer가 크지?
	
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

