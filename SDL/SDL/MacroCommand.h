#pragma once
#include "Command.h"
#include <iostream>
#include <list>

class MacroCommand : public Command {
public:
	MacroCommand();
	virtual ~MacroCommand();
	virtual void add(Command* command);
	virtual void remove(Command* command);
	virtual void undo();
	virtual void redo();
	virtual void execute();
private:
	std::list<Command*> Commands;
	Command * undoneCommand;
	bool undone = false;
};
