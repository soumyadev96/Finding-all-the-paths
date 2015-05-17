#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define PATH "soumya41.txt"
#define MAX 999
#define N 4 //maximum no of possible path between any two node
int n,**arrr,*mark,*arr,**list,top=0,top1=-1,****paths;
int **creat(int);
void display(int **,int);
void copy_1(int *);
void pathfind();
void DFS(int ,int );
void show();
int main()
{
	int i,j,k;
	arrr=creat(1);
	display(arrr,n);
	pathfind();
	show();
        
}
void show()
{
	int i,j,k,l;
	for(k=0;k<n;k++)
	for(l=0;l<n;l++)
	{
		if(k!=l)
		{
		
		 printf("\n%d th to %d th node all paths are \n",k,l);
         i=0;
         while(paths[k][l][i]!=0)
         {
	
	      j=0;
	     while((paths[k][l][i][j]!=MAX)&&(j<n))
	      {
	
	       printf("%4d-->",paths[k][l][i][j]);
	       j++;
          }
          printf("\n");
		  i++;   
         }
	    }
    }
}
int **creat(int f)//creats adjacency matrix
{
	char arr[100],c;int i=0,j,k,n1,i1,l,**arrr1;FILE *ptr;
	if(f==1) 
	ptr=fopen(PATH,"r");
	
	fgets(arr,80,ptr);
    i=0;n=0;
	while(arr[i]!='\n')// gets the total no of vertex
	{
		k=arr[i]-'0';
		n=(n*10)+k;
		i++;
	}
	arrr1=(int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)
	arrr1[i]=(int *)malloc(sizeof(int)*n);
	n1=0;i=0;j=0;k=0;
	for(i=0;i<n;i++,j=0)
	{
	 fgets(arr,80,ptr);i1=0;
	 l=strlen(arr)-1;
	  for(i1=0;i1<=l;i1++)
	   {
	     if(isdigit(arr[i1]))
	     {
	      k=0;
	      k=arr[i1]-'0';
	       n1=n1*10+k;
	      if((i==n-1)&&(j==n-1))
	      arrr1[i][j]=n1;	
	     }
	    else
        {
         arrr1[i][j]=n1;
	     n1=0;j++;
	    }
	   }
	}
	fclose(ptr);
	return arrr1;
}
void display(int **arr,int n)//display a 2d array
{
	int i,j;
	for(i=0;i<n;i++)
	{
	  printf("\n");
	  for(j=0;j<n;j++)
       printf(" %d  ",arr[i][j]);
    }
	
}
void pathfind()
{
	int i,j,k;
	mark=(int *)malloc(sizeof(int)*n);
	arr=(int *)malloc(sizeof(int)*n);
	paths=(int ****)malloc(sizeof(int ***)*n);
	for(i=0;i<n;i++)
	{
	 paths[i]=(int ***)malloc(sizeof(int **)*n);
	
    }
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
		if(i!=j)
		{
		 list=(int **)malloc(sizeof(int *)*pow(n,N));
		 for(k=0;k<n;k++)
		   mark[k]=0;
		  for(k=0;k<pow(n,N);k++)
         list[k]=0;
		 mark[i]=1;
		 top=0;
		 top1=-1;
		 arr[top]=i;
	     DFS(i,j);
		 paths[i][j]=list;
		}
	}
}
void DFS(int s,int d)
{
int i,l;
for(i=0;i<n;i++)
{
	if((arrr[s][i]!=0)&&(mark[i]==0))
	{
		
		if(i!=d)
		{
			top++;
			mark[i]=1;
			arr[top]=i;
			DFS(i,d);
			mark[i]=0;
		}
		if(i==d)
		{
		    top++;
			arr[top]=d;
			copy_1(arr);
	
		}
	top--;	
	}
	
}	
}
void copy_1(int *arr)
{
	
	int *arr1,i;
	arr1=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	arr1[i]=MAX;
	for(i=0;i<=top;i++)
	arr1[i]=arr[i];
	top1++;
	list[top1]=arr1;
	
}
