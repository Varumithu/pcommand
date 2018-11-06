#pragma once

#include "editor.h"

#include <iostream>

class base_parser_state {
private:
    virtual void parse_remaining() = 0;
public:
    virtual ~base_parser_state() = 0;
    virtual void call_editor() = 0;
    parser* parser;
};

class copy_parser_state : public base_parser_state {
    void parse_remaining();
public:
    ~copy_parser_state(){}
    void call_editor(){}
};

class insert_parser_state : public base_parser_state {
    void parse_remaining();
public:
    ~insert_parser_state(){}
    void call_editor(){}
};

class paste_parser_state : public base_parser_state {
    void parse_remaining();
public:
    ~paste_parser_state(){}
    void call_editor(){}
};

class delete_parser_state : public base_parser_state {
    void parse_remaining();
public:
    ~delete_parser_state(){}
    void call_editor(){}
};

class undo_parser_state : public base_parser_state {
    void parse_remaining();
public:
    ~undo_parser_state(){}
    void call_editor(){}
};

class redo_parser_state : public base_parser_state {
    void parse_remaining();
public:
    ~redo_parser_state(){}
    void call_editor(){}
};

class parser final {
private:
    base_parser_state* state;
	
public:
    std::string line;
	void parse(std::istream& input);
    Editor& my_editor;
};