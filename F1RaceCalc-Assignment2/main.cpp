//main.cpp
#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
	const int numDrivers = 5;
	const int numRaces = 6;
	Driver drivers[numDrivers] = {
		//Driver is name of structure type [name,team,points] defined in fun.h
		// [numDrivers] is the size of the array	
		// drivers is the name of the array.
		//Below are the most recent 5 racers scores of the 2024 season
		{"Lewis Hamilton", {1, 12, 3, 8, 2, 10}},
		{"Lando Norris", {16, 18, 18, 25, 13, 16}},
		{"Carlos Sainz", {4, 25, 25, 6, 0, 12}},
		{"George Russell", {15, 10, 12, 12, 15, 6}},
		{"Charles Laclerc", {16, 16, 30, 10, 18, 25}}
	};

	double averagePoints = calculateAveragePoints(drivers, numDrivers, numRaces);
	cout << "Average Points from each race and Racer:" << averagePoints << endl;

	return 0;
}
// This code is to calculate tht total points for Hamilton,
//Calculate the avg points for Lewis Hamilton,
//Using recursion, the remaining drivers points are averaged out,
//Lastly, all averages are combined, then divided by # of drivers for the overall avg. 
