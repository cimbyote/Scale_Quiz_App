#include "GameRunner.h"

Gamerunner::Gamerunner() //default
{
	cout << "Gamerunner has been made" << endl;
	noteInstance = new Notes();
	currentNote = 0;
	currentScale = 0;
	runningFlag = false;
}



void Gamerunner::play()
{
	runningFlag = true;
	cout << "Game is running Play" << endl;

	currentNote = randomizeNote();
	currentScale = randomizeScaleType();
	cout << currentNote << endl;

	//cout << "Write out the " << getStringForEnum(currentNote) << " scale, one note at a time" << endl;
	//cout << "Hit enter after each individual letter" << endl;
	//cout << "Enter in Q to quit." << endl;

	// << LoadMajorScale(currentNote) << endl;

	printAllScales();

	//int counter = 0;

	//while (runningFlag)
	//{
	//	cin >> userInput;

	//	cout << userInput << endl;

	//	cout << ++counter << endl;

	//	if ((counter == 8)||(!userInput.compare("Q")))
	//	{
	//		runningFlag = false;
	//	}
	//}

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
	return getRandomNum(1, 4);
}

void Gamerunner::printAllScales()
{
	cout << "Printing All Scales" << endl;
	for (int i = 1; i <= 12; i++)
	{
		cout << i<<": " << LoadMajorScale(i) << endl;
	}
}

string Gamerunner::getStringForEnums(int enum_val)
{
	//string tmp(noteInstance->enum_str[enum_val]);
	string tmp("STUB");
	return tmp;
}

string Gamerunner::LoadMajorScale(int scaleNum)
{
	//wwhwwwh
	//2212221
	//0123456
	string outputString = "";
	int notesLoaded = 0;
	
	int startingNote = scaleNum;
	int scaleClimber = startingNote;

	while (notesLoaded < 8)
	{

		//outputString.append(noteInstance->getNote(scaleClimber));

		//Load notes of scale dynamically for fun

		//TODO: Make this work all the time, not just on a few scales

		if (scaleClimber == 13) {
			
			scaleClimber = 1;
			
		}
		else if (scaleClimber == 14) {

			scaleClimber = 2;
		}
		else
		{
			//whole
			if ((notesLoaded == 0) || (notesLoaded == 1) || (notesLoaded == 3) || (notesLoaded == 4) || (notesLoaded == 5))
			{
				outputString.append(noteInstance->getNote(scaleClimber)+"\t");
				scaleClimber += 2; //move forward for next
			}
			//half
			else if ((notesLoaded == 2) || (notesLoaded == 6))
			{
				outputString.append(noteInstance->getNote(scaleClimber) + "\t");
				++scaleClimber; //move forward for next
			}
			//reset for octave
			else if (notesLoaded == 7)
			{
				scaleClimber = startingNote;
				outputString.append(noteInstance->getNote(scaleClimber) + "\t");
			}
			++notesLoaded;
		}

		//1,3,4,6,8,10,11,1
		
	}
	

	return outputString;
}

string Gamerunner::LoadMinorScale(int scaleNum)
{
	//whole, half, whole, whole, half, whole, whole. 
	return string();
}
