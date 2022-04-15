#include "Notes.h"

NoteNode::NoteNode()
{
	note = Note::NONE;
	next = nullptr;
}

NoteNode::NoteNode(Note inNote)
{
	note = inNote;
	next = nullptr;
	cout << getNote(note) << " Note has been made\n"; //delete this after debugging
}

NoteNode::NoteNode(Note inNote, NoteNode& prevNote)
{
	note = inNote;
	next = nullptr;
	prevNote.next = this;
}

std::string NoteNode::getNote(int noteNum)
{
	//This is a bad way to do it, but want to get it working

	switch (noteNum) {
	case 1:
		return "C ";
	case 2:
		return "C# ";
	case 3:
		return "D ";
	case 4:
		return "D# ";
	case 5:
		return "E ";
	case 6:
		return "F ";
	case 7:
		return "F# ";
	case 8:
		return "G ";
	case 9:
		return "G# ";
	case 10:
		return "A ";
	case 11:
		return "A# ";
	case 12:
		return "B ";
	case 13:
		return"NONE";
	}
		
}
