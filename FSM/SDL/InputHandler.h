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
	enum Animations
	{
		IdleAni,
		jumpingToIdle,
		idleToJumping,
		idleToClimbing,
		climbingToIdle,
		idling
	};
	void handleInput(SDL_Event & event);
	void setCurrent(States);
	States getCurrent();
	void setCurrentAni(Animations);
	Animations getCurrentAni();

private:

	Animation * finiteStateMachine;
	States current;
	Animations currentAni;
};
