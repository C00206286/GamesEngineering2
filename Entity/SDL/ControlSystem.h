#pragma once
#include "Entity.h"
#include "HealthComponent.h"
#include "PositionComponent.h"

class ControlSystem
{
	std::vector<Entity*> entities;
	std::vector<Component*> components;

public:
	void addEntity(Entity * e) { entities.push_back(e); }
	void update() {
		std::cout << "ControlSystem Update" << std::endl;
		for (Entity* ent : entities)
		{
			std::vector<Component*> components = ent->getComponents();
			for (Component* c : components)
			{
				PositionComponent* c1 = static_cast<PositionComponent *>(c);
				c1->setPositionX(100);
			}
		}
		/* Loop through Entities with */
		/* HealthComponents and Update */
		/* TBI */
	}
};