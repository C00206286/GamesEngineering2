#pragma once
#include "Command.h"
#include <iostream>

class FireCommand : public Command
{
public:
	virtual void execute() { std::cout << "Fire!" << std::endl; }
};
