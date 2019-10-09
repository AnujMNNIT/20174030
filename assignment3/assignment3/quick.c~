#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
 
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];   
    int i = (low - 1),j; 
  
    for ( j = low; j <= high- 1; j++) 
    { 
         
        if (arr[j] <= pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  

void quicksort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
      
        int pi = partition(arr, low, high); 
        quicksort(arr, low, pi - 1); 
        quicksort(arr, pi + 1, high); 
    } 
} 


int main()
{
  int t1,t2,n;
  printf("enter number of test cases \n");
  scanf("%d",&t1);
  t2=t1;
  FILE *fp,*fp1,*fp2,*fp3;
  fp=fopen("quick.txt","w");
  while(t1--)
  { 
   n=(t2-t1)*10000;
   int i;
    int arr1[n],arr2[n],arr3[n],num;
    clock_t beg,end;
     double time1,time2,time3;
    fp1=fopen("quicka.txt","w");
    for(i=0;i<n;i++)
    {
       num=rand()%1000000;
       fprintf(fp1,"%d\n",num);
    }
    fclose(fp1);
     fp2=fopen("quickb.txt","w");
     for(i=0;i<n;i++)
    {
       fprintf(fp2,"%d\n",i);
    }
    fclose(fp2);
     fp3=fopen("quickw.txt","w");
     for(i=0;i<n;i++)
    {
     
       fprintf(fp3,"%d\n",n-i);
    }
    fclose(fp3);
    fp1=fopen("quicka.txt","r");
     for(i=0;i<n;i++)
    {
       fscanf(fp1,"%d\n",&arr1[i]);
    }
    fclose(fp1);
     fp2=fopen("quickb.txt","r");
      for(i=0;i<n;i++)
    {
       fscanf(fp2,"%d\n",&arr2[i]);
    }
    fclose(fp2);
      fp3=fopen("quickw.txt","r");
      for(i=0;i<n;i++)
    {
       fscanf(fp3,"%d ",&arr3[i]);
    }
    fclose(fp3);
    beg=clock();
    quicksort(arr1,0,n-1);
    end=clock();
    time1=(double)(end-beg)/CLOCKS_PER_SEC;
    beg=clock();
    quicksort(arr2,0,n-1);
    end=clock();
    time2=(double)(end-beg)/CLOCKS_PER_SEC;
    beg=clock();
    quicksort(arr3,0,n-1);
    end=clock();
    time3=(double)(end-beg)/CLOCKS_PER_SEC;
     fp1=fopen("quickas.txt","w");
    for(i=0;i<n;i++)
    {
      
       fprintf(fp1,"%d\n",arr1[i]);
    }
    fclose(fp1);
     fp2=fopen("quickbs.txt","w");
     for(i=0;i<n;i++)
    {
       fprintf(fp2,"%d\n",arr2[i]);
    }
    fclose(fp2);
     fp3=fopen("quickws.txt","w");
     for(i=0;i<n;i++)
    {
       num=rand();
       fprintf(fp3,"%d\n",arr3[i]);
    }
    fclose(fp3);
    printf("%d %lf %lf %lf\n",n,time1,time2,time3);
    fprintf(fp,"%d %lf %lf %lf\n",n,time1,time2,time3);  
  }
  return 0;
}
