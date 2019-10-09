
#include<stdio.h>
#include<stdlib.h>
#define white 1
#define gray  2
#define black 3
#define null -1
#define infinite 9999
int ttime=0;

struct list{
	int info;
	struct list *next;
};
struct Graph{
	int pie ;
	int color;
	int dt;
	int ft;
};
typedef struct Graph graph;
typedef struct list node;
node *head=NULL;
 insertnode(node* a[],int v,int w)
{
	node *q=(node *)malloc(sizeof(node));
	q->info=w;
	q->next=a[v]->next;
	a[v]->next=q;	
}
node *insert(node* head,int info)
{
	node *p=(node *)malloc(sizeof(node));
	p->info=info;
	if(head==NULL)
	{
		p->next=NULL;
		return p;
	}
	p->next=head->next;
	head->next=p;
	return head;
}

void display(node* head)
{
		node* p=head;
		if(p==NULL)
		printf("khali hai dhakkan");
		while(p!=NULL)
		{
			printf("-> %d ",p->info);
			p=p->next;
		}
}

void displaygraph(node* a[],int vertex)
{
	int i;
	for(i=0;i<vertex;i++)
	{
		printf("\n%d ",i);
		node* p=a[i]->next;
		while(p!=NULL)
		{
			printf("-> %d ",p->info);
			p=p->next;
		}
	}
	
}


 DFS_visit(graph gp[],int v,node* a[],int vertex)
{
	int j;
	gp[v].dt=++ttime;
	gp[v].color=gray;
	printf("%d |%d \n",v,gp[v].pie );
	node *p=a[v]->next;
	while(p!=NULL)
	{
		        if(gp[p->info].color==white)
				{
				 gp[p->info].pie=v;
				 DFS_visit(gp,p->info,a,vertex);
				}	
				p=p->next;	
	}
   	   	       
	gp[v].ft=++ttime;
	gp[v].color=black;
    insert(head,v);
}

 DFS(graph gp[],node* a[],int vertex)
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
	   	DFS_visit(gp,i,a,vertex);
	   }
	   printf("No. of components :%d",cnt);	
}


void toposort(graph gp[],node *a[],int vertex)
{
	printf("\n");
	DFS(gp,a,vertex);
	printf("HI\n");
	display(head);
	printf("BYE\n");
}

int main()
{
	int vertex,v,w,e,i;
	printf("Enter the number of vertices and edges: ");
	scanf("%d%d",&vertex,&e);
	struct list *a[vertex];
	graph gp[vertex];
	for(i=0;i<vertex;i++)
	{
		    node *p=(node *)malloc(sizeof(node));
		    a[i]=p;
			a[i]->info=i;
			a[i]->next=NULL;
	}
	
	printf("Enter the pair of vertices containing edge: ");
	while(e--)
	{
		scanf("%d%d",&v,&w);
		insertnode(a,v,w);
	}
	displaygraph(a,vertex);
	DFS(gp,a,vertex);
	toposort(gp,a,vertex);
	
}

