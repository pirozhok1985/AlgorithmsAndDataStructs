#include <stdlib.h>
#include <stdio.h>

typedef struct myObject myObject;

struct myObject
{
	int value;
	myObject* next;
};

myObject* structInit(const int val)
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

int Pop(myObject** stack)
{
	int tmp = (*stack)->value;
	myObject* item = *stack;
	*stack = item->next;
	free(item);
	return  tmp;
}

int main(int argc, char** argv)
{
	int number;
	printf("Enter the number you want to convert to binary: ");
	scanf("%d", &number);
	if (number < 2)
	{
		printf("Nothing to convert!");
		return 0;
	}
	myObject* item = structInit(number%2);
	if (item  == NULL) return 1;
	myObject** myStack = &item;
	number /= 2;

	while(number >= 2)
	{
		myObject* item = structInit(number % 2);
		if (item == NULL) return 1;
		Push(myStack, item);
		number /= 2;
	}
	myObject* itemLast = structInit(number);
	if (item == NULL) return 1;
	Push(myStack, itemLast);
	while ((*myStack) != NULL)
	{
		int result = Pop(myStack);
		printf("%d", result);
	}
	return 0;
}