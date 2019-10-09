#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int a[], int l,int u) 
{ 
   int i, key, j; 
   for (i = l+1; i <=u; i++) 
   { 
       key = a[i]; 
       j = i-1; 
       while (j >=l && a[j] > key) 
       { 
           a[j+1] = a[j]; 
           j = j-1; 
       } 
       a[j+1] = key; 
   } 
} 
void merge(int a[], int l, int m, int u) 
{ 
    int i, j, k,n1,n2; 
    n1 = m - l + 1; 
    n2 =  u - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = a[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = a[m + 1+ j]; 
    i = 0; 
    j = 0; 
    k = l;  
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
            a[k++] = L[i++]; 
        else
            a[k++] = R[j++]; 
    } 
  
    while (i < n1)  
        a[k++] = L[i++];  
    while (j < n2)   
        a[k++] = R[j++]; 
 
} 
  
void mergesort(int a[], int l, int u) 
{ 
    if((u-l)<=10)
          insertion_sort(a,l,u);
    else      
    { 
        int m = (l+u)/2; 
        mergesort(a, l, m); 
        mergesort(a, m+1, u);  
        merge(a, l, m, u); 
    } 
} 

int main()
{
   FILE *fp=fopen("data.txt","w");
   int i,ran,a[1000];
   for(i=0;i<1000;i++)
   {
      ran=rand()%100;
      fprintf(fp,"%d ",ran);
   }   
   fclose(fp);
   fp=fopen("data.txt","r");
   for(i=0;i<1000;i++)
      fscanf(fp,"%d ",&a[i]);
    fclose(fp);
    mergesort(a,0,999);
   fp=fopen("datasorted.txt","w");
   for(i=0;i<1000;i++)
      fprintf(fp,"%d ",a[i]);
    fclose(fp);
   return 0;
}




