# include <iostream>
# include <Windows.h>

using namespace std;


//1.카드 생성
//2. 카드 셔플
//3. 8장 선택
//4. 카드 나열
//5. 카드 선택 a,b
//6. 카드 비교

void ViewCard(int _Pick[])
{

	switch (_Pick[] / 13)
	{
	case 0:		cout << "♠";  break;
	case 1:		cout << "♡";  break;
	case 2:		cout << "◇";  break;
	case 3:		cout << "♣";  break;
	}
	switch (_Pick[] % 13)
	{
	case 0:		cout << "A";  break;
	case 10:	cout << "J";  break;
	case 11:	cout << "Q";  break;
	case 12:	cout << "K";  break;
	default:	cout << _Pick[] % 13 + 1;
	}
}

void main()
{
	srand(GetTickCount());


	//좌표 값 생성
	const int Size = 4;
	int Out[Size*Size] = {};
	bool IsView[Size*Size] = {};
	int Card[52];
	int Pick[Size*2] = {};


	//카드 생성
	for (int i = 0; i < 52; i++)
	{
		Card[i] = i;
	}


	//카드 셔플
	for (int i = 0; i < 100; i++)
	{
		int S = rand() % 52;
		int D = rand() % 52;

		int Temp = Card[S];
		Card[S] = Card[D];
		Card[D] = Temp;
	}


////8장 선택
//for (int j = 0; j < Size * 2; j++)
//{
//	Pick[j] = Card[j];
//}



	//같은 그림 2개
	for (int i = 0; i < Size*Size; i++)
	{
		Out[i] = Card[i / 2];  
	}
	
	

	//좌표값 셔플
	for (int i = 0; i < Size*Size * 3; i++) 
	{
		int Src = rand() % (Size*Size);
		int Dev = rand() % (Size*Size);

		int Temp = Out[Src];
		Out[Src] = Out[Dev];
		Out[Dev] = Temp;
	}



	//선택 값
	int		NOT_SELECT = -1;
	int		First = NOT_SELECT;
	int		Second = NOT_SELECT;

	int		Index = 0;


	while (true) 
	{
		for (int j = 0; j < Size; j++)
		{
			for (int i = 0; i < Size; i++)
			{
				//if (IsView[Size*j + i] == false)
				//{
				//	cout << "▣";
				//}
				//else
				//{
					switch (Out[Size*j + i])  // 숫자로까지는 하겠는데 카드 모양을 나오게는 못하겠음
					{
					case 0:	cout << Pick[0];	break;						
					case 1:	cout << Pick[1];	break;						
					case 2:	cout << Pick[2];	break;						
					case 3:	cout << Pick[3];	break;						
					case 4:	cout << Pick[4];	break;						
					case 5:	cout << Pick[5];	break;						
					case 6:	cout << Pick[6];	break;						
					case 7:	cout << Pick[7];	break;						
					}														
				//}															
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