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