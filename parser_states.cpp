#include "parser.h"
#include "sstream"

void copy_parser_state::call_editor() {// what i expect in line : " ind1 ind2" 
    size_t ind1, ind2;
    std::istringstream{ parser->line } >> ind1 >> ind2; // i hope this works
    parser->my_editor.Copy(ind1, ind2);

}

void paste_parser_state::call_editor() {// expect " dest"
    size_t dest;
    std::istringstream{ parser->line } >> dest; // still hope this works;
    parser->my_editor.Paste(dest);
}

void insert_parser_state::call_editor(){//expect " string dest"
    size_t dest;
    size_t temp = parser->line.find_first_of('\"');
    if (temp == -1) {
        //TODO exceptions
    }
    parser->line.erase(parser->line.begin(), parser->line.begin() + temp); // delete everything up to and including first " 
    std::string user_input;
    std::getline(std::istringstream{parser->line}, user_input);
    parser->line.erase(parser->line.begin(), parser->line.begin() + parser->line.find_first_of('\"'));

}
