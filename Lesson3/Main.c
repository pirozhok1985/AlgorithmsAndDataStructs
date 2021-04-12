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

int BinarySearch(int* array, int searchValue)
{
	int leftBorder = 0, rightBorder = ARRAY_LENGTH - 1;
	int middle = leftBorder + (rightBorder - leftBorder) / 2;
	while (leftBorder <= rightBorder && array[middle] != searchValue)
	{
		if (array[middle] <= searchValue)
			leftBorder = middle + 1;
		else
			rightBorder = middle - 1;
		middle = leftBorder + (rightBorder - leftBorder) / 2;
	}
	if (array[middle] == searchValue)
		return middle;
	else
		return -1;
}

int main(int argc, char* argv[])
{
	int myArr[ARRAY_LENGTH];
	int myArr1[ARRAY_LENGTH];
	int myArr2[ARRAY_LENGTH];
	int myArr3[ARRAY_LENGTH];
	int compareCount = 0;
	int min;
	int myValue;
	printf("Enter the number you want to be found: ");
	scanf("%d", &myValue);

	printf("Reference array:\n");
	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		myArr[i] = rand() % 101;
		myArr1[i] = myArr[i];
		myArr2[i] = myArr[i];
		myArr3[i] = myArr[i];
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
			}
			compareCount++;
		}
	}

	printf("Bubble sorted array:\n");
	printf("Comparison count equals: %d\n", compareCount);

	//---------Print sorted array-------//
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
			}
			compareCount++;
		}
		if(myArr2[min] < myArr2[i])
			Swap(&myArr2[min], &myArr2[i]);
	}

	printf("\n\n\n");
	printf("Bubble sorted array with increase perfomance:\n");
	printf("Comparison count equals: %d\n", compareCount);


	//---------Print sorted array-------//
	arrayPrint(myArr2);

	//---------Shake sort---------//
	compareCount = 0;
	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		for (int j = 0; j < ARRAY_LENGTH - 1; j++)
		{
			if (myArr3[j] > myArr3[j + 1]) {
				Swap(&myArr3[j], &myArr3[j + 1]);
			}
		}
		for (int j = ARRAY_LENGTH - 1; j > 0; j--)
		{
			if (myArr3[j] < myArr3[j - 1]) {
				Swap(&myArr3[j], &myArr3[j - 1]);
			}
		}
	}

	printf("\n\n\n");
	printf("Shake sorted array:\n");


	//---------Print sorted array-------//
	arrayPrint(myArr3);

	printf("\n\n\n");
	printf("Element %d has index %d", myValue, BinarySearch(myArr3, myValue));

	return 0;
}