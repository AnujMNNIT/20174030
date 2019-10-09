#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition(int a[],int l,int u)
{
  int i,pivot=a[u];
  int li=l-1;
  for(i=l;i<=u-1;i++)
     if(a[i]<pivot)
     {
       li++;
       swap(&a[li],&a[i]);
     }  
  li++;
  swap(&a[li],&a[u]);
  return li;
}

int rpartition(int a[], int l, int u)
{
   int ran,len=u-l;
   ran=rand()%len+l;
   swap(&a[ran],&a[u]);
   return partition(a,l,u);
   
}

void QS(int a[],int l,int u)
{
  int q;
   while(l<u)
   {
      q=rpartition(a,l,u);
      if((q-l)>(u-q))
       {
         QS(a,l,q-1);
         l=q+1;
       }      
      else
      {
        QS(a,q+1,u);
        u=q-1;
      }
   }
}

int main()
{
   int i,a[20];
  
   for(i=0;i<20;i++)
   {
     int ran=rand()%100;
     printf("%d ",ran);
     a[i]=ran;
   }
    QS(a,0,20);
    printf("sorted:\n");
    for(i=0;i<20;i++)
   {
     printf("%d ",a[i]);
   }
}


