#include "InputHandler.h"

InputHandler::InputHandler()
{
	finiteStateMachine = new Animation();
}

InputHandler::~InputHandler()
{

}

void InputHandler::handleInput(SDL_Event & event)
{
	switch (event.type)
	{
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
	
		case SDLK_SPACE:
			finiteStateMachine->jumping();
			//button_Space->execute();
			//macroCmd->add(button_Space);
			break;
		case SDLK_UP:
			finiteStateMachine->climbing();
			break;
		case SDLK_h:
			finiteStateMachine->idle();
			break;
		}
	}
}