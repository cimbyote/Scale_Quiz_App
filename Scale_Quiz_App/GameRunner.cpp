#include "GameRunner.h"

Gamerunner::Gamerunner() //default
{
	cout << "Gamerunner has been made" << endl;
	runningFlag = false;
}



void Gamerunner::play()
{
	runningFlag = true;
	cout << "Game is running Play" << endl;

	currentScale = Scale(static_cast<Scale::ScaleType>(randomizeScaleType()), static_cast<Note::NoteList>(randomizeNote()));

	currentScale.LoadScale();

	currentScale.printScale();
}



int Gamerunner::getRandomNum(int min, int max)
{
	//TODO: Figure out why this works

	//http://www.cplusplus.com/forum/beginner/183358/
	//http://www.cplusplus.com/reference/random/mersenne_twister_engine/operator%28%29/

	// obtain a seed from the system clock:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::mt19937 generator(seed);  // mt19937 is a standard mersenne_twister_engine

	return (generator() % (max - min + 1)) + min;
}

int Gamerunner::randomizeNote()
{
	return getRandomNum(1, 12);
}

int Gamerunner::randomizeScaleType()
{
	return 1;
	//return getRandomNum(1, 4);
}

void Gamerunner::printAllScales()
{
	cout << "Printing All Scales" << endl;
	for (int i = 1; i <= 12; i++)
	{
		//cout << i<<": " << LoadMajorScale(i) << endl;
	}
}

string Gamerunner::getStringForEnums(int enum_val)
{
	//string tmp(noteInstance->enum_str[enum_val]);
	string tmp("STUB");
	return tmp;
}
