#include "Notes.h"

Note::Note()
{
	note = Helper::NoteList::NONE;
	next = nullptr;
}

Note::Note(Helper::NoteList inNote)
{
	note = inNote;
	next = nullptr;
	cout << getNote(note) << " Note has been made\n"; //delete this after debugging
}

Note::Note(Helper::NoteList inNote, Note& prevNote)
{
	note = inNote;
	next = nullptr;
	prevNote.next = this;
}

std::string Note::getNote(Helper::NoteList noteNum)
{
	//This is a bad way to do it, but want to get it working

	switch (noteNum) {
	case Helper::NoteList::C:
		return "C ";
	case Helper::NoteList::Cs:
		return "C# ";
	case Helper::NoteList::D:
		return "D ";
	case Helper::NoteList::Ds:
		return "D# ";
	case Helper::NoteList::E:
		return "E ";
	case Helper::NoteList::F:
		return "F ";
	case Helper::NoteList::Fs:
		return "F# ";
	case Helper::NoteList::G:
		return "G ";
	case Helper::NoteList::Gs:
		return "G# ";
	case Helper::NoteList::A:
		return "A ";
	case Helper::NoteList::As:
		return "A# ";
	case Helper::NoteList::B:
		return "B ";
	case Helper::NoteList::NONE:
		return"NONE";
	default:
		return "Error";
	}
}
