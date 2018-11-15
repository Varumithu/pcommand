#include <gtest/gtest.h>

#include "../header/editor.h"
#include "../header/parser.h"

#include <sstream>
#include <string>
#include <iostream>

TEST(EditorTesting, InsertTest) {
	Editor edit;
	std::string blah {"blah blah"};
	edit.Append(blah);
	edit.Print();
	edit.Insert(4, blah);
	edit.Print();
}

TEST(EditorTesting, AppendUndoRedoTest) {
	Editor edit;
	std::string blah {"blah blah"};
	edit.Append(blah);
	edit.Print();
	edit.Undo();
	edit.Print();
	edit.Redo();
	edit.Print();
}

TEST(EditorTesting, CopyPasteTest) {
	Editor edit;
	std::string blah{ "blah blah" };
	edit.Append(blah);
	edit.Print();
	edit.Copy(0, 2);
	edit.Paste(4);
	edit.Print();
	edit.Undo();
	edit.Print();
}

TEST(EditorTesting, ParsingTest) {
	Editor edit;
	parser test(edit);
	std::string blah{"blah"};
	edit.Append(blah);
	edit.Append(" ");
	edit.Print();
    std::istringstream input_copy("copy 0 3");
//    std::string ddd;
//    input_copy >> ddd;
	test.parse(input_copy);
    std::istringstream input_paste("paste 5");
    test.parse(input_paste);
    edit.Print();
    std::istringstream input_insert("insert \"loli\" 5");
    test.parse(input_insert);
    std::istringstream input_undo("undo");
    test.parse(input_undo);
    edit.Print();
    std::istringstream input_redo("redo");
    test.parse(input_redo);
    edit.Print();
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();



}