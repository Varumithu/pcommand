//
// Created by valmit on 13/11/18.
//

#include "../header/command.h"
#include "../header/delete_command.h"
#include "../header/editor_exceptions.h"

void DeleteCommand::Execute() {
    if (ind2 < doc->size() && ind1 < ind2) {
        size_t substr_size = ind2 - ind1 + 1;
        save_for_undo.resize(substr_size);
        doc->copy(save_for_undo.data(), substr_size, ind1);
        doc->erase(ind1, substr_size);
    }
    else {
        throw invalid_arguments();
    }
}

void DeleteCommand::Undo() {
    doc->insert(ind1, save_for_undo);
}