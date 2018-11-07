#pragma once
#include "Entity.h"
#include "PositionComponent.h"
#include <SDL.h>

class RenderSystem
{
	std::vector<Entity*> entities;
	std::vector<Component*> components;
	int r = 0;
	int g = 0;
	int b = 0;

public:
	void addEntity(Entity * e) { entities.push_back(e); }
	void update(SDL_Surface* surface) {

		for (Entity* ent : entities)
		{
			std::vector<Component*> components = ent->getComponents();
			for (Component* c : components)
			{
				if (c->id == 2)
				{
					if (ent->id == 1)
					{
						r = 33;
						g = 255;
						b = 81;
					}
					if (ent->id == 2)
					{
						r = 255;
						g = 0;
						b = 0;
					}
					if (ent->id == 3)
					{
						r = 0;
						g = 0;
						b = 255;
					}
					if (ent->id == 4)
					{
						r = 255;
						g = 0;
						b = 255;
					}
					SDL_Rect rect;
					PositionComponent* c1 = dynamic_cast<PositionComponent *>(c);

					rect.x = c1->getPositionX();
					rect.y = c1->getPositionY();
					//rect.x = 100;
					//rect.y = 0;
					rect.w = 40;
					rect.h = 40;
		            SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, r, g, b));
					
				}
			}
		}
		/* Loop through Entities with */
		/* HealthComponents and Update */
		/* TBI */
	}
};
