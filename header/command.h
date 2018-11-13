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

class InsertCommand : public Command
{
	size_t ind;
	const std::string str;
public:
	InsertCommand(size_t _ind, const std::string& _str) : ind(_ind), str(_str) {}

	void Execute() override;
//	void Redo();
	void Undo() override;
};

class CopyCommand : public Command {
    size_t ind1, ind2;
    std::string& clipboard;
public:
    CopyCommand(size_t ind1, size_t ind2, std::string& clipboard) : ind1(ind1), ind2(ind2), clipboard(clipboard) {}
    void Execute() override;
	void Undo() override{}
};

class PasteCommand : public Command {
	size_t dest;
	const std::string& clipboard;
public:
	PasteCommand(size_t dest, const std::string& clipboard) : dest(dest), clipboard(clipboard) {}
	void Execute() override;
	void Undo() override;
};

class DeleteCommand : public Command {
    size_t ind1, ind2;
    std::string save_for_undo;
public:
    DeleteCommand(size_t ind1, size_t ind2) : ind1(ind1), ind2(ind2) {}
    void Execute() override;
    void Undo() override;
};
