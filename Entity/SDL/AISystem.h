#pragma once
#include "Entity.h"
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "ControlComponent.h"
#include <stdlib.h>  

class AISystem
{
	std::vector<Entity*> entities;

public:
	int positionX;
	int positionY;
	int direction = 0;
	int wanderCount = 0;
	bool directionChange = false;
	double speed = 1;


	void addEntity(Entity * e) { entities.push_back(e); }
	void update() {
		wanderCount = wanderCount + 1;
		if (wanderCount > 600)
		{
			direction = rand() % 4 + 1;
			wanderCount = 0;
		}

		for (Entity* ent : entities)
		{	

			PositionComponent* c1 = NULL;
			for (Component* c : ent->getComponents())
			{
				if (c->id == 2)
				{
					c1 = dynamic_cast<PositionComponent *>(c);
					if (direction == 1)
					{
						c1->setPositionX(c1->getPositionX() + speed);
					}
					// Move Down
					if (direction == 2)
					{
						c1->setPositionY(c1->getPositionY() + speed);
					}
					// Move Left
					if (direction == 3)
					{
						c1->setPositionX(c1->getPositionX() - speed);
					}
					// Move Up
					if (direction == 4)
					{
						c1->setPositionY(c1->getPositionY() - speed);
					}
					if (c1->getPositionX() < 0)
					{
						c1->setPositionX(999);
					}
					if (c1->getPositionX() > 1000)
					{
						c1->setPositionX(1);
					}
					if (c1->getPositionY() < 0)
					{
						c1->setPositionY(999);
					}
					if (c1->getPositionY() > 1000)
					{
						c1->setPositionY(1);
					}
				}
				
			}
		}

	}
	
};
