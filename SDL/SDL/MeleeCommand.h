#pragma once
#include "Command.h"
#include <iostream>

class MeleeCommand : public Command
{
public:
	virtual void execute() { std::cout << "Melee!" << std::endl; }
};
