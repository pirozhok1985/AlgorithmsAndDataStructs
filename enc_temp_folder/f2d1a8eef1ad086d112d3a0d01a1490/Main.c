#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void ReadMatrix(char* fileName, int** array, int length);
void PrintMatrix(int** array, int length);
void GraphTraverse(int peak);
int matrix[SIZE][SIZE];
int processedPeaks[SIZE];

int main(int argc, char** argv)
{
	ReadMatrix("matrix.txt", matrix, (SIZE*SIZE));
	PrintMatrix(matrix, (SIZE * SIZE));
	printf("\n\n\n");
	GraphTraverse(0);
	return 0;
}

void ReadMatrix(char* fileName, int** array, int length)
{
	FILE* fileStream = fopen(fileName, "rb");
	if(fileStream == NULL)
	{
		printf("Open file error!");
		exit(1);
	}
	for (int i = 0; i < length; i++)
	{
		fscanf(fileStream, "%d", (array + i));
	}
	fclose(fileStream);
}
void PrintMatrix(int** array, int length)
{
	int** tmp = array;
	for (int i = 0, j = 1; i < length; i++, j++)
	{
		if (j % 5 == 0)
			printf("%d\n", *(tmp + i));
		else
			printf("%d ", *(tmp + i));
	}
}
void GraphTraverse(int peak)
{
	for (int i = peak; i < SIZE; i++)
	{
		printf("%d ", peak);
		processedPeaks[i] = 1;
		for (int j = 0; j < SIZE; j++)
		{
			if (matrix[i][j] == 1 && processedPeaks[j] == 0)
			{
				peak = j;
				GraphTraverse(peak);
			}
		}
		return;
	}
}