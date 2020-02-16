#pragma once
#include "Bulb.h"
class NewBulb :
	public Bulb
{
public:
	NewBulb();
	~NewBulb();

	void	TurnOn();
	void	TurnOff();
	void	Name();
};

