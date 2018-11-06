#include "command.h"


void InsertCommand::Execute()
{
	doc->insert(ind, str);
}

void InsertCommand::Undo()
{
	doc->erase(ind, ind + str.size());
}


