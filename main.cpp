// Denise Montesdeoca Project 2
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
/**
ifstream infile("A-small-practice.in");       // file it is reading from
ofstream outfile("output_small.txt");         // file it is printing to
**/
ifstream infile("A-large-practice.in");       // file it is reading from
ofstream outfile("output_large.txt");         // file it is printing to

const char ORANGE_ROBOT = 'O';
const char BLUE_ROBOT = 'B';

int main(){
	int location, orangeLocation, blueLocation,
            blueTime, orangeTime, seconds, time,
            caseNumb, moves;
    	char robot;

	infile >> caseNumb;
	for(int caseIn = 0; caseIn < caseNumb; caseIn++){   // goes through all the cases
		orangeLocation = 1; // orange robot starting point
        	blueLocation = 1;   // blue robot starting point
		seconds = 0;        // reset seconds for the next case
	 	blueTime = 0;       // time total making moves until orange robots turn to push button
        	orangeTime = 0;     // time total making moves until blue robots turn to push button

		infile >> moves;    // read steps
		for (int i = 0; i < moves; i++){ // go through every move of the sequence
			infile >> robot;    	 // read what robot
			infile >> location; 	 // read position robot must get to

			if(robot == BLUE_ROBOT){
                		// calculate the distance between current blue location and destination
                		// and the time it took after oranges robot last move time
				time = abs( blueLocation - location ) - orangeTime + 1;

				if (time < 1){ time = 1; }

				seconds += time;  	 // increment how many seconds it takes to complete sequence
				blueTime += time; 	 //  time blue robot has been moving
				blueLocation = location; // blue robots new location
				orangeTime = 0;
			}
			else if (robot == ORANGE_ROBOT){
                		// calculate the distance between current orange location and destination
                		// and the time it took after blues robot last move time
				time = abs( orangeLocation - location ) - blueTime + 1;

				if (time < 1){ time = 1; }

				seconds += time;    	   // increment how many seconds it takes to complete sequence
				orangeTime += time; 	   // time orange robot has been moving
				orangeLocation = location; // orange robots new location
				blueTime = 0;
			}
		}
		outfile << "Case #" << caseIn + 1 << ": " << seconds << endl;
	}
	return 0;
}

