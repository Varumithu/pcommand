#include <gtest/gtest.h>

#include "editor.h"


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

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}