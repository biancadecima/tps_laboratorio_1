#include <stdio.h>
#include <stdlib.h>
#include "calculations.h"

float calculateAverage(float amount, int total){
	float average;

	average = (float) amount / total;

	return average;
}

float calculatePercentage(int amount, int total){
	float percentage;
	percentage = (float) (amount * 100) / total;

	return percentage;
}
