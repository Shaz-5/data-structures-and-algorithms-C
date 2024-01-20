#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("\nIMPLEMENTATION OF SPARSE MATRIX USING ARRAY\n");
	int rows,cols;
	printf("\nEnter the order of the Matrix:\n");
	printf("Enter number of rows: ");
	scanf("%d",&rows);
	printf("Enter number of columns: ");
	scanf("%d",&cols);
	int sp_matrix[rows][cols];
	printf("\nEnter the elements of the Matrix:\n");
	
	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
		{
			printf("Enter element [%d][%d]: ",i,j);
			scanf("%d",&sp_matrix[i][j]);
		}
	
	int total = 0;
	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			if(sp_matrix[i][j]!=0)
				total++;
	
	int sp_rep[3][total];
	int k = 0;
	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			if(sp_matrix[i][j]!=0)
			{
				sp_rep[0][k] = i;
				sp_rep[1][k] = j;
				sp_rep[2][k] = sp_matrix[i][j];
				k++;
			}
	
	printf("\nThe Matrix: \n");
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
			printf(" %d\t",sp_matrix[i][j]);
		printf("\n");
	}
	
	printf("\nSparse Matrix Representation(Row,Column,Value):\n");
	for(int i =0; i<3; i++)
	{
		for(int j =0; j<total; j++)
			printf("  %d  ",sp_rep[i][j]);
		printf("\n");
	}
}
