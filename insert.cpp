#include "command.h"


void InsertCommand::Execute()
{
	doc->Insert(ind, str);
}

void InsertCommand::Undo()
{
	doc->Remove(ind, ind + str.size() - 1);
}


