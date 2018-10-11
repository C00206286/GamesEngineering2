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
	undone = false;
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
		UndoneCommands.push_back(undoneCommand);
		Commands.pop_back();
		undone = true;
		std::cout << "Undone" << std::endl;
	}
}
void MacroCommand::redo()
{
	//if (undone == true)
	if(UndoneCommands.size() > 0 && undone == true)
	{
		Commands.push_back(UndoneCommands.back());
		UndoneCommands.pop_back();
		std::cout << "Redone" << std::endl;
	}
}