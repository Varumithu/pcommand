#include "../header/command.h"
#include "../header/insert_command.h"

void InsertCommand::Execute()
{
	doc->insert(ind, str);
}

void InsertCommand::Undo()
{
	doc->erase(ind, str.size());
}


