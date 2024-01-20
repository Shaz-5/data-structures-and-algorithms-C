#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};
struct node *head = NULL, *newnode, *temp;

void insert_f();
void insert_l();
void insert_p();
void delete_f();
void delete_l();
void delete_p();
void display();
void max();
void mean();
void sort();
void rev();

int main()
{
	printf("\nIMPLEMENTATION OF VARIOUS LINKED LIST OPERATIONS\n");
	printf("\nOperations:\n1.Insert at start\n2.Insert at end\n3.Insert at position\n4.Delete at start\n5.Delete at end\n6.Delete at position\n7.Display\n8.Max\n9.Mean\n10.Sort\n11.Reverse\n12.Exit\n");
	while(1)
	{
		int choice;
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case(1):
				insert_f();
				break;
			
			case(2):
				insert_l();
				break;
			
			case(3):
				insert_p();
				break;
			
			case(4):
				delete_f();
				break;
			
			case(5):
				delete_l();	
				break;
				
			case(6):
				delete_p();
				break;	
			
			case(7):
				display();
				break;
			
			case(8):
				max();
				break;
				
			case(9):
				mean();
				break;
				
			case(10):
				sort();
				break;
				
			case(11):
				rev();
				break;
				
			case(12):
				exit(0);
				
			default:
				printf("\nInvalid Input! Try agian.\n");
				break;
		}
	}
}

void insert_f()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the element to insert: ");
	scanf("%d",&newnode->data);
	newnode->next = head;
	head = newnode;
	display();
}

void insert_l()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter element to insert: ");
	scanf("%d",&newnode->data);
	newnode->next = NULL;
	temp = head;
	while(temp->next!=NULL)
		temp = temp->next;
	temp->next=newnode;
	display();
}

void insert_p()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter element to insert: ");
	scanf("%d",&newnode->data);
	temp = head;
	int pos;
	printf("Enter the position to insert element: ");
	scanf("%d",&pos);
	for(int i = 2; i<pos; i++)
		if(temp->next!=NULL)
			temp=temp->next;
	newnode->next = temp->next;
	temp->next=newnode;
	display();
}

void delete_f()
{
	head = head->next;
	display();
}

void delete_l()
{
	temp = head;
	while(temp->next->next!=NULL)
		temp=temp->next;
	temp->next=NULL;
	display();
}

void delete_p()
{
	int pos;
	printf("Enter position to delete: ");
	scanf("%d",&pos);
	temp = head;
	for(int i=2; i<pos; i++)
		if(temp->next!=NULL)
			temp = temp->next;
	temp->next = temp->next->next;
	display();
}

void display()
{
	temp = head;
	printf("\nThe linked list is: \n");
	while(temp!=NULL)
	{
		printf(" %d --> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");	
}

void max() {
	temp = head;
	int max = temp->data;
	while(temp->next!=NULL)
	{
		temp = temp->next;
		if(max< temp->data)
			max = temp->data;
	}
	printf("\nMaximum number is: %d\n",max);
}

void mean() {
	temp = head;
	float sum  = temp->data,count=0,mean=0;
	while(temp->next!=NULL)
	{
		temp = temp->next;
		count++;
		sum = sum + temp->data;
	}
	mean = sum/count;
	printf("\nMean is: %f\n",mean);
}

void sort() {
	struct node *index = NULL;
	temp = head;
	int tmp;
	while(temp!=NULL)
	{	index = temp->next;
		while(index!=NULL)
		{	if(temp->data > index->data)
				{
					tmp = temp->data;
					temp->data = index->data;
					index->data = tmp;
				}
			index = index->next;
		}
	temp = temp->next;
	}	
	display();
}

void rev() {
	struct node *prev = NULL;
	struct node *next = NULL;
	temp = head;
	while(temp!=NULL)
	{
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;	
	}head = prev;
	display();
}
