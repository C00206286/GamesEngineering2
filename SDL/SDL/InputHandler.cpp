#include "InputHandler.h"

InputHandler::InputHandler()
{
	button_Enter = new FireCommand();
	button_V = new MeleeCommand();
	button_Ctrl = new CrouchCommand();
	button_Space = new JumpCommand();
	button_C = new ShieldCommand();
	macroCmd = new MacroCommand();
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
		case SDLK_RETURN:
			button_Enter->execute();
			macroCmd->add(button_Enter);
			break;
		case SDLK_v:
			button_V->execute();
			macroCmd->add(button_V);
			break;
		case SDLK_LCTRL:
			button_Ctrl->execute();
			macroCmd->add(button_Ctrl);
			break;
		case SDLK_SPACE:
			button_Space->execute();
			macroCmd->add(button_Space);
			break;
		case SDLK_c:
			button_C->execute();
			macroCmd->add(button_C);
			break;
		case SDLK_b:
			macroCmd->execute();
			break;
		}
	}
}