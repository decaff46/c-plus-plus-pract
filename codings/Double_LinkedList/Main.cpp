#include "cDouble_LinkedList.h"

void main(void)
{
	cDouble_LinkedList<int>	List;

	for (int i = 0; i < 4; ++i)
	{
		List.push_back(i);
	}

	for (int i = 0; i < 4; ++i)
	{
		List.push_front(i+10);
	}

	for (int i = 0; i < 3; ++i)
	{
		List.pop_back();
	}

	for (int i = 0; i < 3; ++i)
	{
		List.pop_front();
	}

	return void();
}