#pragma once

#include "Bulb.h"

class White :
	public Bulb
{
public:
	White();
	~White();

	void	TurnOn();
	void	TurnOff();
	void	Name();
};

