#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ConvertDToB(int number);
int myPow(int number, int degree);
int myPowRecursion(int number, int degree);
int myPowFastRecursion(int number, int degree);
int main(int argc, char* argv[])
{
	int num;
	printf("Enter the decimal number to convert: ");
	scanf("%d", &num);
	printf("Converted binary number: ");
	ConvertDToB(num);
	int myNumber, pow;
	printf("\nEnter the number and power using coma as delim: ");
	scanf("%d, %d", &myNumber, &pow);
	printf("Result using myPow: %d\nResult using myPowRecursion: %d\nResult using myPowFastRecursion: %d", myPow(myNumber, pow), myPowRecursion(myNumber, pow), myPowFastRecursion(myNumber, pow));
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
	return degree == 1 ? number : number * myPowRecursion(number, degree - 1);
}
int myPowFastRecursion(int number, int degree)
{
	if (degree == 0)
	{
		return 1;
	}
	else
	{
		if (degree % 2 == 0)
		{
			return number * number * myPowFastRecursion(number, degree - 2);
		}
		return number * myPowFastRecursion(number, degree - 1);
	}
}