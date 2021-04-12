#include <stdio.h>
#include <stdlib.h>
#define ARRAY_LENGTH 100
void Swap(int *x, int *y)
{
	*x = *x ^ *y;
	*y = *y ^ *x;
	*x = *x ^ *y;
}

int main(int argc, char* argv[])
{
	int myArr[ARRAY_LENGTH];
	int compareCount = 0;
	int min;
	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		myArr[i] = rand() % 101;
		printf("%d ", myArr[i]);
	}
	printf("\n\n\n");

	//---------bubble sort-----------//
	//for (int i = 0; i < ARRAY_LENGTH; i++)
	//{
	//	for (int j = 0; j < ARRAY_LENGTH - 1; j++)
	//	{
	//		if (myArr[j] > myArr[j + 1]) {
	//			Swap(&myArr[j], &myArr[j + 1]);
	//			compareCount++;
	//		}
	//	}
	//}
	

	//---------bubble sort perfomance---------//
	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		min = i;
		for (int j = i; j < ARRAY_LENGTH; j++)
		{
			if (myArr[j] < myArr[min]) {
				min = j;
				compareCount++;
			}
		}
		if(myArr[min] < myArr[i])
			Swap(&myArr[min], &myArr[i]);
	}
	printf("Compare count equals: %d\n", compareCount);


	//---------Print sorted array-------//
	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		printf("%d ", myArr[i]);
	}
	return 0;
}