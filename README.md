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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//fun.cpp
#include "functions.h"

int calculateTotalPoints(int* points, int numRaces)
{
	if (numRaces == 0) {//numRaces = 0, means there are no more races.The == checks is numRaces is equal to 0.
		return 0;
	}
	return points[0] + calculateTotalPoints(points + 1, numRaces - 1);
	//points[0] is the first element. 
	//points + 1 makes the program continue with the process of looking at the other points made. 
	//numRaces - 1 makes up the decrese in amount of races left to analyze. 
	//calculateTotalPoints is recalled with an updated pointer, this is recursion.
}
double calculateAveragePoints(Driver* drivers, int numDrivers, int numRaces)
{

	if (numDrivers == 0) {
		return 0;
	}
	int totalPoints = calculateTotalPoints(drivers->points, numRaces);//drivers is the pointer to the first element of [Driver], (->) is the operator, using the pointer to access numbers.
	return (totalPoints / (double)numRaces + calculateAveragePoints(drivers + 1, numDrivers - 1, numRaces)) / numDrivers;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
//fun.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
using namespace std;

struct Driver {//"struct" is the structure data type. Allows for grouping var. of different types.
	string name;
	int points[6];//points for the 6 races
};

int calculateTotalPoints(int* points, int numRaces);
double calculateAveragePoints(Driver* drivers, int numDrivers, int numRaces);

#endif //FUNCTIONS_H
