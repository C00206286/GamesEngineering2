#include "InputHandler.h"

InputHandler::InputHandler()
{
	finiteStateMachine = new Animation();
}

InputHandler::~InputHandler()
{

}

SDL_Rect InputHandler::handlerUpdate(SDL_Rect rectImage)
{
	return finiteStateMachine->AnimationUpdate(rectImage);
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
			break;
		case SDLK_UP:
				finiteStateMachine->climbing();
			break;
		case SDLK_RETURN:
				finiteStateMachine->idle();
			break;
		}
	}
}
