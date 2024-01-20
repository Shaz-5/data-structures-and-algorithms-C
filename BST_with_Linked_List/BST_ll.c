#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left, *right;
};

//create node
struct node *newnode(int elem) {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = elem;
	temp->left = temp->right = NULL;
	return temp;
}

//inorder
void inorder(struct node *root) {
	if(root!=NULL) {
		inorder(root->left);
		printf(" %d ",root->data);
		inorder(root->right);
	}
}

//preorder
void preorder(struct node *root) {
	if(root!=NULL) {
		printf(" %d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

//postorder
void postorder(struct node *root) {
	if(root!=NULL) {
		postorder(root->left);
		postorder(root->right);
		printf(" %d ",root->data);
	}
}

//insert node
struct node *insert(struct node *node, int i) {
	if(node==NULL) return newnode(i);
	if(i< node->data)
		node->left = insert(node->left,i);
	else
		node->right = insert(node->right,i);
	return node;
}

//inorder successor
struct node *min(struct node *node) {
	struct node *tmp = node;
	while(tmp && tmp->left!=NULL)
		tmp = tmp->left;
	return tmp;
}

//delete node
struct node *delete(struct node *root, int i) {
	if(root==NULL) return root;
	if(i < root->data)
		root->left = delete(root->left, i);
	else if(i > root->data)
		root->right = delete(root->right, i);
	else {
		//case1 and 2
		if(root->left == NULL) {
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL) {
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		else{//case3 and 4
		struct node *temp = min(root->right);
		root->data = temp->data;	//replace inorder successor
		delete(root->right, temp->data);	//delete inorder successor
		}
	return root;
	}
}

int main() {
	struct node *root = NULL;
	printf("\nBINARY SEARCH TREE USING ARRAY\n");
	printf("\nOperations:\n1.Insert\n2.Display\n3.Delete\n4.Exit\n");
	int elem;
	while(1) {
	int choice;
	printf("\nEnter your choice: ");
	scanf("%d",&choice); 
	switch(choice) {
		case 1:
			printf("Enter element to insert: ");
			scanf("%d",&elem);
			root = insert(root,elem);
			break;
		case 2:
			printf("\nPre-order: ");
			preorder(root);
			printf("\nIn-order: ");
			inorder(root);
			printf("\nPost-order: ");
			postorder(root);
			printf("\n");
			break;
		case 3:
			int del;
			printf("Enter node to delete: ");
			scanf("%d",&del);
			delete(root,del);
			break;
		case 4:
			exit(0);
		default:
			printf("\nInvalid Input! Try Again.\n");
		}
	}
	return 0;}
