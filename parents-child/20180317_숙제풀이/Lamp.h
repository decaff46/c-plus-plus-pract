#pragma once

#include "Bulb.h"

class Lamp
{
	Bulb	*m_bulb = nullptr;

public:
	Lamp();
	~Lamp();

	void	TurnOn();
	void	TurnOff();
	void	Name();
	void	ChangeBulb(int _type);
};

