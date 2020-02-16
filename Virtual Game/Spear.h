#pragma once
#include "Weapon.h"
class Spear :
	public Weapon
{
public:
	Spear();
	~Spear();
	void Attack();
	void Defense();
};

