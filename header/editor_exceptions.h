//
// Created by valmit on 13/11/18.
//

#ifndef PATTERN_COMMAND_EDITOR_EXCEPTIONS_H
#define PATTERN_COMMAND_EDITOR_EXCEPTIONS_H

#include <exception>
#include <string>

class editor_exception : std::exception {
public:
    std::string message;
    editor_exception() { message = "something went wrong with the editor"; }
};

class parser_exception : public editor_exception {
public:
    parser_exception() {message = "something went wrong in parsing"; }
};

class unknown_command : public parser_exception { //this is thrown if there's no parser function in the map with corresponding name
public:
    unknown_command() { message = "command not recognized"; }
};

class unparsable_arguments : public parser_exception { // this is thrown if parsing functions cannot understand arguments
public:
    unparsable_arguments() { message = "could not understand argumennts"; }
};

class invalid_arguments : public editor_exception { //this is thrown by command member function
public:
    invalid_arguments() { message = "arguments are invalid, though they were understood"; }
};

#endif //PATTERN_COMMAND_EDITOR_EXCEPTIONS_H
