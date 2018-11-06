#ifndef _MYCOMMANDPATTERNLINEEDITORDOTH_
#define _MYCOMMANDPATTERNLINEEDITORDOTH_

#include <string>
#include <iostream>
#include <vector>

#include "document.h"
#include "command.h"





class Editor
{
	std::string doc;
	std::vector<Command*> DoneCommands, UndoneCommands;
	Command* command;
	std::string clipboard;
	void clear_undone();
public:
	void Insert(size_t ind, std::string str);

	void Copy(size_t ind1, size_t ind2);
	void Paste(size_t dest);
	void Undo();
	void Redo();
	void Print();
	void Append(std::string& str);
};


#endif