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