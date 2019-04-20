/*
	Name :- Aakash Bhaskar Kalore ,
	Branch:- IT , Std. :- TE , Div. :- A ,
	Roll no. :- 35026 ,
	Sub. :-  DAA.
*/

#include <stdio.h>

int Queen, board[100][100];

int is_attacking(int i,int j)
{
    int k,l;

    for(k=0;k<Queen;k++)
    {
        if( (board[i][k] == 1) || (board[k][j] == 1) )
            return 1;
    }

    for(k=0;k<Queen;k++)
    {
        for(l=0;l<Queen;l++)
        {
            if( ((k+l) == (i+j)) || ((k-l) == (i-j)) )
            {
                if(board[k][l] == 1)
                    return 1;
            }
        }
    }
    return 0;
}

int solution(int n)
{
    int i,j;

    if(n==0)
        return 1;

    for(i=0;i<Queen;i++)
    {
        for(j=0;j<Queen;j++)
        {
            if((!is_attacking(i,j)) && (board[i][j]!=1))
            {
                board[i][j] = 1;
                if(solution(n-1)==1)
                    return 1;
                board[i][j] = 0;
            }
        }
    }
    return 0;
}

int main()
{	
	printf("\n\t\t**N Queens problem using Backtracking**\n");
	
	printf("\n\tEnter the no. of Queens : ");
	scanf("%d",&Queen);
	
	int i,j;
	
	for(i=0;i<Queen;i++)
	{
		for(j=0;j<Queen;j++)
			board[i][j]=0;
	}
	
	solution(Queen);
	
	printf("\n\tThe solution of %d Queens problem is : \n",Queen);
	for(i=0;i<Queen;i++)
	{	
		printf("\n\t");
		for(j=0;j<Queen;j++)
			printf("%d\t",board[i][j]);
	}
	printf("\n");
}

/*
				**OUTPUT**

aakash@Aakash:~$ gcc 5.c
aakash@Aakash:~$ ./a.out

		**N Queens problem using Backtracking**

	Enter the no. of Queens : 4

	The solution of 4 Queens problem is : 

	0	1	0	0	
	0	0	0	1	
	1	0	0	0	
	0	0	1	0	
aakash@Aakash:~$ ./a.out

		**N Queens problem using Backtracking**

	Enter the no. of Queens : 7

	The solution of 7 Queens problem is : 

	1	0	0	0	0	0	0	
	0	0	1	0	0	0	0	
	0	0	0	0	1	0	0	
	0	0	0	0	0	0	1	
	0	1	0	0	0	0	0	
	0	0	0	1	0	0	0	
	0	0	0	0	0	1	0	

*/


