#include "Jumping.h"

void Jumping::idle(Animation*a)
{
	std::cout << "Going from Jumping to Idling" << std::endl; 
	a->setCurrent(new Idle());
	delete this;
}