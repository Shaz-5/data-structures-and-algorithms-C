#include <stdio.h>
#include <stdlib.h>

int stack[50],top,size;
void push(void);
void pop(void);
void display(void);

int main()
{
	printf("\nIMPLEMENTATION OF STACK USING ARRAY\n");
	top = -1;
	printf("\nEnter size of stack(Max = 50): ");
	scanf("%d",&size);
	printf("\nOperations:\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
	while(1)
	{
		int choice;
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case(1):
				push();	
				break;
			
			case(2):
				pop();
				break;
			
			case(3):
				display();
				break;
			
			case(4):
				exit(0);
				
			default:
				printf("\nInvalid Input! Try Again.\n");
		}
	}
}

void push()
{
	if(top >= size-1)
		printf("\nStack is full!\n");
	else
	{
		int elem;
		printf("\nEnter element to push: ");
		scanf("%d",&elem);
		top++;
		stack[top] = elem;
	}
}

void pop()
{
	if(top <= -1)
		printf("\nStack is empty!\n");
	else
	{
		printf("\nPopped the element %d from the stack\n",stack[top]);
		top--;
	}
}

void display()
{
	if(top >= 0)
	{
		printf("\nThe Stack is: \n\n");
		for(int i=top; i>=0; i--)
			printf("   %d\n",stack[i]);
	}
	else
		printf("\nStack is empty!\n");
}
