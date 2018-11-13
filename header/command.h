#pragma once

#include <string>
/*
 * TODO one thing i nned to do is add broken_command flag to every command, so that if it throws exception it is then not undone/redone or whatever
 *
 */

class Command
{
protected:
	std::string * doc;
public:
	virtual ~Command() {}
	virtual void Execute() = 0;
	virtual void Undo() = 0;
//	virtual void Redo() = 0;
	void setDocument(std::string * _doc);
};



