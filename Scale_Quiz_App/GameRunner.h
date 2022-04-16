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


    Gamerunner(Gamerunner const&) = delete; //copy constructor
    Gamerunner& operator=(const Gamerunner&) = delete; //copy assignment operator
    ~Gamerunner(); //destructor

private:
    Gamerunner(); //default constructor
    
    Scale currentScale;


    //do better
    bool runningFlag;
    string userInput;

    int getRandomNum(int min, int max);
    int randomizeNote();
    int randomizeScaleType();

    void printAllScales();

    string getStringForEnums(int enum_val);

    
 

};

