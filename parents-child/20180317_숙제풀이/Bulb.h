#pragma once

class Bulb
{
public:
	virtual ~Bulb() = default;

	virtual void	TurnOn()	= 0;
	virtual void	TurnOff()	= 0;
	virtual void	Name()		= 0;
};