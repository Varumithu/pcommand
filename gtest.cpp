#include <gtest/gtest.h>

#include "editor.h"


TEST(EditorTesting, InsertTest) {
	Editor edit;

}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	char s = '1';
	int line, line_b;
	std::string str;
	Editor res;
	while (s != 'e')
	{
		std::cout << "What to do: \n1.Add a line\n2.Undo last command" << std::endl;
		std::cin >> s;
		switch (s)
		{
		case '1':
			std::cout << "What line to insert: ";
			std::cin >> line;
			--line;
			std::cout << "What to insert: ";
			std::cin >> str;
			res.Insert(line, str);
			break;
		case '2':
			res.Undo();
			break;
		}
		std::cout << "$$$DOCUMENT$$$" << std::endl;
		res.Print();
		std::cout << "$$$DOCUMENT$$$" << std::endl;
	}
}