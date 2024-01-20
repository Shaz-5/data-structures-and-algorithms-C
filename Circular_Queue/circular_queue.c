#include <stdio.h>
#include <stdlib.h>

int cq[100];
int size;
int front = -1;
int rear = -1;

void enq();
void deq();
void display();

int main()
{
	printf("\nIMPLEMENTATION OF CIRCULAR QUEUE USING ARRAY\n");
	printf("\nEnter size of the Queue: ");
	scanf("%d",&size);
	printf("\nCircular Queue Operations:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
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
	if((front == rear+1) || (front == 0 && rear==size-1))
		printf("\nQueue Overflow!\n");
	else
	{
		int elem;
		printf("\nEnter element to Enqueue: ");
		scanf("%d",&elem);
		if(front == -1)
			{
				front = rear = 0;
				cq[rear] = elem;
			}
		else if(rear == size-1 && front!=0)
			{
				rear = 0;
				cq[rear] = elem;
			}
		else
		{
			rear++;
			cq[rear] = elem;
		}
	}
}

void deq()
{
	if(front == -1)
		printf("\nQueue is empty!\n");
	else if(front == rear)
		{
			printf("\nThe element %d is Dequeued\n",cq[front]);
			front = -1;
			rear = -1;
		}
	else
	{
		printf("\nThe element %d is Dequeued\n",cq[front]);
		if(front == size-1)
			front = 0;
		else
			front++;
	}
}

void display()
{
	if(front == -1)
		printf("\nQueue is empty!\n");
	else
	{
		printf("\nThe Circular Queue is: \n");
		if(rear >= front)
			for(int i=front; i<=rear; i++)
				printf(" %d ",cq[i]);
		else
		{
			for(int i = front; i<size; i++)
				printf(" %d ",cq[i]);
			for(int i= 0; i<=rear; i++)
				printf(" %d ",cq[i]);
		}
		printf("\n");
	}
}
