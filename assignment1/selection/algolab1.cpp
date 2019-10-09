#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void selectionsort(int arr[], int n) 
{ 
    int i, j, min; 
    for (i = 0; i < n-1; i++) 
    { 
  
        min= i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j;  
        swap(&arr[min], &arr[i]); 
    } 
    
} 

int main()
{
	int t;
	printf("\nenter number of test cases");
	scanf("%d",&t);
	while(t--)
	{
	FILE *fp;
	int i;
	int size,n;
	clock_t t_start,t_end;
	printf("\nenter number of elements");
	scanf("%d",&size);
	int arr[size];
	fp=fopen("selection_sort.text","w");
	if(fp==NULL)
	{
		printf("can't open this file");
		exit(1);
	}
	for(i=0;i<size;i++)
	{
		n=rand()%size;
		fprintf(fp,"%d\n",n);	
	}
	fclose(fp);
	
	
	fp=fopen("selection_sort.text","r");
	if(fp==NULL)
	{
		printf("can't open this file");
		exit(1);
	}
	for(i=0;i<size;i++)
	{	
		fscanf(fp,"%d\n",&arr[i]);	
	}
	fclose(fp);
	t_start=clock();
	selectionsort(arr,size);
	t_end=clock();
	fp=fopen("selection_sort1.text","w");
	if(fp==NULL)
	{
		printf("can't open this file");
		exit(1);
	}
	for(i=0;i<size;i++)
	{	
		fprintf(fp,"%d\n",arr[i]);	
	}
	fclose(fp);
	double time=(double)(t_end-t_start)/CLOCKS_PER_SEC;
	printf("\ntime of computation is: %lf",time);
	
   }
	
}
