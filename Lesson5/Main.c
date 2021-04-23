#include <stdlib.h>
#include <stdio.h>

typedef struct myObject myObject;
typedef char T;

struct myObject
{
	int value;
	myObject* next;
};

myObject* structInit(const T val)
{
	myObject* item = (myObject*)malloc(sizeof(myObject));
	if(item == NULL)
	{
		printf("Memory allocation error!!");
		return NULL;
	}
	item->value = val;
	item->next = NULL;
	return  item;
}

void Push(myObject** stack, myObject* item)
{
	item->next = *stack;
	*stack = item;
}

T Pop(myObject** stack)
{
	T tmp = (*stack)->value;
	myObject* item = *stack;
	*stack = item->next;
	free(item);
	return  tmp;
}

T Print(myObject** stack)
{
	T value = (*stack)->value;
	return value;
}

void ConvertToBinary(void)
{
	int number;
	printf("Enter the number you want to convert to binary: ");
	scanf("%d", &number);
	if (number < 2)
	{
		printf("Nothing to convert!");
		return;
	}
	myObject* item = structInit(number % 2);
	if (item == NULL) return;
	myObject** myStack = &item;
	number /= 2;

	while (number >= 2)
	{
		myObject* item = structInit(number % 2);
		if (item == NULL) return;
		Push(myStack, item);
		number /= 2;
	}
	myObject* itemLast = structInit(number);
	if (item == NULL) return;
	Push(myStack, itemLast);
	while ((*myStack) != NULL)
	{
		int result = Pop(myStack);
		printf("%d", result);
	}
}

int arrayLength(T* expr)
{
	int count = 0;
	int i = 0;
	while (*(expr + i))
	{
		i++;
		count++;
	}
	*(expr + i) = '\0';
	return count;
}

T* Comparision(myObject** stack, T* expr, T* arr)
{
	int i = 0;
	T value;
	while (1)
	{
		value = *expr;
		if (Print(stack) == '^')
		{
			switch (value)
			{
			case '+':
				Push(stack, structInit(*expr));
				expr++;
				break;
			case  '-':
				Push(stack, structInit(*expr));
				expr++;
				break;
			case  '*':
				Push(stack, structInit(*expr));
				expr++;
				break;
			case  '/':
				Push(stack, structInit(*expr));
				expr++;
				break;
			case  '(':
				Push(stack, structInit(*expr));
				expr++;
				break;
			case  ')':
				printf("Wrong expression!");
				return NULL;
			default:
				expr++;
				*(arr + i) = value;
				i++;
			}
		}
		else if (Print(stack) == '+' || Print(stack) == '-')
		{
			switch (*expr)
			{
			case '\0':
				while((*stack)->value != '^')
				{
					*(arr + i) = Pop(stack);
					i++;
				}		
				return arr;
			case '+':
				*(arr + i) = Pop(stack);
				i++;
				break;
			case  '-':
				*(arr + i) = Pop(stack);
				i++;
				break;
			case  '*':
				Push(stack, structInit(*expr));
				expr++;
				break;
			case  '/':
				Push(stack, structInit(*expr));
				expr++;
				break;
			case  '(':
				Push(stack, structInit(*expr));
				expr++;
				break;
			case  ')':
				*(arr + i) = Pop(stack);
				i++;
				break;
			default:
				expr++;
				*(arr + i) = value;
				i++;
			}
		}
		else if (Print(stack) == '*' || Print(stack) == '/')
		{
			switch (*expr)
			{
			case '\0':
				while ((*stack)->value != '^')
				{
					*(arr + i) = Pop(stack);
					i++;
				}
				return arr;
			case '+':
				*(arr + i) = Pop(stack);
				i++;
				break;
			case  '-':
				*(arr + i) = Pop(stack);
				i++;
				break;
			case  '*':
				*(arr + i) = Pop(stack);
				i++;
				break;
			case  '/':
				*(arr + i) = Pop(stack);
				i++;
				break;
			case  '(':
				Push(stack, structInit(*expr));
				expr++;
				break;
			case  ')':
				*(arr + i) = Pop(stack);
				i++;
				break;
			default:
				expr++;
				*(arr + i) = value;
				i++;
			}
		}
		else if (Print(stack) == '(')
		{
			switch (*expr)
			{
			case '\0':
				printf("Wrong expression!");
				return NULL;
			case '+':
				Push(stack, structInit(*expr));
				expr++;
				break;
			case  '-':
				Push(stack, structInit(*expr));
				expr++;
				break;
			case  '*':
				Push(stack, structInit(*expr));
				expr++;
				break;
			case  '/':
				Push(stack, structInit(*expr));
				expr++;
				break;
			case  '(':
				Push(stack, structInit(*expr));
				expr++;
				break;
			case  ')':
				Pop(stack);
				expr ++;
				break;
			default:
				expr++;
				*(arr + i) = value;
				i++;
			}
		}
	}
}

void PrintArray(T* arr, int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		printf("%c", *(arr + i));
	}
}

void ConvertToOPN(void)
{
	char* expr;
	myObject* exprStart = (structInit('^'));
	myObject** stack = &exprStart;
	printf("Enter an expression to convert: ");
	scanf("%s", &expr);
	const int arrLength = arrayLength(&expr);
	T* arr = (T*)malloc(sizeof(int) * arrLength);
	Comparision(stack, &expr, &arr);
	PrintArray(&arr, arrLength);
	//free(stack);
	free(arr);
}

int main(int argc, char** argv)
{
	int choise;
	printf("Choose program to run:\n");
	printf("1. Convert to binary\n");
	printf("2. Convert to OPN\n");
	scanf("%d", &choise);

	switch (choise)
	{
	case 1:
		ConvertToBinary();
		break;
	case 2:
		ConvertToOPN();
		break;
	}
	return 0;
}