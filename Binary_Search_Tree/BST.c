#include <stdio.h>
#include <stdlib.h>

int bst[100] = {0};

void insert(int i, int data) {
	if(bst[i] == 0) {
		bst[i] = data;
	}
	else {
		if(data < bst[i]){
			insert(2*i, data);
		}
		else if(data >bst[i]) {
			insert(2*i+1,data);
		}
	}
}

int left(int i) {
	if(bst[i]!=0)
		return 2*i;
	else
		return -1;
}

int right(int i) {
	if(bst[i]!=0)
		return 2*i+1;
	else
		return -1;
}

void preorder(int i) {
	if(i>0 && bst[i]!=0)
	{
		printf(" %d ",bst[i]);
		preorder(left(i));
		preorder(right(i));
	}
}

void postorder(int i) {
	if(i>0 && bst[i]!=0)
	{
		postorder(left(i));
		postorder(right(i));
		printf(" %d ",bst[i]);
	}
}

void inorder(int i) {
	if(i>0 && bst[i]!=0)
	{
		inorder(left(i));
		printf(" %d ",bst[i]);
		inorder(right(i));
	}
}

int min(int i) {
	if(bst[2*i]==0)
		return i;
	while(bst[i]!=0 && bst[2*i]!=0)
		i = 2*i;
	return i;
}

int search(int k, int del) {
	if(bst[k]==del) return k;
	if(del < bst[k])
		search(2*k, del);
	else if(del > bst[k])
		search(2*k+1, del);
}

int i;
int delete(int del) {
	if(bst[1] == 0)
		printf("\nEmpty Tree\n");
	
	if(bst[left(del)]==0 && bst[del]!=0) {
		printf("Deleted %d\n",bst[del]);
		bst[del] = bst[right(del)];
		i = right(del);
		while(bst[i]!=0)
		{	
			bst[i] = bst[right(i)];
			i = right(i);
		}
	}
	else if(bst[right(del)]==0 && bst[del]!=0) {
		printf("Deleted %d\n",bst[del]);
		bst[del] = bst[left(del)];
		i = left(del);
		while(bst[i]!=0)
		{	
			bst[i] = bst[left(i)];
			i = left(i);
		}
	}
	else {
		printf("Deleted %d\n",bst[del]);
		bst[del] = bst[min(right(del))];
		i = min(right(del));
		while(bst[i]!=0)
		{	
			bst[i] = bst[right(i)];
			i = right(i);
		}
	}
}

int main()
{
	printf("\nBINARY SEARCH TREE USING ARRAY\n");
	printf("\nOperations:\n1.Insert\n2.Display\n3.Delete\n4.Exit\n");
	int elem;
	while(1) {
	int choice,del;
	printf("\n\nEnter your choice: ");
	scanf("%d",&choice); 
	switch(choice) {
		case 1:
			printf("Enter element to insert: ");
			scanf("%d",&elem);
			insert(1,elem);
			break;
		case 2:
			printf("\nPre-order: ");
			preorder(1);
			printf("\nIn-order: ");
			inorder(1);
			printf("\nPost-order: ");
			postorder(1);
			break;
		case 3:
			printf("Enter node to delete: ");
			scanf("%d",&del);
			delete(search(1,del));
			break;
		case 4:
			exit(0);
		default:
			printf("\nInvalid Input! Try Again.\n");
		}
	}
	return 0;
}
