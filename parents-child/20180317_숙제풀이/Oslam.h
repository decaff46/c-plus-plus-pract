#pragma once
#include "Bulb.h"

class Oslam :
	public Bulb
{
public:
	Oslam();
	~Oslam();

	void	TurnOn();
	void	TurnOff();
	void	Name();
};

