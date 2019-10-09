
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct Node
{
	int info;
	struct Node* next;
};
typedef struct Node node;
void insert(node* head, int x) 
{ 
    node* p = (node*)malloc(sizeof(node)) ; 
    p->info  = x; 
    p->next = head; 
    head= p; 
} 
int display(node *head,int arr[],int index) 
{ 
    node *temp = head; 
    while(temp != NULL) 
    {   
        arr[index++]=temp->info;
        printf("%d  ", temp->info); 
        temp = temp->next; 
    } 
    return index;
} 
  
void sortedInsert(node  *head, node* new_node) 
{ 
    node* current; 
    if (head == NULL || (head)->info >= new_node->info) 
    { 
        new_node->next = head; 
        head = new_node; 
    } 
    else
    { 
        current = head; 
        while (current->next!=NULL && 
               current->next->info < new_node->info) 
        { 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
} 
void insertionSort(node* head) 
{ 
    node *sorted = NULL; 
    node *current = head; 
    if(current==NULL)
      {
      	printf("empty");
      	return;
	  }
    while (current != NULL) 
    { 
         
        node *next = current->next; 
        sortedInsert(sorted, current); 
        current = next; 
    } 
    head = sorted; 
} 
void bucketsort(int a[],node* head[],int n)
{
  int i,index=0;
  for(i=0;i<n;i++)
  {
  	insert(head[a[i]/1000],a[i]);
  }
  for(i=0;i<100;i++)
  {
  	insertionSort(head[i]);	
  }
  for(i=0;i<n;i++)
  {
  	index=display(head[i],a,index);
  	index++;
  }
  
  
}

main()
{
	int i,n,t;
	printf("Enter the no. of test cases: ");
	scanf("%d",&t);
	FILE *fp=fopen("bucket.txt","w");
	
	while(t--)
	{
		//scanf("%d",&n);
		n=100*(10-t);
		int arr1[n],arr2[n],arr3[n],num;
		node* head[100];
		clock_t end,start;
		double clock_time1,clock_time2,clock_time3;
		FILE *fp1=fopen("avgbucket.txt","w");
		FILE *fp2=fopen("bestbucket.txt","w");
		FILE *fp3=fopen("worstbucket.txt","w");
	
		for(i=0;i<n;i++)
		{
			num=rand();
			fprintf(fp1,"%d ",num);
		}
		fclose(fp1);
		fp1=fopen("avgbucket.txt","r");
		for(i=0;i<n;i++)
		{
			fscanf(fp1,"%d ",&arr1[i]);
		}
		
		for(i=0;i<n;i++)
		{
			fprintf(fp2,"%d ",i);
		}
		fclose(fp2);
		fp2=fopen("bestbucket.txt","r");
		for(i=0;i<n;i++)
		{
			fscanf(fp2,"%d ",&arr2[i]);
		}
		
		for(i=0;i<n;i++)
		{
			fprintf(fp3,"%d ",n-i);
		}
		fclose(fp3);
		fp3=fopen("worstbucket.txt","r");
		for(i=0;i<n;i++)
		{
			fscanf(fp3,"%d ",&arr3[i]);
		}
		
		start=clock();
	    bucketsort(arr1,head,n);
		end=clock();
		clock_time1=((double)(end-start))/CLOCKS_PER_SEC;

		start=clock();
	    bucketsort(arr2,head,n);
		end=clock();
		clock_time2=((double)(end-start))/CLOCKS_PER_SEC;
		
		start=clock();
	    bucketsort(arr3,head,n);
		end=clock();
		clock_time3=((double)(end-start))/CLOCKS_PER_SEC;

    	fprintf(fp,"%d %lf %lf %lf\n",n,clock_time1,clock_time2,clock_time3);
	}
}

