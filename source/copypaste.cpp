//
// Created by valmit on 02/11/18.
//

#include "../header/command.h"

void CopyCommand::Execute() {
    if (ind2 < doc->size()) {
        clipboard.clear();
        clipboard.reserve(doc->size());
        doc->copy(clipboard.data(), ind2 - ind1 + 1, ind1);
        clipboard.push_back('\0');
    }
    else {
        //TODO exceptions
    }
}

void PasteCommand::Execute() {
	if (dest < doc->size()) {
		doc->insert(dest, clipboard);
	}
	else {
		//TODO exceptions
	}
}

void PasteCommand::Undo() {
	doc->erase(doc->begin() + dest, doc->begin() + dest + clipboard.size() - 1);
}