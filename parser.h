#include "editor.h"

#include <iostream>

class parser final {
private:
	std::string line;
public:
	void parse(std::istream& input);
};