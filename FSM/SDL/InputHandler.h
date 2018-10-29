#pragma once
#include "Animation.h"

#include <SDL.h>

class InputHandler
{
public:
	InputHandler();
	~InputHandler();


	void handleInput(SDL_Event & event);
	SDL_Rect handlerUpdate(SDL_Rect rectImage);

private:

	Animation * finiteStateMachine;
};
