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
		cout << "0. ������" << endl;
		cout << "1. ����" << endl;
		cout << "2. ���" << endl;
		cout << "3. ��ü" << endl;
		cout << "4. ȭ��û��" << endl;
		cout << "�Է� : ";
		cin >> input;

		switch (input)
		{
		case 0: character.Throw();	break;
		case 1:	character.Attack();	break;
		case 2:	character.Defense();break;

		case 3:
		{
			cout << "���� ���� ����" << endl;
			cout << "1. Į" << endl;
			cout << "2. Ȱ" << endl;
			cout << "3. â" << endl;
			cout << "4. ����" << endl;
			cin >> input;

			character.Change(input);
		}break;
		case 4: system("cls");	break;
		}
	}
	return 0;
}