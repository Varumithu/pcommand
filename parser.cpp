#include "parser.h"

#include <sstream>

void parser::parse(std::istream& input) {
	std::getline(input, line);
    std::string first_token;
    std::getline(std::istringstream{line}, first_token, ' ');
    line.erase(line.begin(), line.begin() + first_token.size() - 1);
    if (first_token == "copy") {
        state = new copy_parser_state();
    }
    else if (first_token == "insert") {
        state = new insert_parser_state();
    }
    else if (first_token == "paste") {
        state = new paste_parser_state();
    }
    else if (first_token == "delete") {
        state = new delete_parser_state();
    }
    else if (first_token == "undo" ) {
        state = new undo_parser_state();
    }
    else if (first_token == "redo") {
        state = new redo_parser_state();
    }
    else {
        //TODO exceptions
    }
    state->parser = this;
    state->call_editor(); // bad
}