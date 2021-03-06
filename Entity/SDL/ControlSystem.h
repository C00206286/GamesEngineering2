#pragma once
#include "Entity.h"
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "ControlComponent.h"

class ControlSystem
{
	std::vector<Entity*> entities;

public:
	int positionX;
	int positionY;
	int direction = 0;
	int speed = 10;

	SDL_Event e;

	
	void addEntity(Entity * e) { entities.push_back(e); }
	void update() {

		while (SDL_PollEvent(&e) != 0)
		{
			direction = handleInput(e);
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				//quit = true;
			}
		}

		for (Entity* ent : entities)
		{
			PositionComponent* c1 = NULL;
			for (Component* c : ent->getComponents())
			{
				if (c->id == 2)
				{
					c1 = dynamic_cast<PositionComponent *>(c);
				}
				if (c->id == 3)
				{
					if (direction == 1)
					{
						c1->setPositionX(c1->getPositionX() + speed);
						direction = 0;
					}
					// Move Down
					if (direction == 2)
					{
						c1->setPositionY(c1->getPositionY() + speed);
						direction = 0;
					}
					// Move Left
					if (direction == 3)
					{
						c1->setPositionX(c1->getPositionX() - speed);
						direction = 0;
					}
					// Move Up
					if (direction == 4)
					{
						c1->setPositionY(c1->getPositionY() - speed);
						direction = 0;
					}
				}			
			}
		}
	
	}
	int handleInput(SDL_Event & event)
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_RIGHT:
				return 1;
				break;
			case SDLK_DOWN:
				return 2;
				break;
			case SDLK_LEFT:
				return 3;
				break;
			case SDLK_UP:
				return 4;
				break;
			}
		}
	}
};