#include <iostream>
#include <Windows.h>
using namespace std;

void main()
{
	srand(GetTickCount());

	// 이름이 있는 상수
	const int	Size = 4;
	int			Out[Size*Size] = {};
	bool		IsView[Size*Size] = {};

	for (int i = 0; i < Size*Size; i++)
	{
		Out[i] = i / 2; //이게 두개의 동일한 카드가 나와야해서 /2를 하신건가요?
	}

	// 셔플
	// 1. 인덱스 2개를 임의로 설정한다.
	// 2. 해당 인덱스의 값을 교체한다.
	for (int i = 0; i < Size*Size * 3; i++) //Size*Size * 3 왜 여기서 *3을 해야 하나요? 지난번 200처럼 그냥 인가요?
	{
		int Src = rand() % (Size*Size); 
		int Dev = rand() % (Size*Size);

		int Temp = Out[Src];
		Out[Src] = Out[Dev];
		Out[Dev] = Temp;
	}

	//	반복 여부
	bool	IsPlaying = true;
	int		Input = 0;

	//	비교용
	int		NOT_SELECT = -1;
	int		First = NOT_SELECT;
	int		Second = NOT_SELECT;

	while (IsPlaying)
	{
		// 출력
		for (int j = 0; j < Size; j++)
		{
			for (int i = 0; i < Size; i++)
			{
				if (IsView[Size*j + i] == false) 
				{								 
					cout << "▣";
				}
				else
				{
					switch (Out[Size*j + i]) 
					{
					case 0:	cout << "＠";	break;
					case 1:	cout << "★";	break;
					case 2:	cout << "♥";	break;
					case 3:	cout << "▲";	break;
					case 4:	cout << "♣";	break;
					case 5:	cout << "♨";	break;
					case 6:	cout << "☎";	break;
					case 7:	cout << "◎";	break;
					}
				}
			}
			cout << endl;
		}

		cout << "번호 : ";

		// 입력
		if (First == NOT_SELECT)
		{
			cin >> First;
			IsView[First] = true;
		}
		else if (Second == NOT_SELECT)
		{
			cin >> Second;
			IsView[Second] = true;
		}

		// 판정
		else
		{
			if (Out[First] != Out[Second])
			{
				IsView[First] = false;
				IsView[Second] = false;
			}


			First = NOT_SELECT;
			Second = NOT_SELECT;

			//	일시정지
			system("pause");
		}

		// 화면 청소
		system("cls");
	}


}