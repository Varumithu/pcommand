#pragma once

#include "editor.h"

#include <iostream>
#include <map>

typedef void (*parsing_function)(std::string&, Editor&);

class parser final {
private:
    std::map<std::string, parsing_function> parsers;
public:
    parser(Editor& my_editor);
    std::string line;
	void parse(std::istream& input);
    Editor& my_editor;
};
