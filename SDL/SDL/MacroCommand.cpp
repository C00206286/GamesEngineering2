#include "MacroCommand.h"


MacroCommand::MacroCommand()
{

}

MacroCommand::~MacroCommand()
{
	std::cout << "deconstructing" << std::endl;
}

void MacroCommand::add(Command* command)
{
	Commands.push_back(command);
}

void MacroCommand::remove(Command* command)
{
	Commands.remove(command);
}

void MacroCommand::execute()
{
	std::list<Command*>::iterator iter;
	for (iter = Commands.begin(); iter != Commands.end(); ++iter)
	{
		(*iter)->execute();
	}
	std::cout << "executed" << std::endl;
}
void MacroCommand::undo()
{
	if (Commands.size() > 0)
	{
		undoneCommand = Commands.back();
		Commands.pop_back();
		undone = true;
	}
}
void MacroCommand::redo()
{
	if (undone == true)
	{
		Commands.push_back(undoneCommand);
		undone = false;
	}
}