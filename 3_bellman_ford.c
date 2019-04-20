/*
	Name :- Aakash Bhaskar Kalore ,
	Branch:- IT , Std. :- TE , Div. :- A ,
	Roll no. :- 35026 ,
	Sub. :-  DAA.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
struct Edge
{
    int source, destination, weight;
};
 
struct Graph
{
    int V, E;
    struct Edge* edge;
};
 
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph));
 
    graph->V = V;   
    graph->E = E;
     
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}
 
void FinalSolution(int dist[], int n)
{
    printf("\n\tVertex\t\tMin. Distance from Source Vertex");
    
    int i;
    for (i = 0; i < n; ++i)
		printf("\n\t%d \t\t %d", i, dist[i]);
	printf("\n\n");
}
 
void BellmanFord(struct Graph* graph, int source)
{
    int V = graph->V; 
    int E = graph->E;
    int StoreDistance[V];
    int i,j;
 
    for (i = 0; i < V; i++)
        StoreDistance[i] = INT_MAX;
 
    StoreDistance[source] = 0;
 
    for (i = 1; i <= V-1; i++)
    {
        for (j = 0; j < E; j++)
        {
            int u = graph->edge[j].source; 
            int v = graph->edge[j].destination; 
            int weight = graph->edge[j].weight; 
            if (StoreDistance[u] + weight < StoreDistance[v])
                StoreDistance[v] = StoreDistance[u] + weight;
        }
    }
    
  	for (i = 0; i < E; i++)
    {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination; 
        int weight = graph->edge[i].weight;
        if (StoreDistance[u] + weight < StoreDistance[v])
        {
            printf("\n\tERROR: Entered graph contains NEGATIVE EDGE CYCLE\n");
        	return;
        }
    }
 
    FinalSolution(StoreDistance, V);
 
    return;
}
 
int main()
{
    int V,E,S,i;
    
    printf("\n\t\t**Bellman-Ford algorithm**\n");  
 
	printf("\n\tEnter the no. of Vertices in the graph: ");
    scanf("%d",&V);
 
	printf("\n\tEnter the no. of Edges in the graph: ");
    scanf("%d",&E);
 
	printf("\n\tEnter the source vertex: ");
	scanf("%d",&S);
 
    struct Graph* graph = createGraph(V, E);    
 
    for(i=0;i<E;i++)
    {
		printf("\n\tEnter the Source, Destination and weight of edge %d: ",i+1);
        scanf("%d%d%d",&graph->edge[i].source,&graph->edge[i].destination,&graph->edge[i].weight);
    }
 
    BellmanFord(graph, S);

    return 0;
}

/*

				**OUTPUT**

aakash@Aakash:~$ gcc 3.c
aakash@Aakash:~$ ./a.out

		**Bellman-Ford algorithm**

	Enter the no. of Vertices in the graph: 5

	Enter the no. of Edges in the graph: 6

	Enter the source vertex: 0

	Enter the Source, Destination and weight of edge 1: 0 1 6

	Enter the Source, Destination and weight of edge 2: 1 4 1

	Enter the Source, Destination and weight of edge 3: 1 3 5

	Enter the Source, Destination and weight of edge 4: 0 3 4

	Enter the Source, Destination and weight of edge 5: 2 1 -4

	Enter the Source, Destination and weight of edge 6: 4 2 2

	ERROR: Entered graph contains NEGATIVE EDGE CYCLE



aakash@Aakash:~$ ./a.out

		**Bellman-Ford algorithm**

	Enter the no. of Vertices in the graph: 5

	Enter the no. of Edges in the graph: 7

	Enter the source vertex: 0

	Enter the Source, Destination and weight of edge 1: 0 1 17

	Enter the Source, Destination and weight of edge 2: 1 2 25

	Enter the Source, Destination and weight of edge 3: 2 3 1

	Enter the Source, Destination and weight of edge 4: 3 1 -24

	Enter the Source, Destination and weight of edge 5: 1 4 15

	Enter the Source, Destination and weight of edge 6: 0 3 40

	Enter the Source, Destination and weight of edge 7: 4 2 9

	Vertex		Min. Distance from Source Vertex
	0 		 	0
	1 		 	16
	2 			40
	3 		 	40
	4 		 	31
	
	
	
	aakash@Aakash:~$ ./a.out

		**Bellman-Ford algorithm**

	Enter the no. of Vertices in the graph: 5

	Enter the no. of Edges in the graph: 6

	Enter the source vertex: 0

	Enter the Source, Destination and weight of edge 1: 0 1 1

	Enter the Source, Destination and weight of edge 2: 1 2 2

	Enter the Source, Destination and weight of edge 3: 2 3 3

	Enter the Source, Destination and weight of edge 4: 3 4 4

	Enter the Source, Destination and weight of edge 5: 4 5 5

	Enter the Source, Destination and weight of edge 6: 5 6 6

	Vertex		Min. Distance from Source Vertex
	0 		 0
	1 		 1
	2 		 3
	3 		 6
	4 		 10

*/
