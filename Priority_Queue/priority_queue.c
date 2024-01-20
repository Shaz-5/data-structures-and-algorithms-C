#include <stdio.h>
#include <stdlib.h>

int pq[100];
int front = 0;
int rear = 0;
int temp,i,size;

void insert();
void delete_min();
void display();

int main()
{
	printf("\nIMPLEMENTATION OF PRIORITY QUEUE USING ARRAY\n");
	printf("\nEnter size of the priority queue: ");
	scanf("%d",&size);
	printf("\nOperations:\n1.Insert\n2.Delete_Min\n3.Display\n4.Exit\n");
	while(1)
	{
		int choice;
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case(1):
				insert();
				break;
				
			case(2):
				delete_min();
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

void insert()
{
	if(rear >= size )
		printf("\nQueue Overflow!\n");
	else
	{
		if(front == 0)
			front = 1;
		int elem;
		printf("\nEnter element to insert: ");
		scanf("%d",&elem);
		rear++;
		pq[rear] = elem;
		for(i=rear; i>front; i--)
		{
			if(pq[i] < pq[i/2])
				{
					temp = pq[i];
					pq[i] = pq[i/2];
					pq[i/2] = temp;
				}
		}
	}
}

void delete_min()
{
	if(front == 0)
		printf("\nQueue is empty!\n");
	else
	{
		printf("\nThe minimum element %d is deleted\n",pq[front]);
		pq[front] = pq[rear];
		rear--;
		for(i=front; i<=rear/2; i++)
		{
			if(pq[i] > pq[2*i] && pq[2*i]<pq[(2*i)+1])
				{
					temp = pq[i];
					pq[i] = pq[2*i];
					pq[2*i] = temp;
				}
			else if(pq[i] > pq[(2*i)+1])
				{
					temp = pq[i];
					pq[i] = pq[(2*i)+1];
					pq[(2*i)+1] = temp;
				}
		}
		if(rear==0)
			front = 0;
	}
}

void display()
{
	if(front == 0)
		printf("\nQueue is empty!\n");
	else
	{
		printf("\nThe Priority Queue is: \n");
		for (int i = front; i<=rear; i++)
			printf(" %d ",pq[i]);
		printf("\n");
	}
}
