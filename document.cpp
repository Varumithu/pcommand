#include "editor.h"

#include <string>
#include <iostream>


Document::Document() {
	data.reserve(arr_size); // at least for 10 symbols
}

void Document::Insert(size_t ind, const std::string & str) {
	if (ind > data.size()) {
		throw 1; //TODO make exceptions
	}
	if (data.max_size() >= data.size() + str.size()) {
		data.insert(ind, str);
	}
	else {
		data.reserve(data.size() + str.size());
		data.insert(ind, str);
	}
}

void Document::Remove(size_t ind1, size_t ind2) {
	if (ind2 < data.size()) { // i will not check for 1nd1 > ind2
		data.erase(ind1, ind2 - ind1 + 1);
	}
	else throw 2; // TODO exceptions
}

char& Document::operator [] (size_t x) {
	return data[x];
}

void Document::Print()
{
	std::cout << "$$$BEGIN$$$" << std::endl;
	for (size_t i = 0; i < data.size(); ++i)
	{
		std::cout << data[i];
	}
	std::cout << std::endl << "$$$END$$$" << std::endl;
}
