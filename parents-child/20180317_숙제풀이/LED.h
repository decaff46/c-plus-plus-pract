#pragma once
#include "Bulb.h"

class LED :
	public Bulb
{
public:
	LED();
	~LED();

	void	TurnOn();
	void	TurnOff();
	void	Name();
};

