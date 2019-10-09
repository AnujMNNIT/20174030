#include<stdio.h>
#include<stdlib.h>
#define infinite 99999
struct Heap
{
	int info;
	int lindex; 
	int index;
};
typedef struct Heap heap;
int k=10;
int n=10;
int a[10][10]={
	          {1,2,3,4,5,6,7,8,9,10},
	          {11,12,13,14,15,16,17,18,19,20},
	          {21,22,23,24,25,26,27,28,29,30},
	          {31,32,33,34,35,36,37,38,39,40},
	          {41,42,43,44,45,46,47,48,49,50},
	          {2,4,6,8,10,12,14,16,18,20},
	          {3,6,9,12,15,18,21,24,27,30},
	          {5,10,15,20,25,30,35,40,45,50},
	          {10,20,30,40,50,60,70,80,90,100},
	          {1,1,1,1,1,1,1,1,1,1}
			 };

void swap(heap* a, heap* b)
{
	heap t = *a;
	*a= *b;
	*b = t;
}
void minheapify(heap a[],int i,int HS)
{
  int lc=2*i+1 ,rc=2*i+2;
  int small=i;
  if(lc<=HS&&a[lc].info<a[small].info)
  small=lc;
  if(rc<=HS&&a[rc].info<a[small].info)
  small=rc;
  if(i!=small)
  {
	swap(&a[i],&a[small]);
	minheapify(a,small,HS);
  }
}
void buildminheap(heap a[],int HS,int n)
{
  int i;
  for(i=n/2;i>=0;i--)
  minheapify(a,i,HS);
 
}  

void merge(heap Heap[],int merg[],int HS)
{
    buildminheap(Heap,HS,k);
    int i;
    for(i=0;i<n*k;i++)
    {
    	merg[i]=Heap[0].info;
    	if (Heap[0].index< n) 
		{ 
			Heap[0].info = a[Heap[0].lindex][(Heap[0].index)++]; 	
		}  
		else 
		   Heap[0].info = infinite;   	
		   minheapify(Heap,0,HS);  	
		
	}
 
}

int main()
{
	int i,merg[k*n];
	heap Heap[10*k];
	for(i=0;i<k;i++)
	{
	    Heap[i].info=a[i][0];
	    Heap[i].lindex=i;
	    Heap[i].index=1;	
	}
	merge(Heap,merg,10);
	for(i=0;i<n*k;i++)
	{
		printf("%d ",merg[i]);
	}
} 
