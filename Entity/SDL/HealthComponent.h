#pragma once
#include "Component.h"

class HealthComponent : public Component
{
public:
	HealthComponent() : health(100) { id = 1; }
	/* Data Only */
	int getHealth() { return health; }
	void setHealth(int health) { this->health = health;
	}
private:
	int health;
	
};
