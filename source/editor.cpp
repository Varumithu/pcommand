#include <iostream>
#include <vector>
#include <string>

#include "../header/editor.h"


void Editor::Copy(const size_t ind1, const size_t ind2) {
	command = new CopyCommand(ind1, ind2, clipboard);
	command->setDocument(&doc);
	command->Execute();
}

void Editor::Paste(const size_t dest) {
	clear_undone();
	Insert(dest, clipboard);
}

void Editor::clear_undone() {
	while (UndoneCommands.size() > 0) {
		command = UndoneCommands.back();
		UndoneCommands.pop_back();
		delete command;
	}
}

void Editor::Insert(const size_t ind, const std::string& str)
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
		UndoneCommands.push_back(command);
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

void Editor::Append(const std::string& str) {
	clear_undone();
	command = new InsertCommand(doc.size(), str);
	command->setDocument(&doc);
	command->Execute();
	DoneCommands.push_back(command);
}

void Editor::Print()
{
	std::cout << "document_start-->" << doc << std::endl;
}



