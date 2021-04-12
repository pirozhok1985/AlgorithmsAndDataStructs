#include <stdio.h>
#include <stdlib.h>
#define ARRAY_LENGTH 100
void Swap(int *x, int *y)
{
	*x = *x ^ *y;
	*y = *y ^ *x;
	*x = *x ^ *y;
}

void arrayPrint(int* array)
{
	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		printf("%d ", *(array + i));
	}
}

int main(int argc, char* argv[])
{
	int myArr[ARRAY_LENGTH];
	int myArr1[ARRAY_LENGTH];
	int myArr2[ARRAY_LENGTH];
	int compareCount = 0;
	int min;

	printf("Reference array:\n");
	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		myArr[i] = rand() % 101;
		myArr1[i] = myArr[i];
		myArr2[i] = myArr[i];
		printf("%d ", myArr[i]);
	}
	printf("\n\n\n");

	//---------bubble sort-----------//
	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		for (int j = 0; j < ARRAY_LENGTH - 1; j++)
		{
			if (myArr1[j] > myArr1[j + 1]) {
				Swap(&myArr1[j], &myArr1[j + 1]);
				compareCount++;
			}
		}
	}
	//---------Print sorted array-------//
	printf("Bubble sorted array:\n");
	printf("Comparison count equals: %d\n", compareCount);
	arrayPrint(myArr1);
	
	//---------bubble sort perfomance---------//
	compareCount = 0;
	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		min = i;
		for (int j = i; j < ARRAY_LENGTH; j++)
		{
			if (myArr2[j] < myArr2[min]) {
				min = j;
				compareCount++;
			}
		}
		if(myArr2[min] < myArr2[i])
			Swap(&myArr2[min], &myArr2[i]);
	}

	printf("\n\n\n");
	printf("Bubble sorted array with increase perfomance:\n");
	printf("Comparison count equals: %d\n", compareCount);


	//---------Print sorted array-------//
	arrayPrint(myArr2);


	return 0;
}