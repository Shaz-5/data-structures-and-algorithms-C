#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int main()
{
	printf("\nIMPLEMENTATION OF STACK USING LINKED LIST\n");
	struct node *front = NULL;
	struct node *rear = NULL;
	printf("\nOperations:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
	while(1)
	{
		int choice;
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case(1):
				struct node *val;
				val = (struct node*)malloc(sizeof(struct node));
				int elem;
				printf("\nEnter element to Enqueue: ");
				scanf("%d",&elem);
				val -> data = elem;
				val -> next = NULL;
				if(front == NULL && rear == NULL)
					front = rear = val;
				else
				{
					rear -> next  = val;
					rear = val;
				}break;

			case(2):
				if(front == NULL)
					printf("\nEmpty queue!\n");
				else
				{
					printf("\nDequeued element %d from the queue\n",front -> data);
					front = front->next;
					if(front == NULL)
						rear = NULL;
				}break;

			case(3):
				if(front == NULL && rear == NULL)
					printf("\nEmpty queue!\n");	
				else
				{
					struct node *temp = front;
					printf("\nThe queue is:\n" );
					while(temp!=NULL)
						{
							printf(" %d --> ",temp->data);
							temp = temp->next;
						}
					printf(" NULL\n");
				}break;
				
			case(4):
				exit(0);
			
			default:
				printf("\nInvalid Entry. Try again!\n");
				break;
		}
	}
}
