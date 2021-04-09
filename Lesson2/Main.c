#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ConvertDToB(int number);
int main(int argc, char* argv[])
{
	int num;
	printf("Enter the decimal number to convert: ");
	scanf("%d", &num);
	printf("Converted binary number: ");
	ConvertDToB(num);
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