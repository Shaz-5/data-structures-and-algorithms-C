#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("\nIMPLEMENTATION OF POLYNOMIALS USING ARRAY\n\n");
	int deg;
	float pol[deg+1];
	while(1)
	{
		printf("Enter the degree of the polynomial: ");
		scanf("%d",&deg);
		if(deg<1)
			printf("\nDegree should be greater than 0!\n\n");
		else
		{
			printf("\nEnter the coefficients of the polynomial:\n");
			for(int i = deg; i>=0; i--)
			{
				printf("Enter coefficient of x^%d: ",i);
				scanf("%f",&pol[i]);
			}
			printf("\nThe polynomial is: \n");
			for(int i = deg; i>=0; i--)
			{
				if(pol[i] != 0)
				{
					if(i == deg)
						printf("%.2fx^%d ",pol[i],i);
					else if(i == 1)
						printf(" + %.2fx ",pol[i]);
					else if(i == 0)
						printf(" + %.2f ",pol[i]);
					else
						printf(" + %.2fx^%d ",pol[i],i);
				} 
			}
			printf("\n\n");
			break;
		}
	}
}
