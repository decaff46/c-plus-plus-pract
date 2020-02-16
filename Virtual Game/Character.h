#pragma once
#include "Weapon.h"

class Character
{
	Weapon *m_weapon = nullptr;
public:
	Character();
	~Character();

	void Attack() ;
	void Defense();
	void Change(int _type) ;
	void Throw();
};				

