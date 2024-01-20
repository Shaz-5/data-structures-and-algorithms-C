#include <stdio.h>
#include <stdlib.h>

int btree[100];
int nodes;

void create_tree(int nodes);
int get_rightchild(int i);
int get_leftchild(int i);
void preorder(int i);
void postorder(int i);
void inorder(int i);

int main()
{
	printf("\nBINARY TREE USING ARRAY\n");
	printf("\nEnter number of nodes: ");
	scanf("%d",&nodes);
	create_tree(nodes);
	printf("\nPreorder:\n");
    preorder(1);
    printf("\n\nInorder:\n");
    inorder(1);
    printf("\n\nPostorder:\n");
    postorder(1);
    printf("\n\n");
    return 0;
}

void create_tree(int nodes)
{
	printf("\nEnter the elements: \n");
	printf("Enter root: ");
	scanf("%d",&btree[1]);
	for(int i=1; i<=nodes/2; i++)
	{
		printf("\n");
		printf("Enter left child of %d: ",btree[i]);
		scanf("%d",&btree[2*i]);
		printf("Enter right child of %d: ",btree[i]);
		scanf("%d",&btree[(2*i)+1]);
	}
}

int get_rightchild(int i)
{
	if((btree[i]!=0) && (((2*i)+1)<=nodes))
		return (2*i)+1;
	else
		return -1;
}

int get_leftchild(int i)
{
	if((btree[i]!=0) && ((2*i)<=nodes))
		return 2*i;
	else
		return -1;
}

void preorder(int i)
{
	if(i>0 && btree[i]!=0)
	{
		printf(" %d ",btree[i]);
		preorder(get_leftchild(i));
		preorder(get_rightchild(i));
	}
}

void postorder(int i)
{
	if(i>0 && btree[i]!=0)
	{
		postorder(get_leftchild(i));
		postorder(get_rightchild(i));
		printf(" %d ",btree[i]);
	}
}

void inorder(int i)
{
	if(i>0 && btree[i]!=0)
	{
		inorder(get_leftchild(i));
		printf(" %d ",btree[i]);
		inorder(get_rightchild(i));
	}
}
