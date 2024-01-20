#include <stdio.h>
#include <stdlib.h>

int disjset[10];
int Find(int x);
void Union(int x, int y);

int main()
{
	for(int i = 10; i>0; i--)
		disjset[i] = 0;
	printf("\nDISJOINT SET OPERATIONS\n");
	printf("\nOperations:\n1.Union(x,y)\n2.Find\n3.Exit");
	int choice,n1,n2,n3;
	while(1)
	{	
		printf("\n\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter x: ");
				scanf("%d",&n1);
				printf("Enter y: ");
				scanf("%d",&n2);
				Union(n1,n2);
				break;
			case 2:
				printf("Enter number: ");
				scanf("%d",&n3);
				printf("Root = %d",Find(n3));
				break;
			case 3:
				exit(0);
			default:
				printf("\nInvalid Input! Try Again.\n");
				break;
		}
	}
}

int Find(int x)
{
	if(disjset[x] == 0)
		return x;
	else
		return Find(disjset[x]);
}

void Union(int x, int y)
{
	int r1 = Find(x);
	int r2 = Find(y);
	if(r1!=r2)
		disjset[y] = x;
}
