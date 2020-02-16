#include <iostream>
using namespace std;
#include "Character.h"


int main()
{
	int			input = 0;
	bool		isPlaying = true;
	Character	character;

	while (isPlaying)
	{
		cout << "0. 던지기" << endl;
		cout << "1. 공격" << endl;
		cout << "2. 방어" << endl;
		cout << "3. 교체" << endl;
		cout << "4. 화면청소" << endl;
		cout << "입력 : ";
		cin >> input;

		switch (input)
		{
		case 0: character.Throw();	break;
		case 1:	character.Attack();	break;
		case 2:	character.Defense();break;

		case 3:
		{
			cout << "무기 종류 선택" << endl;
			cout << "1. 칼" << endl;
			cout << "2. 활" << endl;
			cout << "3. 창" << endl;
			cout << "4. 도끼" << endl;
			cin >> input;

			character.Change(input);
		}break;
		case 4: system("cls");	break;
		}
	}
	return 0;
}