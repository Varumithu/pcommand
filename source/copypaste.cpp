//
// Created by valmit on 02/11/18.
//

#include "../header/command.h"
#include "../header/copypaste_commands.h"
#include "../header/editor_exceptions.h"


void CopyCommand::Execute() {
    if (ind2 < doc->size()) {
        clipboard.clear();
        size_t substr_size = ind2 - ind1 + 1;
        clipboard.resize(substr_size);
        doc->copy(clipboard.data(), substr_size, ind1);
    }
    else {
        throw invalid_arguments();
    }
}

void PasteCommand::Execute() {
	if (dest < doc->size()) {
		doc->insert(dest, clipboard);
	}
	else {
		throw invalid_arguments();
	}
}

void PasteCommand::Undo() {
	doc->erase(doc->begin() + dest, doc->begin() + dest + clipboard.size() - 1);
}