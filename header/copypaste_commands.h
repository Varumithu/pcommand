//
// Created by valmit on 13/11/18.
//

#ifndef PATTERN_COMMAND_COPYPASTE_COMMANDS_H
#define PATTERN_COMMAND_COPYPASTE_COMMANDS_H

#include "editor.h"

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


#endif //PATTERN_COMMAND_COPYPASTE_COMMANDS_H
