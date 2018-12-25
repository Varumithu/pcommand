#pragma once

#include <string>

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



