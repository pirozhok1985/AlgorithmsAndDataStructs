#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double IMT(double h, double m);

int main(int argc, char* argv[])
{
	//-------------------IMT-------------------------
	double height, weight;
	printf("Enter your height(in meters) and weight using coma as delimeter: ");
	scanf("%lf, %lf", &height, &weight);
	printf("Your IMT = %.0lf", IMT(height, weight));
	//---------------------------------------------
	//---------------------Max value---------------
	int a, b, c, d;
	int max, max1, max2;
	printf("\nEnter four numbers using coma as delimeter: ");
	scanf("%d, %d, %d, %d", &a, &b, &c, &d);
	max1 = (a > b) ? a : b;
	max2 = (c > d) ? c : d;
	max = (max1 > max2) ? max1 : max2;
	printf("Max number is %d", max);
	//---------------------------------------------

	return 0;
}

double IMT(double h, double m)
{
	double I;
	return I = m / (h * h);
}