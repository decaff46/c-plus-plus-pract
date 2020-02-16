#pragma once
#include "Weapon.h"
class Arrow :
	public Weapon
{
public:
	Arrow();
	~Arrow();
	void Attack();
	void Defense();
	//void Throw();
};

