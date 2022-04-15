#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include "Scale.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

//TODO: make a singleton
//TODO: make sure all big 4 are in

class Gamerunner 
{


public:

    static Gamerunner& getInstance()
    {
        static Gamerunner instance; // Guaranteed to be destroyed.
                              // Instantiated on first use.
        return instance;
    }

	void play();

    Gamerunner(Gamerunner const&) = delete;
    void operator=(Gamerunner const&) = delete;

private:
    Gamerunner();
    
    Scale currentScale;


    //do better
    bool runningFlag;
    string userInput;

    int getRandomNum(int min, int max);
    int randomizeNote();
    int randomizeScaleType();

    void printAllScales();

    string getStringForEnums(int enum_val);

    //For scales and their formulas
    //https://en.wikipedia.org/wiki/List_of_musical_scales_and_modes
    
    string LoadMinorScale(int scaleNum);

};

