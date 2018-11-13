//
// Created by valmit on 13/11/18.
//

#ifndef PATTERN_COMMAND_INSERT_COMMAND_H
#define PATTERN_COMMAND_INSERT_COMMAND_H

#include "editor.h"



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







#endif //PATTERN_COMMAND_INSERT_COMMAND_H
