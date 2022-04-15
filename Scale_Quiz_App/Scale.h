#include "Notes.h"


class Scale
{

public:
	enum Scales
	{
		Major = 1,
		Minor,
		Locrian,
		Lydian,
		NOTSCALE
	};

	Scales scaleName;
	NoteNode::Note scaleRootNote;
	NoteNode* headerNoteNode;

	Scale();
	Scale(Scales inScaleName, NoteNode::Note inRootNote, NoteNode* inHeader);
	Scale(Scales inScaleName, NoteNode::Note inRootNote);

	void LoadScale();
	void addNoteToScale(int inScaleNum);

	void LoadMajorScale(int scaleNum);

private:


};

