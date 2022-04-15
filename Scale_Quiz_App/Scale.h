#include "Notes.h"

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;
using std::endl;

class Scale
{

public:
	enum ScaleType
	{
		Major = 1,
		Minor,
		Locrian,
		Lydian,
		NOTSCALE
	};

	ScaleType scaleName;
	Note::NoteList scaleRootNote;
	Note* headerNoteNode;

	Scale();
	Scale(ScaleType inScaleName, Note::NoteList inRootNote, Note* inHeader);
	Scale(ScaleType inScaleName, Note::NoteList inRootNote);

	void LoadScale();
	void addNoteToScale(int inScaleNum);

	//For scales and their formulas
	//https://en.wikipedia.org/wiki/List_of_musical_scales_and_modes

	void LoadMajorScale(int rootNum);
	void LoadMinorScale(int rootNum);

	void printScale();

	std::string getScale(int noteNum)
	{
		//This is a bad way to do it, but want to get it working

		switch (noteNum) {
		case 1:
			return "Major ";
		case 2:
			return "Minor ";
		case 3:
			return "Locrian ";
		case 4:
			return "Lydian ";
		default:
			return "none ";
		}

	}

private:


};

