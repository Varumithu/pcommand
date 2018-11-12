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


//namespace parsing {
//    void parse_copy(std::string& line, Editor& my_editor);
//
//    void parse_paste(std::string& line, Editor& my_editor);
//
//    void parse_insert(std::string& line, Editor& my_editor);
//
//    void parse_erase(std::string& line, Editor& my_editor);
//
//    void parse_undo(std::string& line, Editor& my_editor);
//
//    void parse_redo(std::string& line, Editor& my_editor);
//}