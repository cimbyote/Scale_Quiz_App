#ifndef HELPER_H
#define HELPER_H


class Helper{

public:
    enum class NoteList
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
    enum class ScaleType
    {
        Major = 1,
        Minor,
        Locrian,
        Lydian,
        NOTSCALE
    };

};

#endif /* MOVE_H */

