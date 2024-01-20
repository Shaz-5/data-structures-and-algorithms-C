#include <stdio.h>
#include <stdlib.h>

int vertices;

void bfs(int adj[][vertices], int start);
void dfs(int adj[][vertices],int visited[], int start);

int main()
{
	printf("\nEnter number of vertices: ");
	scanf("%d",&vertices);
	
	int adj[vertices][vertices],visited[vertices];
	printf("\nEnter 0 if vertex is not connected and 1 if vertex is connected:\n");
	for(int i = 0; i<vertices; i++)
		for(int j = 0; j<vertices; j++)
		{
			if(i==j)
			{
				adj[i][j] = 0;
				continue;
			}
			printf("%d --> %d?: ",i,j);
			scanf("%d",&adj[i][j]);
		}
		
	printf("\nThe adjacency matrix:\n");
	for(int i = 0; i<vertices; i++)
	{	
		for(int j = 0; j<vertices; j++)
			printf(" %d ", adj[i][j]);
		printf("\n");
	}
	printf("\nBFS: ");
	bfs(adj,0);
	printf("\n\nDFS: ");
	for(int i =0;i<vertices;i++)
		visited[i] = 0;
	dfs(adj,visited, 0);
	printf("\n");
}

void dfs(int adj[][vertices],int visited[], int start)
{
	printf(" %d ",start);
	visited[start] =1;
	for(int i=0;i<vertices;i++)
	{
		if(visited[i]!=1 && adj[start][i]==1)
		{
			dfs(adj,visited,i);
		}
	}	
}

void bfs(int adj[][vertices], int start)
{
	int visited[vertices],queue[vertices],front=-1,rear=-1;

	for(int i=0;i<vertices;i++)
		visited[i] =0;

	front++;
	queue[++rear] = start;
	visited[start] = 1;

	while(front<=rear)
	{
		start = queue[front++];
		printf(" %d ",start);

		for(int i=0;i<vertices;i++)
		{
			if(adj[start][i]==1 && visited[i] != 1)
			{
				queue[++rear] = i;
				visited[i] =1;
			}
		}


	}

}
