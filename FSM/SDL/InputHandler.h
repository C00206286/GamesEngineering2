#pragma once
#include "Animation.h"

#include <SDL.h>

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	enum States
	{
		Jumping,
		Idle,
		Climbing
	};
	void handleInput(SDL_Event & event);
	void setCurrent(States);
	States getCurrent();

private:

	Animation * finiteStateMachine;
	States current;
};
