#include "Helper.h"
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
	

	Helper::ScaleType scaleName;
	Helper::NoteList scaleRootNote;
	Note* headerNoteNode;

	Scale(); //default constructor
	Scale(Helper::ScaleType inScaleName, Helper::NoteList inRootNote, Note* inHeader);
	Scale(Helper::ScaleType inScaleName, Helper::NoteList inRootNote);
	Scale(int inScaleNum, int inRootNoteNum);

	//Scale(Scale const&); //copy constructor
	//Scale& operator=(const Scale&); //copy assignment operator
	//~Scale(); //destructor


	void LoadScale();
	void addNoteToScale(int inScaleNum);

	//For scales and their formulas
	//https://en.wikipedia.org/wiki/List_of_musical_scales_and_modes

	void LoadMajorScale(Helper::NoteList rootNum);
	void LoadMinorScale(Helper::NoteList rootNum);

	void printScale();

	Helper::ScaleType getScale(int noteNum);
	Helper::NoteList getNote(int inNoteNum);

	std::string getScaleToPrint(Helper::ScaleType scaleType)
	{
		//This is a bad way to do it, but want to get it working

		switch (scaleType) {
		case Helper::ScaleType::Major:
			return "Major ";
		case Helper::ScaleType::Minor:
			return "Minor ";
		case Helper::ScaleType::Locrian:
			return "Locrian ";
		case Helper::ScaleType::Lydian:
			return "Lydian ";
		default:
			return "none ";
		}

	}

private:


};

