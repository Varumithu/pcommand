#pragma once

#include <string>

class Document
{
	std::string data;
public:
	Document();
	size_t size() { return data.size(); }
	void Insert(size_t ind, const std::string & str);
	void Remove(size_t ind1, size_t ind2);

	char & operator [] (size_t x);

	void Print();
};
