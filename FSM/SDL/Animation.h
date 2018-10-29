#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Animation
{
	class State* current;
public:
	Animation();
	void setCurrent(State* s)
	{
		current = s;
	}
	void idle();
	void jumping();
	void climbing();
	SDL_Rect AnimationUpdate(SDL_Rect rect);
};
