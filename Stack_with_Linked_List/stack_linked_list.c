#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
}; 

int main()
{
	printf("\nIMPLEMENTATION OF STACK USING LINKED LIST\n");
	struct node *top = NULL;
	printf("\nOperations:\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
	while(1)
	{
		int choice;
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case(1):
				int elem;
					printf("\nEnter element to push: ");
					scanf("%d",&elem);
				struct node *new_node;
				new_node = (struct node*)malloc(sizeof(struct node));
				new_node -> data = elem;
				if(top == NULL)
					new_node -> next = NULL;
				else
					new_node -> next = top;
				top = new_node;
				break;
			
			case(2):
				if(top == NULL)
					printf("\nEmpty Stack!\n");
				else
				{
					struct node *temp = top;
					printf("\nPopped element %d from the stack\n",temp->data);
					top = temp -> next;
					free(temp);
				} break;
				
			case(3):
				if(top == NULL)
					printf("\nEmpty Stack!\n");
				else
				{
					printf("\nThe stack is:\n\n");
					struct node *temp = top;
					while(temp!=NULL)
					{
						printf(" %d \n",temp->data);
						temp = temp -> next;
					}
				} break;
			
			case(4):
				exit(0);
				
			default:
				printf("\nInvalid Input! Try agian.\n");
				break;
		}
	}
}
