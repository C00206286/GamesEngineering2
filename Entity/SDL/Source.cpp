/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "HealthSystem.h"
#include "ControlSystem.h"
#include "RenderSystem.h"
#include "AISystem.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 1000;

int main(int argc, char* args[])
{
	double count = 0;
	Entity player(1);
	Entity cat(2);
	Entity dog(3);
	Entity alien(4);
	//PositionComponent pc;
	HealthComponent HealthComp;
	PositionComponent PositionComp(100,100);
	ControlComponent ControlComp;

	player.addComponent(&HealthComp);
	player.addComponent(&PositionComp);
	player.addComponent(&ControlComp);

	PositionComponent PositionComp2(400, 400);
	cat.addComponent(&HealthComp);
	cat.addComponent(&PositionComp2);

	PositionComponent PositionComp3(200, 100);
	dog.addComponent(&HealthComp);
	dog.addComponent(&PositionComp3);

	PositionComponent PositionComp4(100, 700);
	alien.addComponent(&HealthComp);
	alien.addComponent(&PositionComp4);


	HealthSystem hs;
	ControlSystem cs;
	RenderSystem rs;
	AISystem ais;
	//PositionSystem ps;
	hs.addEntity(&player);
	cs.addEntity(&player);
	rs.addEntity(&player);

	hs.addEntity(&cat);
	cs.addEntity(&cat);
	rs.addEntity(&cat);
	ais.addEntity(&cat);

	hs.addEntity(&dog);
	cs.addEntity(&dog);
	rs.addEntity(&dog);
	ais.addEntity(&dog);

	hs.addEntity(&alien);
	cs.addEntity(&alien);
	rs.addEntity(&alien);
	ais.addEntity(&alien);


	//ps.addEntity(player);

	int quit = 0;
	SDL_Event event;
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			//Update the surface
			SDL_UpdateWindowSurface(window);

		
			//Wait two seconds
			//SDL_Delay(2000);
		}
	}

	while (!quit)
	{
		ais.update();
		hs.update();
		cs.update();
		rs.update(screenSurface);
		SDL_UpdateWindowSurface(window);
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
	}

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}