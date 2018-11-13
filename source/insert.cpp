#include "../header/command.h"


void InsertCommand::Execute()
{
	doc->insert(ind, str);
}

void InsertCommand::Undo()
{
	doc->erase(ind, str.size());
}


