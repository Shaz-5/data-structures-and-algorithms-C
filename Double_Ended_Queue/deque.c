#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("\nIMPLEMENTATION OF DEQUE USING ARRAY\n");
	int size;
	printf("\nEnter size of the Queue: ");
	scanf("%d",&size);
	int dq[size];
	int front = -1, rear = -1;
	printf("\nDeque Operations:\n1.Insert at left\n2.Insert at right\n3.Delete from left\n4.Delete from right\n5.Display\n6.Exit\n");
	while(1)
	{
		int choice;
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case(1):
			{
				if((front == rear+1) || (front == 0 && rear==size-1))
					printf("\nQueue Overflow!\n");
				else
				{
					int elem;
					printf("\nEnter element to Insert left: ");
					scanf("%d",&elem);
					if(front == -1)
						{
							front = rear = 0;
							dq[rear] = elem;
						}
					else if(front == 0)
						{
							front = size-1;
							dq[front] = elem;
						}
					else
					{
						front--;
						dq[front] = elem;
					}
				}
			}break;
			
			case(2):
			{
				if((front == rear+1) || (front == 0 && rear==size-1))
					printf("\nQueue Overflow!\n");
				else
				{
					int elem;
					printf("\nEnter element to Insert Right: ");
					scanf("%d",&elem);
					if(front == -1)
						{
							front = rear = 0;
							dq[rear] = elem;
						}
					else if(rear == size-1)
						{
							rear = 0;
							dq[rear] = elem;
						}
					else
					{
						rear++;
						dq[rear] = elem;
					}
				}
			}break;
				
			case(3):
			{
				if(front == -1)
					printf("\nQueue is empty!\n");
				else if(front == rear)
					{
						printf("\nThe element %d is deleted\n",dq[front]);
						front = -1;
						rear = -1;
					}
				else
				{
					printf("\nThe element %d is deleted\n",dq[front]);
					if(front == size-1)
						front = 0;
					else
						front++;
				}
			}break;
			
			case(4):
			{
				if(front == -1)
					printf("\nQueue is empty!\n");
				else if(front == rear)
					{
						printf("\nThe element %d is deleted\n",dq[front]);
						front = -1;
						rear = -1;
					}
				else
				{
					printf("\nThe element %d is deleted\n",dq[rear]);
					if(rear == 0)
						rear = size-1;
					else
						rear--;
				}
			}break;
				
			case(5):
			{
				if(front == -1)
					printf("\nQueue is empty!\n");
				else
				{
					printf("\nThe Deque is: \n");
					if(rear >= front)
						for(int i=front; i<=rear; i++)
							printf(" %d ",dq[i]);
					else
					{
						for(int i = front; i<size; i++)
							printf(" %d ",dq[i]);
						for(int i= 0; i<=rear; i++)
							printf(" %d ",dq[i]);
					}
					printf("\n");
				}
			}break;
				
			case(6):
				exit(0);
				
			default:
				printf("\nInvalid input! Try Again.\n");
		}
	}
}
