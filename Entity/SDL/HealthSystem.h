#pragma once
#include "Entity.h"
#include "HealthComponent.h"
#include "PositionComponent.h"

class HealthSystem
{
	std::vector<Entity*> entities;
	std::vector<Component*> components;
	HealthComponent* playerHealthComp;
	int playerPositionX;
	int playerPositionY;
	int playerHealth;

public:
	void addEntity(Entity * e) { entities.push_back(e); }
	void update() {
		//std::cout << "HealthSystem Update" << std::endl;
		for (Entity* ent : entities)
		{
				std::vector<Component*> components = ent->getComponents();
				for (Component* c : components)
				{
					if (c->id == 1)
					{
						HealthComponent* c1 = dynamic_cast<HealthComponent *>(c);
						if (ent->id == 1)
						{
							playerHealthComp = dynamic_cast<HealthComponent *>(c);
							//Player get health
						}
						else
						{
							//AI health set
							c1->setHealth(100);
						}
					}
					if (c->id == 2)
					{
						PositionComponent* c3 = dynamic_cast<PositionComponent *>(c);
						if (ent->id == 1)
						{
							PositionComponent* c2 = dynamic_cast<PositionComponent *>(c);
							playerPositionX = c2->getPositionX();
							playerPositionY = c2->getPositionY();
						}
						else if (c3->getPositionX() <= playerPositionX + 40 && c3->getPositionX() >= playerPositionX && c3->getPositionY() <= playerPositionY + 40 && c3->getPositionY() >= playerPositionY)
						{
							playerHealthComp->setHealth(playerHealthComp->getHealth() - 1);
							std::cout << "Player Health = " << playerHealthComp->getHealth() << std::endl;
						}
					}
				}
		}
		/* Loop through Entities with */
		/* HealthComponents and Update */
		/* TBI */
	}
};