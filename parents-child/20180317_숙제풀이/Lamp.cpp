#include "Lamp.h"

#include "White.h"
#include "LED.h"
#include "Oslam.h"
#include "NewBulb.h"

Lamp::Lamp()
{
}

Lamp::~Lamp()
{
	//	기존 전구 제거
	if (m_bulb != nullptr)	delete m_bulb;
}

void Lamp::TurnOn()
{
	if (m_bulb != nullptr)	m_bulb->TurnOn();
}

void Lamp::TurnOff()
{
	if (m_bulb != nullptr)	m_bulb->TurnOff();
}

void Lamp::Name()
{
	if (m_bulb != nullptr)	m_bulb->Name();
}

void Lamp::ChangeBulb(int _type)
{
	//	기존 전구 제거
	if( m_bulb != nullptr )	delete m_bulb;

	switch (_type)
	{
	case 0:	m_bulb = new White; break;

	case 1:	m_bulb = new LED;	break;

	case 2:	m_bulb = new Oslam; break;

	case 3:	m_bulb = new NewBulb; break;
	}
}
