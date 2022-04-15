#include <string>
#include <iostream>

using std::cout;
class Note
{
    //Turn into a linked list item, and build up a "Scale" from them.
    //Scalable to include additonal items later on0

public:

    enum NoteList
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
    
    NoteList note;
    Note* next;

    Note();
    Note(NoteList inNote);
    Note(NoteList inNote, Note& prevNote);
    
    std::string getNote(int noteNum);


    

private:

    

    //static const char* enum_str[] = {"C Major" , "C Minor"};
};

