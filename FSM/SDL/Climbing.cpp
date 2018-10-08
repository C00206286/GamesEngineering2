#include "Climbing.h"

void Climbing::idle(Animation* a)
{
	std::cout << "Going from Climbing to Idling" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}