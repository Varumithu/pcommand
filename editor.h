#ifndef _MYCOMMANDPATTERNLINEEDITORDOTH_
#define _MYCOMMANDPATTERNLINEEDITORDOTH_

#include <string>
#include <iostream>
#include <vector>

#include "document.h"
#include "command.h"

const size_t arr_size = 10;




class Editor
{
	Document doc;
	std::vector<Command*> DoneCommands, UndoneCommands;
	Command* command;
	std::string clipboard;
	void clear_undone();
public:
	void Insert(size_t ind, std::string str);


	void Undo();
	void Redo();
	void Print();
	void Append(std::string& str);
};


#endif