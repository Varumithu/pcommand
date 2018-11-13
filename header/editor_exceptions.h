//
// Created by valmit on 13/11/18.
//

#ifndef PATTERN_COMMAND_EDITOR_EXCEPTIONS_H
#define PATTERN_COMMAND_EDITOR_EXCEPTIONS_H

#include <exception>

class editor_exception : std::exception {

};

class parser_exception : editor_exception {

};

class unknown_command : parser_exception { //this is thrown if there's no parser function in the map with corresponding name

};

class unparsable_arguments : parser_exception { // this is thrown if parsing functions cannot understand arguments

};

class invalid_arguments : editor_exception { //this is thrown by command member function

};

#endif //PATTERN_COMMAND_EDITOR_EXCEPTIONS_H
