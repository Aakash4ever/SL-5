/*
	Name :- Aakash Bhaskar Kalore ,
	Branch:- IT , Std. :- TE , Div. :- A ,
	Roll no. :- 35026 ,
	Sub. :-  DAA.
*/

#include<stdio.h>

#define MAX 10

int quick_sort_r(int array[],int first,int last,int n)
{
    int pivot,i,j,k,temp;
    
    if(first<last)
    {
        i=pivot=first;
        j=last;
        while(i<j)
        {
            while(array[i]<=array[pivot]&&i<last)
                i++;
                while(array[j]>array[pivot])
                    j--;
                    if(i<j)
                    {
                        temp=array[i];
                        array[i]=array[j];
                        array[j]=temp;
                    }
        }
        temp=array[pivot];
        array[pivot]=array[j];
        array[j]=temp;
        
        quick_sort_r(array,first,j-1,n);
        quick_sort_r(array,j+1,last,n);
    }
    return 0;
}

int main()
{
	int array[MAX],n,i,j;
	
	printf("\n\t\t**Optimal storage on tapes using Greedy method**\n");
	
	printf("\n\tEnter the no. of files : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n\tEnter the size of file %d : ",i+1);
		scanf("%d",&array[i]);
	}
	printf("\n\n\tEntered files sizes are : ");
	for(i=0;i<n;i++)
		printf("%d ",array[i]);
			
	quick_sort_r(array,0,n-1,n);
	
	printf("\n\n\tOrder of files sizes must be : ");
	for(i=0;i<n;i++)
		printf("%d ",array[i]);
		
	float MRT=0; 
    for (i=0;i<n;i++) 
    { 
    	int sum=0; 
        for(j=0;j<=i;j++) 
            sum+=array[j]; 
        MRT+=sum; 
    } 
    MRT/=n; 
    printf("\n\n\tMinimum Mean Retrieval Time of this order is: %0.3f\n",MRT); 
}

/*
				**OUTPUT**

aakash@Aakash:~$ gcc 2.c
aakash@Aakash:~$ ./a.out

		**Optimal storage on tapes using Greedy method**

	Enter the no. of files : 5

	Enter the size of file 1 : 5

	Enter the size of file 2 : 10

	Enter the size of file 3 : 66

	Enter the size of file 4 : 12

	Enter the size of file 5 : 1


	Entered files sizes are : 5 10 66 12 1 

	Order of files sizes must be : 1 5 10 12 66 

	Minimum Mean Retrieval Time of this order is: 29.000
aakash@Aakash:~$ ./a.out

		**Optimal storage on tapes using Greedy method**

	Enter the no. of files : 6

	Enter the size of file 1 : 5 

	Enter the size of file 2 : 3

	Enter the size of file 3 : 7

	Enter the size of file 4 : 1

	Enter the size of file 5 : 3

	Enter the size of file 6 : 2


	Entered files sizes are : 5 3 7 1 3 2 

	Order of files sizes must be : 1 2 3 3 5 7 

	Minimum Mean Retrieval Time of this order is: 9.000


*/
