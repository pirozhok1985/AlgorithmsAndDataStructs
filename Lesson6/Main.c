#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void myHashFunc(char* str);
void ConvertToHex(long long int number);
char Converter(int value);

int main(int argc, char** argv)
{
	printf("Enter the password: ");
	char string[256];
	scanf("%s", &string);
	myHashFunc(string);
	return 0;
}

void myHashFunc(const char* str)
{
	const long long int salt = 159753951357258;
	long long int result = 0;
	int count = 0;

	while(*(str+count))
	{
		char tmp = *(str + count);
		result += tmp;
		count++;
	}
	result += salt;
	ConvertToHex(result);
}

void ConvertToHex(long long int number)
{
	long long int result = 0;
	
	while(number>=16)
	{
		ConvertToHex(number / 16);
		result = number % 16;
		printf("%c",Converter(result));
		return;
	}
	printf("%c", Converter(number));
}

char Converter(int value)
{
	switch (value)
	{
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 10:
		return 'A';
	case 11:
		return 'B';
	case 12:
		return 'C';
	case 13:
		return 'D';
	case 14:
		return 'E';
	case 15:
		return 'F';
	default:
		return '0';
	}
}