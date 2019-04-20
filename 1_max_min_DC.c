/*
	Name :- Aakash Bhaskar Kalore ,
	Branch:- IT , Std. :- TE , Div. :- A ,
	Roll no. :- 35026 ,
	Sub. :-  DAA.
*/

#include<stdio.h>

void maxmin(int *array,int x,int y,int *max,int *min);

int main()
{
	int array[20],n,i,max,min;
	
	printf("\n\t\t**Max & Min using Divide & Conquer Strategy**\n");
	
	printf("\n\tEnter the size of array : ");
	scanf("%d",&n);
	
	printf("\n\tEnter the array Elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	
	printf("\n\tEntered Array is:");
	for(i=0;i<n;i++)
	{
		printf(" %d",array[i]);
	}
	
	max=array[0];
	min=array[0];
	maxmin(array,0,n-1,&max,&min);
	
	printf("\n\n\tFrom the given array :\n\t 1. Max no. is : %d\n\t 2. Min no. is : %d",max,min);
	
	printf("\n");
	return 0;
}

int maxf(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}

int minf(int x,int y)
{
	if(x<y)
		return x;
	else
		return y;
}

void maxmin(int *array,int x,int y,int *max,int *min)
{
	int lmax,lmin;
	if(y<=x+1)
	{
		lmax=maxf(array[x],array[y]);
		lmin=minf(array[x],array[y]);
		if(lmin<*min)
			*min=lmin;
		if(lmax>*max)
			*max=lmax;
		return;	
	}
	else
	{
		maxmin(array,x,((x+y)/2),max,min);
		maxmin(array,(((x+y)/2)+1),y,max,min);
		lmax=maxf(array[x],array[y]);
		lmin=minf(array[x],array[y]);
		if(lmin<*min)
			*min=lmin;
		if(lmax>*max)
			*max=lmax;
		return;	
	}
}

/*

					**OUTPUT**
					
					
aakash@Aakash:~$ gcc 1.c
aakash@Aakash:~$ ./a.out

		**Max & Min using Divide & Conquer Strategy**

	Enter the size of array : 5

	Enter the array Elements : 1 6 -1 7 11  

	Entered Array is: 1 6 -1 7 11

	From the given array :
	 1. Max no. is : 11
	 2. Min no. is : -1
aakash@Aakash:~$ gcc 1.c
aakash@Aakash:~$ ./a.out

		**Max & Min using Divide & Conquer Strategy**

	Enter the size of array : 10

	Enter the array Elements : 1 9 3 -11 5 6 7 500 60 -945

	Entered Array is: 1 9 3 -11 5 6 7 500 60 -945

	From the given array :
	 1. Max no. is : 500
	 2. Min no. is : -945

*/
