#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ConvertDToB(int number);
int myPow(int number, int degree);
int myPowRecursion(int number, int degree);
int main(int argc, char* argv[])
{
	//int num;
	//printf("Enter the decimal number to convert: ");
	//scanf("%d", &num);
	//printf("Converted binary number: ");
	//ConvertDToB(num);

	printf("%d", myPowRecursion(2, 10));
	return 0;
}
void ConvertDToB(int number)
{
	if (number >= 2)
	{
		ConvertDToB(number / 2);
	}
	printf("%d", number%2);
}
int myPow(int number, int degree)
{
	int result = number;
	for (int i = 0; i < degree - 1; i++)
	{
		result *= number;
	}
	return result;
}
int myPowRecursion(int number, int degree)
{ 
	--degree;
	int result = 1;
	if (degree > 0)
		result = myPowRecursion(number, degree);
	return result *= number;
}