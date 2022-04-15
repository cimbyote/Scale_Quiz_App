#include "Scale.h"

Scale::Scale()
{
	scaleName = Scales::NOTSCALE;
	scaleRootNote = NoteNode::Note::NONE;
	headerNoteNode = nullptr;
}

Scale::Scale(Scales inScaleName, NoteNode::Note inRootNote, NoteNode* inHeader)
{
	scaleName = inScaleName;
	scaleRootNote = inRootNote;
	headerNoteNode = inHeader;
}

Scale::Scale(Scales inScaleName, NoteNode::Note inRootNote)
{
	scaleName = inScaleName;
	scaleRootNote = inRootNote;
	headerNoteNode = nullptr;

	//Make the header node, and build the rest
	//headerNoteNode = inHeader;
}

void Scale::LoadScale()
{
	//if type = major, etc....

	LoadMajorScale(scaleRootNote);
}

void Scale::addNoteToScale(int inScaleNum)
{
	if (headerNoteNode != nullptr)
	{
		NoteNode* temp = new NoteNode(static_cast<NoteNode::Note>(inScaleNum));

		//walk the list until there is a null next

		NoteNode* walker = headerNoteNode;
		while (walker->next != nullptr)
		{
			walker = walker->next;
		}

		walker->next = temp;
		
	}
	else
	{
		headerNoteNode = new NoteNode(scaleRootNote);
	}
}

void Scale::LoadMajorScale(int inRootNote)
{
	//wwhwwwh
	//2212221
	//0123456

	this->scaleName = Scales::Major;
	this->scaleRootNote = static_cast<NoteNode::Note>(inRootNote);

	int notesLoaded = 0;

	int startingNote = inRootNote;
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