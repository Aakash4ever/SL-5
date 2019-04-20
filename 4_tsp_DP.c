/*
	Name :- Aakash Bhaskar Kalore ,
	Branch:- IT , Std. :- TE , Div. :- A ,
	Roll no. :- 35026 ,
	Sub. :-  DAA.
*/

#include<stdio.h>

#define INT_MAX 999999
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int array[10][10],n;
 
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
	}
 
	printf("\n\tThe cost matrix is :");
	for( i=0;i < n;i++)
	{
		printf("\n\t");
		for(j=0;j < n;j++)
			printf("%d\t",array[i][j]);
	}
}

int VISITED_ALL = 16-1, dp[16][4];

int  tsp(int mask,int pos)
{
	if(mask==VISITED_ALL)
		return array[pos][0];
		
	if(dp[mask][pos]!=-1)
	   return dp[mask][pos];

	int ans = INT_MAX;

	for(int city=0;city<n;city++)
	{
		if((mask&(1<<city))==0)
		{
			int newAns = array[pos][city] + tsp( mask|(1<<city), city);
			ans = MIN(ans, newAns);
		}
	}
	return dp[mask][pos] = ans;
} 

int main()
{
	printf("\n\t\t**Travelling Salesman Problem using Dynamic Programming**\n");
	
	input();
	
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<n;j++)
            dp[i][j] = -1;
            
	printf("\n\n\tMinimum cost is %d\n",tsp(1,0));

	return 0;
}

/*
	
				**OUTPUT**
				
	aakash@Aakash:~$ gcc 41.c
aakash@Aakash:~$ ./a.out

		**Travelling Salesman Problem using Dynamic Programming**

	Enter the no. of cities : 4

	Enter the Cost Matrix :

	Enter Elements of Row 1 : 0 20 42 25

	Enter Elements of Row 2 : 20 0 30 34

	Enter Elements of Row 3 : 42 30 0 10

	Enter Elements of Row 4 : 25 34 10 0

	The cost matrix is :
	0	20	42	25	
	20	0	30	34	
	42	30	0	10	
	25	34	10	0
		
	Minimum cost is 85



	aakash@Aakash:~$ ./a.out

		**Travelling Salesman Problem using Dynamic Programming**

	Enter the no. of cities : 4

	Enter the Cost Matrix :

	Enter Elements of Row 1 : 0 10 15 20

	Enter Elements of Row 2 : 10 0 35 25

	Enter Elements of Row 3 : 15 35 0 30

	Enter Elements of Row 4 : 20 25 30 0

	The cost matrix is :
	0	10	15	20	
	10	0	35	25	
	15	35	0	30	
	20	25	30	0	
	
	Minimum cost is 80

*/



