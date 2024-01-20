#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

struct DataItem {
   int data;   
   int key;
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key) {
   return key % SIZE;
}

struct DataItem *search(int key) {
   //get the hash 
   int hashIndex = hashCode(key);  
	
   //move in array until an empty 
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex]; 
			
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }        
	
   return NULL;        
}

void insert(int key,int data) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;  
   item->key = key;

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }
	
   hashArray[hashIndex] = item;
}

struct DataItem* delete(struct DataItem* item) {
   int key = item->key;

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key) {
         struct DataItem* temp = hashArray[hashIndex]; 
			
         //assign a dummy item at deleted position
         hashArray[hashIndex] = dummyItem; 
         return temp;
      }
		
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }      
	
   return NULL;        
}

void display() {
   int i = 0;
	printf("\nThe Hash Table:\n");
   for(i = 0; i<SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf("Key: %d, Value: %d\n",hashArray[i]->key,hashArray[i]->data);
      else
         printf("---\n");
   }
	
   printf("\n");
}

int main() {
   dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
   dummyItem->data = -1;  
   dummyItem->key = -1; 

printf("\nHASH TABLE\n");
	printf("\nHashing Functions:\n1.Insert\n2.Delete\n3.Search \n4.Display\n5.Exit\n");
	while(1)
	{
		int choice,k,v,del,srch;
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case(1):
				printf("\nEnter Key: ");
				scanf("%d",&k);
				printf("Enter Value: ");
				scanf("%d",&v);
				insert(k,v);
				break;
				
			case(2):
				printf("\nEnter key to delete: ");
				scanf("%d",&del);
				item = search(del);
				delete(item);
				break;
				
			case(3):
				printf("\nEnter key to search for: ");
				scanf("%d",&srch);
				item = search(srch);
				if(item != NULL) {
				  printf("Element found: %d\n", item->data);
			   	} 
			   	else {
				  printf("Element not found!\n");
			   	}
				break;
				
			case(4):
				display();
				break;
			
			case(5):
				exit(0);
				
			default:
				printf("\nInvalid input! Try Again.\n");
		}
	}
}
