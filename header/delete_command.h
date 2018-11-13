//
// Created by valmit on 13/11/18.
//

#ifndef PATTERN_COMMAND_DELETE_COMMAND_H
#define PATTERN_COMMAND_DELETE_COMMAND_H

#include "editor.h"

class DeleteCommand : public Command {
    size_t ind1, ind2;
    std::string save_for_undo;
public:
    DeleteCommand(size_t ind1, size_t ind2) : ind1(ind1), ind2(ind2) {}
    void Execute() override;
    void Undo() override;
};


#endif //PATTERN_COMMAND_DELETE_COMMAND_H
