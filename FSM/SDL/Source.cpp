

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "InputHandler.h"
#include <string>
#include "State.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

double animationCount = 0;
double delayCount = 0;

InputHandler * handler = new InputHandler();

SDL_Rect rectMove;
SDL_Rect rectImage;



//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image
SDL_Surface* loadSurface(std::string path);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//Current displayed PNG image
SDL_Surface* gPNGSurface = NULL;

bool init()
{
	rectMove.x = 100;
	rectMove.y = 100;
	rectMove.h = 100;
	rectMove.w = 100;

	rectImage.x = 0;
	rectImage.y = 0;
	rectImage.h = 85;
	rectImage.w = 85;


	//Initialization flag
	bool success = true;


	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface(gWindow);
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load PNG surface
	gPNGSurface = loadSurface("grid.png");
	if (gPNGSurface == NULL)
	{
		printf("Failed to load PNG image!\n");
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded image
	SDL_FreeSurface(gPNGSurface);
	gPNGSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* loadSurface(std::string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					handler->handleInput(e);
		
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
				if (handler->getCurrentAni() == handler->IdleAni)
				{
					rectImage.y = 0;
					rectImage.x = 425;
					delayCount = delayCount + 1;
					if (delayCount > 10000)
					{
						animationCount = 0;
						delayCount = 0;
						handler->setCurrentAni(handler->idling);
					}
				}
				if (handler->getCurrentAni() == handler->idling)
				{
					rectImage.x = 0;
					rectImage.y = 425;
					if (rectImage.x < 510)
					{
						rectImage.x = rectImage.x + 85 * animationCount;
						if (delayCount > 1000)
						{
							if (animationCount < 5)
							{
								animationCount = animationCount + 1;
								delayCount = 0;
								std::cout << "ani count = " << animationCount << std::endl;

							}
							if (animationCount == 5)
							{
								animationCount = 0;
								handler->setCurrentAni(handler->IdleAni);
							}
						}
						delayCount = delayCount + 1;
					}
				}
				if (handler->getCurrentAni() == handler->idleToClimbing)
				{
					rectImage.x = 425;
					rectImage.y = 0;
					if (rectImage.x > 0)
					{
						rectImage.x = rectImage.x - 85 * animationCount;
						if (delayCount > 1000)
						{
							if (animationCount < 5)
							{

									animationCount = animationCount + 1;
									delayCount = 0;
								
							}
							if (animationCount == 5)
							{
								animationCount = 0;
								handler->setCurrentAni(handler->climbingToIdle);
							}
						}
						delayCount = delayCount + 1;
					}
				}
				if (handler->getCurrentAni() == handler->idleToJumping)
				{
					rectImage.x = 0;
					rectImage.y = 340;
					if (rectImage.x < 510)
					{
						rectImage.x = rectImage.x + 85 * animationCount;
						if (delayCount > 1000)
						{
							if (animationCount < 5)
							{
									animationCount = animationCount + 1;
									delayCount = 0;
							
							}
							if (animationCount == 5)
							{
								animationCount = 0;
								handler->setCurrentAni(handler->jumpingToIdle);
							}
						}
						delayCount = delayCount + 1;
					}
				}
				if (handler->getCurrentAni() == handler->jumpingToIdle)
				{
					rectImage.x = 425;
					rectImage.y = 340;
					if (rectImage.x > 0)
					{
						rectImage.x = rectImage.x - 85 * animationCount;
						if (delayCount > 1000)
						{
							if (animationCount < 5)
							{
									animationCount = animationCount + 1;
									delayCount = 0;							
							}
							if (animationCount == 5)
							{
								handler->setCurrent(handler->Idle);
								animationCount = 0;
								handler->setCurrentAni(handler->IdleAni);
							}

						
						}
						delayCount = delayCount + 1;
					}
				}
				if (handler->getCurrentAni() == handler->climbingToIdle)
				{
					rectImage.x = 0;
					rectImage.y = 0;
					if (rectImage.x < 510)
					{
						rectImage.x = rectImage.x + 85 * animationCount;
						if (delayCount > 1000)
						{
							if (animationCount < 5)
							{
									animationCount = animationCount + 1;
									delayCount = 0;						
							}
							if (animationCount == 5)
							{
								handler->setCurrent(handler->Idle);
								animationCount = 0;
								handler->setCurrentAni(handler->IdleAni);
							}

						}
						delayCount = delayCount + 1;
					}
				}
				rectImage.h = 85;
				rectImage.w = 85;
				//Apply the PNG image
				SDL_BlitSurface(gPNGSurface, &rectImage, gScreenSurface, &rectMove);

				//Update the surface
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}