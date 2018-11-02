#pragma once

#include "document.h"

#include <string>

class Command
{
protected:
	Document * doc;
public:
	virtual ~Command() {}
	virtual void Execute() = 0;
	virtual void Undo() = 0;
//	virtual void Redo() = 0;
	void setDocument(Document * _doc);
};

class InsertCommand : public Command
{
	size_t ind;
	std::string str;
public:
	InsertCommand(size_t _ind, const std::string& _str) : ind(_ind), str(_str) {}

	void Execute();
//	void Redo();
	void Undo();
};

class AppendCommand : public Command
{
	size_t ind;
	std::string str;
public:
	AppendCommand(size_t _ind, const std::string & _str) : ind(_ind), str(_str) {}

	void Execute();
	//	void Redo();
	void Undo();
};
