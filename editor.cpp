#include <iostream>
#include <vector>
#include <string>

#include "editor.h"




void Editor::clear_undone() {
	while (UndoneCommands.size() > 0) {
		command = UndoneCommands.back();
		UndoneCommands.pop_back();
		delete command;
	}
}

void Editor::Insert(size_t ind, std::string str)
{
	clear_undone();
	command = new InsertCommand(ind, str);
	command->setDocument(&doc);
	command->Execute();
	DoneCommands.push_back(command);
}

void Editor::Undo() {
	if (DoneCommands.size() > 0){

		command = DoneCommands.back();
		DoneCommands.pop_back();
		command->Undo();
	}
}

void Editor::Redo() {
	if (UndoneCommands.size() > 0) {
		command = UndoneCommands.back();
		UndoneCommands.pop_back();
		command->Execute();
		DoneCommands.push_back(command);
	}
}

void Editor::Append(std::string& str) {
	clear_undone();
	command = new InsertCommand(doc.size(), str);
	command->setDocument(&doc);
	command->Execute();
	DoneCommands.push_back(command);
}

void Editor::Print()
{
	clear_undone();
	doc.Print();
}



