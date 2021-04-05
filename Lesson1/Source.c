#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double IMT(double h, double m);

int main(int argc, char* argv[])
{
	double height, weight;
	printf("Enter your height(in meters) and weight using coma as delimeter: ");
	scanf("%lf, %lf", &height, &weight);
	printf("Your IMT = %.0lf", IMT(height, weight));
	return 0;
}

double IMT(double h, double m)
{
	double I;
	return I = m / (h * h);
}