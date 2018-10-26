#pragma once
#include "Entity.h"
#include "HealthComponent.h"

class HealthSystem
{
	std::vector<Entity> entities;
	std::vector<Component*> components;

public:
	void addEntity(Entity e) { entities.push_back(e); }
	void update() {
		std::cout << "HealthSystem Update" << std::endl;
		for (Entity i : entities)
		{
				std::vector<Component*> components = i.getComponents();
				for (Component* c : components)
				{
				    HealthComponent* c1 = static_cast<HealthComponent *> (c);
					c1->setHealth(100);
				}
		}
		/* Loop through Entities with */
		/* HealthComponents and Update */
		/* TBI */
	}
};