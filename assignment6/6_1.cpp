#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 


int partition(int a[], int l, int u)
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
int IOS(int a[],int l,int u,int i)
{
   if(l==u)
   return a[l];
   if(u<l)
   return NULL;
   int q=rpartition(a,l,u);
   int absp=q-l+1;
   if(absp==i)
   return a[q];
   else if(absp>i)return(IOS(a,l,q-1,i));
   else if(absp<i)return(IOS(a,q+1,u,i-absp));
   
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
void minmax(int a[],int n)
{
  int min,max,i;
  if(a[0]<a[1])
  {
  min=a[0];max=a[1];
  }
  else
  {
  min=a[1];max=a[0];
  }
  for(i=2;i<n-1;i++)
  {
     if(a[i]<a[i+1])
     { 
        if(a[i]<min)
        min=a[i];
        if(a[i+1]>max)
        max=a[i+1];
     }
     else
     {
        if(a[i+1]<min)
        min=a[i+1];
        if(a[i]>max)
        max=a[i];
     }
     
  }
  printf("\nmin:%d\nmax:%d\n",min,max);
  
  
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
    minmax(a,20);
    printf("enter the value of i");
    scanf("%d",&i);
    printf("%d is %dth order static\n",IOS(a,3,15,i),i);
     for(i=0;i<20;i++)
   {
     
     printf("%d ",a[i]);
    
   }
    QS(a,0,19);
    printf("\nsorted:\n");
    for(i=0;i<20;i++)
   {
     printf("%d ",a[i]);
   }
  
}
