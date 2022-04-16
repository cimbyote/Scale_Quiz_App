#include "Scale.h"
#include "ConsolePrintColor.h"


Scale::Scale()
{
	scaleName = Helper::ScaleType::NOTSCALE;
	scaleRootNote = Helper::NoteList::NONE;
	headerNoteNode = nullptr;
}

Scale::Scale(Helper::ScaleType inScaleName, Helper::NoteList inRootNote, Note* inHeader)
{
	scaleName = inScaleName;
	scaleRootNote = inRootNote;
	headerNoteNode = inHeader;
}

Scale::Scale(Helper::ScaleType inScaleName, Helper::NoteList inRootNote)
{
	scaleName = inScaleName;
	scaleRootNote = inRootNote;
	headerNoteNode = nullptr;

	//Make the header node, and build the rest
	//headerNoteNode = inHeader;
}

Scale::Scale(int inScaleNum, int inRootNoteNum)
{
	scaleName = getScale(inScaleNum);
	scaleRootNote = getNote(inRootNoteNum);
	headerNoteNode = nullptr;
}

void Scale::LoadScale()
{
	//if type = major, etc....

	LoadMajorScale(scaleRootNote);
}

void Scale::printScale()
{
	//TODO: add protection later
	//TODO: move this kinda thing elsewhere, or change the format. output a string?

	//walk the list and print
	Note* walker = headerNoteNode;
	while (walker->next != nullptr)
	{
		cout << walker->getNoteToPrint(walker->note)<< "\t";
		

		walker = walker->next;
	}

	//print the last bit
	cout << RED << walker->getNoteToPrint(walker->note) << RESET;
}

Helper::ScaleType Scale::getScale(int noteNum)
{
	switch (noteNum) {
	case 1:
		return Helper::ScaleType::Major;
	case 2:
		return Helper::ScaleType::Minor;
	case 3:
		return Helper::ScaleType::Locrian;
	case 4:
		return Helper::ScaleType::Lydian;
	default:
		return Helper::ScaleType::NOTSCALE;
	}
}

Helper::NoteList Scale::getNote(int inNoteNum)
{
	switch (inNoteNum) {
	case 1:
		return Helper::NoteList::C;
	case 2:
		return Helper::NoteList::Cs;
	case 3:
		return Helper::NoteList::D;
	case 4:
		return Helper::NoteList::Ds;
	case 5:
		return Helper::NoteList::E;
	case 6:
		return Helper::NoteList::F;
	case 7:
		return Helper::NoteList::Fs;
	case 8:
		return Helper::NoteList::G;
	case 9:
		return Helper::NoteList::Gs;
	case 10:
		return Helper::NoteList::A;
	case 11:
		return Helper::NoteList::As;
	case 12:
		return Helper::NoteList::B;
	case 13:
		return Helper::NoteList::NONE;
	default:
		return Helper::NoteList::NONE;
	}
}

void Scale::addNoteToScale(int inScaleNum)
{
	if (headerNoteNode != nullptr)
	{
		Note* temp = new Note(getNote(inScaleNum));

		//walk the list until there is a null next

		Note* walker = headerNoteNode;
		while (walker->next != nullptr)
		{
			walker = walker->next;
		}

		walker->next = temp;
		
	}
	else
	{
		headerNoteNode = new Note(scaleRootNote);
	}
}

void Scale::LoadMajorScale(Helper::NoteList inRootNote)
{
	//wwhwwwh
	//2212221
	//0123456

	this->scaleName = Helper::ScaleType::Major;
	this->scaleRootNote = inRootNote;

	int notesLoaded = 0;

	int startingNote = static_cast<int>(inRootNote); //have to cast to int to use algorithm
	int scaleClimber = startingNote;

	//can't reasonable use a for loop, as there is inconsistent iteration progression
	while (notesLoaded < 8)
	{
		//Load notes of scale dynamically for fun
		if (scaleClimber == 13) { scaleClimber = 1; } //Reset back to C (Notes are continuous)
		else if (scaleClimber == 14) { scaleClimber = 2; } //Reset back to C# 
		else
		{
			//whole
			if ((notesLoaded == 0) || (notesLoaded == 1) || (notesLoaded == 3) || (notesLoaded == 4) || (notesLoaded == 5))
			{
				addNoteToScale(scaleClimber);
				scaleClimber += 2; //move forward for next
			}
			//half
			else if ((notesLoaded == 2) || (notesLoaded == 6))
			{
				addNoteToScale(scaleClimber);
				++scaleClimber; //move forward for next
			}
			//reset for octave
			else if (notesLoaded == 7)
			{
				scaleClimber = startingNote; //Re-add the last note
				addNoteToScale(scaleClimber);
			}
			++notesLoaded;
		}
	}
}

void Scale::LoadMinorScale(Helper::NoteList rootNum)
{
}


