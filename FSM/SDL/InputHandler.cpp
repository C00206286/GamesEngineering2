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
}

InputHandler::States InputHandler::getCurrent() 
{
	return current;
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
			}
			
			//button_Space->execute();
			//macroCmd->add(button_Space);
			break;
		case SDLK_UP:
			if (getCurrent() == Idle)
			{
				finiteStateMachine->climbing();
				setCurrent(Climbing);
			}
			break;
		case SDLK_RETURN:

			if (getCurrent() != Idle)
			{
				finiteStateMachine->idle();
				setCurrent(Idle);
			}
			break;
		}
	}
}
