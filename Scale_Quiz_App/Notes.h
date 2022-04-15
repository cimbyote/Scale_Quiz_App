#include <string>
#include <iostream>

using std::cout;
class NoteNode
{
    //Turn into a linked list item, and build up a "Scale" from them.
    //Scalable to include additonal items later on0
    //Get a way to print the scale names

public:

    enum Note
    {
        C = 1,
        Cs, //s is #
        D,
        Ds,
        E,
        F,
        Fs,
        G,
        Gs,
        A,
        As,
        B,
        NONE
    };
    
    Note note;
    NoteNode* next;

    NoteNode();
    NoteNode(Note inNote);
    NoteNode(Note inNote, NoteNode& prevNote);
    
    std::string getNote(int noteNum);


    

private:

    

    //static const char* enum_str[] = {"C Major" , "C Minor"};
};

