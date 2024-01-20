#include <stdio.h>
#include <stdlib.h>

int q[100];
void enq();
void deq();
void display();

int front = -1;
int rear = -1;
int size;

int main()
{
	printf("\nIMPLEMENTATION OF QUEUE USING ARRAY\n");
	printf("\nEnter size of the Queue: ");
	scanf("%d",&size);
	printf("\nQueue Operations:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
	while(1)
	{
		int choice;
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case(1):
				enq();
				break;
				
			case(2):
				deq();
				break;
				
			case(3):
				display();
				break;
				
			case(4):
				exit(0);
				
			default:
				printf("\nInvalid input! Try Again.\n");
		}
	}
}

void enq()
{
	if(rear > size-1 )
		printf("\nQueue Overflow!\n");
	else
	{
		if(front == -1)
			front = 0;
		int elem;
		printf("\nEnter element to Enqueue: ");
		scanf("%d",&elem);
		rear++;
		q[rear] = elem;
	}
}

void deq()
{
	if(front == -1 ||  front>rear)
		printf("\nQueue is empty!\n");
	else
	{
		printf("\nThe element %d is Dequeued\n",q[front]);
		front++;
		size++;
		if(front > rear)
		{
			front = -1;
			rear = -1;
		}
	}
}

void display()
{
	if(front == -1  || front>rear)
		printf("\nQueue is empty!\n");
	else
	{
		printf("\nThe Queue is: \n");
		for (int i = front; i<=rear; i++)
			printf(" %d ",q[i]);
		printf("\n");
	}
}
