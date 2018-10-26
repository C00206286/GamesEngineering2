#include "InputHandler.h"

InputHandler::InputHandler()
{
	finiteStateMachine = new Animation();
	current = Idle;
}

InputHandler::~InputHandler()
{

}
void InputHandler::setCurrent(States state)
{
	current = state;
	finiteStateMachine->idle();
}
void InputHandler::setCurrentAni(Animations ani)
{
	currentAni = ani;
}

InputHandler::States InputHandler::getCurrent() 
{
	return current;
}
InputHandler::Animations InputHandler::getCurrentAni()
{
	return currentAni;
}

void InputHandler::handleInput(SDL_Event & event)
{
	switch (event.type)
	{
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_SPACE:
			if (getCurrent() == Idle)
			{
				finiteStateMachine->jumping();
				setCurrent(Jumping);
				setCurrentAni(idleToJumping);
			}
			break;
		case SDLK_UP:
			if (getCurrent() == Idle)
			{
				finiteStateMachine->climbing();
				setCurrent(Climbing);
				setCurrentAni(idleToClimbing);
			}
			break;
		case SDLK_RETURN:

			if (getCurrent() != IdleAni)
			{
				if (getCurrent() == Climbing)
				{
					setCurrentAni(climbingToIdle);
				}
				else if (getCurrent() == Jumping)
				{
					setCurrentAni(jumpingToIdle);
				}
				finiteStateMachine->idle();
				setCurrent(Idle);
			}
			break;
		}
	}
}
