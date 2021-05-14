#include <stdio.h>
#include <stdlib.h>

void quickSort(int* numbers, int left, int right);
void PrintArray(int* arr, int size);

int main(int argc, char** argv)
{
	int myArr[20];
	for (int i = 0; i < 20; i++)
	{
		myArr[i] = rand() % 20;
	}
	PrintArray(myArr, 20);
	printf("\n");
	quickSort(myArr, 0,19);
	PrintArray(myArr, 20);
	return 0;
}

void quickSort(int* numbers, int left, int right)
{
	int i = left;
	int j = right;
	int pivot = numbers[i+(j-i)/2];

	while (i <= j)
	{
		while (numbers[i] < pivot)
		{
			i++;
		}
		while (numbers[j] > pivot)
		{
			j--;
		}
		if(i <= j)
		{
			int tmp = numbers[i];
			numbers[i++] = numbers[j];
			numbers[j--] = tmp;
		}
	}
	if (j > left)
		quickSort(numbers, left, j);
	if (i < right)
		quickSort(numbers, i, right);
}
void PrintArray(int* arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}