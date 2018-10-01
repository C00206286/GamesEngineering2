#pragma once
#include "Command.h"
#include "FireCommand.h"
#include "JumpCommand.h"
#include "CrouchCommand.h"
#include "MeleeCommand.h"
#include "MacroCommand.h"
#include "ShieldCommand.h"

#include <SDL.h>

class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	void handleInput(SDL_Event & event);

private:
	Command * button_Enter;
	Command * button_V;
	Command * button_Ctrl;
	Command * button_Space;
	Command * button_C;
	MacroCommand * macroCmd;
};
