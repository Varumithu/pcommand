#include "../header/parser.h"
#include "../header/editor_exceptions.h"

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
    line.erase(0, temp + 1); // delete everything up to and including first "
    std::string user_input;
    std::getline(std::istringstream(line), user_input, '"');
    line.erase(0, line.find_first_of('\"') + 1); // delete ecerything up to and including second "
    std::istringstream(line) >> dest;
    my_editor.Insert(dest, user_input);
}

void parse_erase(std::string& line, Editor& my_editor) {//expect "ind1 ind2"
    size_t ind1, ind2;
    std::istringstream(line) >> ind1 >> ind2;
    my_editor.Erase(ind1, ind2);
}

void parse_undo(std::string& line, Editor& my_editor) {
    if (line.length() > 0) {
        throw unparsable_arguments();
    }
    my_editor.Undo();
}

void parse_redo(std::string& line, Editor& my_editor) {
    if (line.length() > 0) {
        throw unparsable_arguments();
    }
    my_editor.Redo();
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
    std::getline(std::istringstream(line), first_token, ' ');
    line.erase(line.begin(), line.begin() + first_token.size() + 1);
    auto fooit = parsers.find(first_token);
    if (fooit == parsers.end()) {
        throw unknown_command();
    }
    else {
        fooit->second(line, my_editor);
    }

}