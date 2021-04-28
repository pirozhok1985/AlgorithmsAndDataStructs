#include <stdio.h>
#include <stdlib.h>

void PrintMatrix(char* fileName);

int main(int argc, char** argv)
{
	PrintMatrix("matrix.txt");
	return 0;
}

void PrintMatrix(char* fileName)
{
	FILE* fileStream = fopen(fileName, "rb");
	if(fileStream == NULL)
	{
		printf("Open file error!");
		exit(1);
	}
	fseek(fileStream, 0, SEEK_END);
	long fsize = ftell(fileStream);
	rewind(fileStream);

	char* buffer = (char*)malloc(sizeof(char) * fsize);
	if (buffer == NULL)
	{
		printf("Error buffer creation!");
		exit(1);
	}

	fread(buffer, 1, fsize, fileStream);
	puts(buffer);

	fclose(fileStream);
	free(buffer);
}