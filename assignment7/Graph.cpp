#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define white 1
#define gray  2
#define black 3
#define null -1
#define infinite 9999
int ttime=0;
struct Graph1
{
	int color;
	int pie;    //pie->parent
	int dist;  //dist->distance from source node 	           
};

struct Graph2
{
	int color;
	int pie;    //pie->parent
	int dt;
	int ft;  //dist->distance from source node 	           
};

typedef struct Graph1 graph_bfs;
typedef struct Graph2 graph_dfs;

 struct queue
{
	int rear;
	int capacity;
	int front;
	int *arr;
};

//queue......................................................

struct queue* createqueue(int capacity)
{
	struct queue *Q=(struct queue*)malloc(sizeof(struct queue));
	Q->capacity=capacity;
	Q->rear=-1;
	Q->front=0;
	Q->arr=(int*)malloc(capacity*sizeof(int));
	return Q;
}
int isempty(struct queue* Q)
{
	if((Q->front-Q->rear==1)||Q->rear==-1)
		return 1;
	return 0;
	
}		
void enqueu(struct queue* Q,int n)
{
	if(Q->rear==(Q->capacity)-1)
	{
		printf("overflow condition");
		return;
	}
	Q->arr[++Q->rear]=n;
}
int dequeue(struct queue* Q)
{
	if(isempty(Q)!=1)
	  return Q->arr[Q->front++];
	return NULL;  
}
void display(struct queue* Q)
{
	if(isempty(Q)!=1)
	{
	int p=Q->front;
	printf("elements of the queue\n");
	do
	{printf("%d\t",Q->arr[p++]);}while(p-Q->rear!=1);
	}
}

//................................................................

//BREADTH FIRST SEARCH...........................................

void BFS_visit(graph_bfs gp[],int s,int* path,int vertex)	
{
   int i,j,v;
   struct queue* Q= createqueue(vertex*vertex);
   gp[s].color=gray;
   gp[s].pie=null;
   gp[s].dist=0;
   enqueu(Q,s);
   printf("\n");
   while(isempty(Q)!=1)
   {
   	   v=dequeue(Q);
   	   
   	   for(j=0;j<vertex;j++)
   	   {
   	   	   if(*((path+v*vertex)+j)!=0)
   	   	   { 
   	   	        if(gp[j].color==white)
				{
				  gp[j].color=gray;
   	              gp[j].pie=v;
   	              gp[j].dist=gp[v].dist+ (*((path+v*vertex)+j));
   	              enqueu(Q,j); 	   	
				}	
	       }
   	   	
	   }
	   gp[v].color=black;
	   printf("%d |%d |%d |%d \n",v,gp[v].color,gp[v].pie,gp[v].dist);
   }	
}

void BFS(graph_bfs gp[],int* path,int vertex)
{
	int i,cnt=0;
	for(i=0;i<vertex;i++)
	{
		gp[i].color=white;
		gp[i].pie=null;
		gp[i].dist=infinite;
	}
	for(i=0;i<vertex;i++)
	   if(gp[i].color==white)
	   {
	   	cnt++;
	   	BFS_visit(gp,i,path,vertex);
	   }
	   printf("No. of components :%d\n",cnt);	
}


//.....................................................................


//DEPTH FIRST SEARCH...................................................



void DFS_visit(graph_dfs gp[],int v,int *path,int vertex)
{
	int j;
	gp[v].dt=++ttime;
	gp[v].color=gray;
	printf("%d |%d \n",v,gp[v].pie );
	 for(j=0;j<vertex;j++)
   	   {
   	   	   if(*((path+v*vertex)+j)!=0)
   	   	   { 
   	   	        if(gp[j].color==white)
				{
				 gp[j].pie=v;
				 DFS_visit(gp,j,path,vertex);
				}	
	       }
   	   	
	   }
	gp[v].ft=++ttime;
	gp[v].color=black;

}
void DFS(graph_dfs gp[],int *path,int vertex)
{
	int i,cnt=0;
	for(i=0;i<vertex;i++)
	{
		gp[i].color=white;
		gp[i].pie=null;
		gp[i].dt=0;
		gp[i].ft=0;
	}
	for(i=0;i<vertex;i++)
	   if(gp[i].color==white)
	   {
	   	cnt++;
	   	DFS_visit(gp,i,path,vertex);
	   }
	   printf("No. of components :%d",cnt);	
}



int main()
{
	int i,j;
	int vertex,count; 
	clock_t beg,end;
	double second;
	while(1)
	
	{
	ttime=0;
	count=0;	
	printf("\nenter number of vertices:\n");
	scanf("%d",&vertex);
	int path[20][20];
	graph_bfs gp1[vertex];
	graph_dfs gp2[vertex];
    for(int i=0;i<vertex;i++)
     for(int j=0;j<vertex;j++)
     {
     	path[i][j]=rand()%2;
     	if(path[i][j]!=0)
     	 count++;	
	 }
        
    for(int i=0;i<vertex;i++)
    {
    	printf("\n");
    	for(int j=0;j<vertex;j++)
         printf("%d ",path[i][j]);	
	}  
	printf("\nBFS:\n");
	
	
	beg=clock();
	BFS(gp1,&path[0][0],vertex);
	end=clock();
	second=((double)(end-beg))/CLOCKS_PER_SEC;
	printf("%lf is time of computation with %d number of edge and vertex\n",second,(count+vertex));
	
	
	printf("DFS:\n");
	beg=clock();
	DFS(gp2,&path[0][0],vertex);
	end=clock();
	second=((double)(end-beg))/CLOCKS_PER_SEC;
	printf("\n%lf is time of computation with %d number of edge and vertex\n",second,(count+vertex));
	
	}
	
	    
}
