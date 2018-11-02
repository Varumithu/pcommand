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

class CopyCommand : public Command {
    size_t ind1, ind2;
public:
    CopyCommand(size_t ind1, size_t ind2) : ind1(ind1), ind2(ind2) {}
    void Execute();
};
