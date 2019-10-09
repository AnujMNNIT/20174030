#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void countSort(int arr[], int n) 
{ 
    int output[n]; 
    int i, count[10] = {0}; 
    for (i = 0; i < n; i++) 
        count[arr[i]]++; 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ arr[i]] - 1] = arr[i]; 
        count[ arr[i] ]--; 
    } 
  
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 

int main()
{
  int t1,t2,n;
  printf("enter number of test cases \n");
  scanf("%d",&t1);
  t2=t1;
  FILE *fp,*fp1,*fp2,*fp3;
  fp=fopen("merge.txt","w");
  while(t1--)
  { 
   n=(t2-t1)*40000;
   int i;
    int arr1[n],arr2[n],arr3[n],num;
    clock_t beg,end;
     double time1,time2,time3;
    fp1=fopen("mergea.txt","w");
    for(i=0;i<n;i++)
    {
       num=rand()%100;
       fprintf(fp1,"%d\n",num);
    }
    fclose(fp1);
     fp2=fopen("mergeb.txt","w");
     for(i=0;i<n;i++)
    {
       fprintf(fp2,"%d\n",i);
    }
    fclose(fp2);
     fp3=fopen("mergew.txt","w");
     for(i=0;i<n;i++)
    {
     
       fprintf(fp3,"%d\n",n-i);
    }
    fclose(fp3);
    fp1=fopen("mergea.txt","r");
     for(i=0;i<n;i++)
    {
       fscanf(fp1,"%d\n",&arr1[i]);
    }
    fclose(fp1);
     fp2=fopen("mergeb.txt","r");
      for(i=0;i<n;i++)
    {
       fscanf(fp2,"%d\n",&arr2[i]);
    }
    fclose(fp2);
      fp3=fopen("mergew.txt","r");
      for(i=0;i<n;i++)
    {
       fscanf(fp3,"%d ",&arr3[i]);
    }
    fclose(fp3);
    beg=clock();
    mergesort(arr1,0,n-1);
    end=clock();
    time1=(double)(end-beg)/CLOCKS_PER_SEC;
    beg=clock();
    mergesort(arr2,0,n-1);
    end=clock();
    time2=(double)(end-beg)/CLOCKS_PER_SEC;
    beg=clock();
    mergesort(arr3,0,n-1);
    end=clock();
    time3=(double)(end-beg)/CLOCKS_PER_SEC;
     fp1=fopen("mergeas.txt","w");
    for(i=0;i<n;i++)
    {
      
       fprintf(fp1,"%d\n",arr1[i]);
    }
    fclose(fp1);
     fp2=fopen("mergebs.txt","w");
     for(i=0;i<n;i++)
    {
       fprintf(fp2,"%d\n",arr2[i]);
    }
    fclose(fp2);
     fp3=fopen("mergews.txt","w");
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
