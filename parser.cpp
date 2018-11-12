#include "parser.h"

#include <sstream>
#include <string>

void parse_copy(std::string& line, Editor& my_editor) {
    size_t ind1, ind2;
    std::istringstream{line} >> ind1 >> ind2; // i hope this works
    my_editor.Copy(ind1, ind2);
}


void parse_paste(std::string& line, Editor& my_editor) {
    size_t dest;
    std::istringstream{line} >> dest; // still hope this works;
    my_editor.Paste(dest);
}

void parse_insert(std::string& line, Editor& my_editor) {
    size_t dest;
    size_t temp = line.find_first_of('\"');
    if (temp == -1) {
        //TODO exceptions
    }
    line.erase(line.begin(), line.begin() + temp); // delete everything up to and including first "
    std::string user_input;
    std::getline(std::istringstream{line}, user_input, '"');
    line.erase(line.begin(), line.begin() + line.find_first_of('\"')); // delete ecerything up to and including second "

}

void parse_erase(std::string& line, Editor& my_editor) {

}

void parse_undo(std::string& line, Editor& my_editor) {

}

void parse_redo(std::string& line, Editor& my_editor) {

}

parser::parser(Editor& my_editor) : my_editor(my_editor) {
    parsing_function foo = &parse_copy;
    parsers.insert({"copy", foo});
    foo = &parse_paste;
    parsers.insert({"paste", foo});
    foo = &parse_insert;
    parsers.insert({"insert", foo});
    foo = &parse_erase;
    parsers.insert({"delete", foo});
    foo = &parse_undo;
    parsers.insert({"undo", foo});
    foo = &parse_redo;
    parsers.insert({"redo", foo});
}

void parser::parse(std::istream& input) {
	std::getline(input, line);
    std::string first_token;
    std::getline(std::istringstream{line}, first_token, ' ');
    line.erase(line.begin(), line.begin() + first_token.size() - 1);

    auto fooit = parsers.find(first_token);
    if (fooit == parsers.end()) {
        // TODO exceptions
    }
    else {
        fooit->second(line, my_editor);
    }

}