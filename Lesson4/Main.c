#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 5
#define M 5

void Print(int arr[N][M])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
}
int main(int argc, char* argv[])
{
	int myArr[N][M];
	int mapArr[N][M] = { {1,1,1,0,1},{1,1,1,1,1},{0,1,1,1,0},{0,1,1,1,1},{1,0,1,1,1} };
	for (int i = 0; i < N; i++)
	{
		myArr[i][0] = (mapArr[i][0] == 0) ? 0 : 1;
		for (int j = 1; j < M; j++)
		{
			myArr[0][j] = (mapArr[0][j] == 0) ? 0 : 1;
			myArr[i][j] = (mapArr[i][j] == 0) ? 0 : myArr[i-1][j] + myArr[i][j-1];
		}
	}
	Print(mapArr);
	printf("\n\n\n");
	Print(myArr);
	return 0;
}