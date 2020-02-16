#pragma once
#include "Weapon.h"
class Axe :
	public Weapon
{
public:
	Axe();
	~Axe();

	void Attack();
	void Defense();
};

