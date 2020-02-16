#include <iostream>
using namespace std; 

// check 함수화 하기 
//void Double_Check(Check) 
//{
//	cin >> Check; 
//}


int main ()
{
	//기본 조건 생성 1.학생	 2. 성적기록 (++성적 최대 점수 100 넘지 못하게 막기)		3. 최대 5명의 학생만 가능
	const	int		StdNumb = 5;
	const	int		SbjNumb = 3;
	char			Students[StdNumb] = { 'A', 'B', 'C', 'D','E' };
	int				Result[SbjNumb * StdNumb] = {};




	//성적 입력
	int KorResult = 0, MathResult = 0, EngResult = 0;
	char Check = ' '; 

	for (int i = 0; i < StdNumb; i++)
	{
		for (int j = 0; j < SbjNumb; j++)
		{
			cout << Students[i] << "의 성적을 입력하세요" << endl;
			cout << "국어 점수 :";
			cin >> KorResult;
			cout << "영어 점수 :";
			cin >> EngResult;
			cout << "수학 점수 :";
			cin >> MathResult;
			cout << Students[i] << " 의 점수는 국어 :" << KorResult << "  영어 :" << EngResult << "  수학 :" << MathResult << "가 맞습니까?(Y/N)" << endl;
			 
			cin >> Check;  // 함수화 시키자 
			if (Check == 'Y' || Check == 'y' || Check == 'N' || Check == 'n')
			{
				if (Check == 'Y' || Check == 'y')
				{
					cout << "다음 학생의 점수를 기입하세요 " << endl;
				}
				else
				{
					cout << Students[i] << "의 성적을 '다시' 입력하세요" << endl;
					cout << "국어 점수 :";
					cin >> KorResult;
					cout << "영어 점수 :";
					cin >> EngResult;
					cout << "수학 점수 :";
					cin >> MathResult;
					cout << Students[i] << " 의 점수는 국어 :" << KorResult << "  영어 :" << EngResult << "  수학 :" << MathResult << "가 맞습니까?(Y/N)" << endl;
					cin >> Check;
				}
			}
			else
			{
				cout << "Y / N 만 입력 가능합니다" << endl;
			}	

		}
		
		
	}

	bool IsStudent = true;

	// 성적표 출력
	while (IsStudent)
	{
		cout << " 성적표를 출력합니다" << endl << endl;
		
		/*cout << "		국어	영어	수학" << endl;			
		for (int i = 0; i < 5; i++)
		{
			cout << Students[i] << "	" << Result << endl;
		}  테두리를 만드록 싶은데 그 안에다가 어떻게 넣아야 할까?  */

		for (int i = 0; i < StdNumb; i++)
		{
			for (int j = 0; j < SbjNumb; j++)
			{
				cout << Result[StdNumb * j + i];
			}
			cout << endl;
		}

	}
		
	
	return 0;
}