//
// Created by valmit on 02/11/18.
//

#include "command.h"

void CopyCommand::Execute() {
    if (ind2 < doc->size()) {
        clipboard.clear();
        for (size_t i = ind1; i < ind2; ++i) {
            clipboard.push_back((*doc)[i]);
        }
    }
    else {
        //TODO exceptions
    }
}