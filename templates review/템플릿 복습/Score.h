#pragma once
#include <iostream>
#include "MyVector.h"
using namespace std;

const int Max = 5; 

class Score
{
public:
	Score();
	~Score();

	struct ScoreSystem
	{
		int ID;
		int Score;
	};

	bool	Isplaying = true; 
	int		input = 0;

};

