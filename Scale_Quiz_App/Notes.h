#include <string>
#include <iostream>
#include "Helper.h"

using std::cout;

class Note
{
    //Turn into a linked list item, and build up a "Scale" from them.
    //Scalable to include additonal items later on0

public:

    
    
    Helper::NoteList note;
    Note* next;

    Note(); //default constructor
    Note(Helper::NoteList inNote);
    Note(Helper::NoteList inNote, Note& prevNote);
    
    //Note(Note const&); //copy constructor
    //Note& operator=(const Note&); //copy assignment operator
    //~Note();//destructor


    std::string getNote(Helper::NoteList noteNum);


    

private:

    

    //static const char* enum_str[] = {"C Major" , "C Minor"};
};

