#ifndef _MYCOMMANDPATTERNLINEEDITORDOTH_
#define _MYCOMMANDPATTERNLINEEDITORDOTH_

#include <string>
#include <iostream>
#include <vector>

#include "command.h"





class Editor
{
	std::string doc;
	std::vector<Command*> DoneCommands, UndoneCommands;
	Command* command;
	std::string clipboard;
	void clear_undone();
public:
	void Insert(const size_t ind, const std::string& str);

	void Copy(const size_t ind1, const size_t ind2);
	void Paste(const size_t dest);
	void Undo();
	void Redo();
	void Print();
	void Append(const std::string& str);
};


#endif