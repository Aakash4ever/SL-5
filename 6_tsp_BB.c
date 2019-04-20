/*
	Name :- Aakash Bhaskar Kalore ,
	Branch:- IT , Std. :- TE , Div. :- A ,
	Roll no. :- 35026 ,
	Sub. :-  DAA.
*/

#include<stdio.h>
 
int array[10][10],visited[10],n,cost=0;
 
void input()
{
	int i,j;
 
	printf("\n\tEnter the no. of cities : ");
	scanf("%d",&n);
 
	printf("\n\tEnter the Cost Matrix :\n");
	for(i=0;i < n;i++)
	{
		printf("\n\tEnter Elements of Row %d : ",i+1);
		for( j=0;j < n;j++)
			scanf("%d",&array[i][j]);
 
		visited[i]=0;
	}
 
	printf("\n\tThe cost matrix is :");
	for( i=0;i < n;i++)
	{
		printf("\n\t");
		for(j=0;j < n;j++)
			printf("%d\t",array[i][j]);
	}
}

int least(int c)
{
	int i,nc=999;
	int min=999,kmin;
 
	for(i=0;i < n;i++)
	{
		if((array[c][i]!=0)&&(visited[i]==0))
			if((array[c][i]) < min)
			{
				min=array[i][0]+array[c][i];
				kmin=array[c][i];
				nc=i;
			}
	}
	if(min!=999)
		cost+=kmin;
 
	return nc;
}
 
void mincost(int city)
{
	int i,ncity;
 
	visited[city]=1;
 
	printf("%d-->",city+1);
	ncity=least(city);
 
	if(ncity==999)
	{
		ncity=0;
		printf("%d",ncity+1);
		cost+=array[city][ncity];
		return;
	}
	mincost(ncity);
}
 
int main()
{
	printf("\n\t\t**Travelling Salesman Problem using Branch and Bound Method**\n");

	input();
 
	printf("\n\tThe Path is : \n");
	mincost(0); //passing 0 because starting vertex
 
	printf("\n\tMinimum cost is %d. \n",cost);
 
	return 0;
}

/*
				**OUTPUT**

aakash@Aakash:~$ gcc 6.c
aakash@Aakash:~$ ./a.out

		**Travelling Salesman Problem using Branch and Bound Method**

	Enter the no. of cities : 4

	Enter the Cost Matrix :

	Enter Elements of Row 1 : 0 10 15 20

	Enter Elements of Row 2 : 5 0 9 10

	Enter Elements of Row 3 : 6 13 0 12

	Enter Elements of Row 4 : 8 8 9 0

	The cost matrix is :
	0	10	15	20	
	5	0	9	10	
	6	13	0	12	
	8	8	9	0	
	The Path is : 
1-->2-->4-->3-->1
	Minimum cost is 35. 
*/
