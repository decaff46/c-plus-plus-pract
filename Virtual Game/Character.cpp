#include "Character.h"
#include "Sword.h"
#include "Arrow.h"
#include "Spear.h"
#include "Axe.h"


Character::Character()
{
}


Character::~Character()
{
	if (m_weapon != nullptr) delete m_weapon;
}

void Character::Attack()
{
	if (m_weapon != nullptr) m_weapon->Attack();
}

void Character::Defense()
{
	if (m_weapon != nullptr) m_weapon->Defense();
}

void Character::Change(int _type)
{
	if (m_weapon != nullptr) delete m_weapon;

	switch (_type)
	{
		case 1:	m_weapon = new Sword;	break;

		case 2:	m_weapon = new Arrow;	break;

		case 3:	m_weapon = new Spear;	break;

		case 4:	m_weapon = new Axe;		break;
	}
}

void Character::Throw()
{
	if (m_weapon !=nullptr)  m_weapon->Throw();
}
