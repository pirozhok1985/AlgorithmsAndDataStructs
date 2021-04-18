#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 5
#define M 5

int i, j, m, n, c[20][20];
char x[20], y[20], b[20][20];

void print(int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 'c')
	{
		print(i - 1, j - 1);
		printf("%c", x[i - 1]);
	}
	else if (b[i][j] == 'u')
		print(i - 1, j);
	else
		print(i, j - 1);
}

void printC()
{
	for (int k = 0; k < m; k++)
	{
		for(int l = 0; l < n; l++)
		{
			printf("%d", c[k][l]);
		}
		printf("\n");
	}
}

void lcs()
{
	m = strlen(x);
	n = strlen(y);
	for (i = 0; i <= m; i++)
		c[i][0] = 0;
	for (i = 0; i <= n; i++)
		c[0][i] = 0;

	//c, u и l обозначают поперечное, восходящее и нисходящее направление соответственно(cross upper left)
	//m - длина первой строки¸
	//n - длина второй строки¸
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 'c';
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 'u';
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 'l';
			}
		}
}
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

	printf("Enter 1st sequence:");
	scanf("%s", x);
	printf("Enter 2nd sequence:");
	scanf("%s", y);
	printf("\nThe Longest Common Subsequence is ");
	lcs();
	print(m, n);
	printf("\n\n");
	printC();
	getch();
	return 0;
}