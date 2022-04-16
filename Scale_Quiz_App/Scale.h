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

