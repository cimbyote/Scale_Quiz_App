#include <string>

class Notes
{
    //Make a singleton? find a pattern to keep the memory usage done
    //Get a way to print the scale names

public:
    enum Scales
    {
        Major = 1,
        Minor,
        Locrian,
        Lydian,
    };

    enum NotesOfScale
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
        B
    };


    Notes();
    
    std::string getNote(int noteNum);


    

private:

    

    //static const char* enum_str[] = {"C Major" , "C Minor"};
};

