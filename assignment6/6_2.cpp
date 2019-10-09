#include<stdio.h>
#include<stdlib.h>
struct BST
{
          int info;
          struct BST* p;
          struct BST* lc;
          struct BST* rc;
          int size;
          int balance;
};
int max(int h1,int h2)
{
   return h1>h2?h1:h2;
}
typedef struct BST bst;
int aug_bst(bst* root)
{
          int s1,s2;
          if(root==NULL)
              return 0;
          s1=aug_bst(root->lc);
          s2=aug_bst(root->rc);
          root->size=s1+s2+1;
          return (root->size);
}
int iton(bst* root,int i)
{
          int cr;
          if(root->lc!=NULL)
             cr=(root->lc->size)+1;
          else
             cr=1;   
          if(i==cr)
          return root->info;
          if(i>cr)
          return(iton(root->rc,i-cr));
          if(i<cr)
          return(iton(root->lc,i));
}
int height(bst* root)
{
  int h1,h2;
  if(root==NULL)
  return 0;
  if(root!=NULL)
  {
    h1=height(root->lc);
    h2=height(root->rc);
    root->balance=h1-h2;
    return max(h1,h2)+1;  
  }
}
void inorder(bst* root)
{
          if(root!=NULL)
          {
             inorder(root->lc);
             printf(" %d    %d    %d \n",root->info,root->size,root->balance);
             inorder(root->rc);
          }
}
bst* llrotation(bst* root)
{
	bst *p=root->lc->rc;
	root->lc->rc=root;
	root=root->lc;
	root->rc->lc=p;
	return root;
}
bst* rrrotation(bst* root)
{
	bst *p=root->rc->lc;
	root->rc->lc=root;
	root=root->rc;
	root->lc->rc=p;
	return root;
}
bst* lrrotation(bst* root)
{
	bst *p=root->lc->rc->lc;
	bst *q=root->lc->rc->rc;
	root->lc->rc->lc=root->lc;
	root->lc->rc->rc=root;
	root=root->lc->rc;
	root->lc->rc=p;
	root->rc->lc=q;
	return root;
}
bst* rlrotation(bst* root)
{
	bst *p=root->rc->lc->rc;
	bst *q=root->rc->lc->lc;
	root->rc->lc->rc=root->rc;
	root->rc->lc->lc=root;
	root=root->rc->lc;
	root->rc->lc=p;
	root->lc->rc=q;
	return root;
}
bst* balance_avl(bst* root ,int bal)
{
	if(bal==2)
	{
		if(root->lc->balance==1)
		{
			printf(":LL:---");
			root=llrotation(root);
		}
		if(root->lc->balance==-1)
		{
			printf(":LR:---");
			root=lrrotation(root);
		}
	}
	else
	if(bal==-2)
	{
		if(root->rc->balance==-1)
		{
			printf(":RR:---");
			root=rrrotation(root);
		}
		if(root->rc->balance==1)
		{
			printf(":RL:---");
			root=rlrotation(root);
		}
	}
	return root;
}
bst* insert(bst* root,int a)
{
           if(root==NULL)
            {
                       bst* root=(bst*)malloc(sizeof(bst));
                       root->info=a;
                       root->lc=NULL;
                       root->rc=NULL;
                       return root;
            }
            if(a<root->info)
            {
            root->lc=insert(root->lc,a);
            }
            else if(a>root->info)
            {
            root->rc=insert(root->rc,a);
            }
            int bal=height(root->lc)-height(root->rc);
            //printf("%d  ",bal);
            return balance_avl(root,bal);
}
bst* create_avl(bst* root ,int a[],int n)
{
          int i;
          for(i=0;i<n;i++)
          {
            root=insert(root,a[i]);
          }
          printf("inorder traversal:\n");
         // inorder(root);
          int h= height(root);
          int rootsize=aug_bst(root);
        //printf("inorder traversal after augmentation:\n");
          printf("info size balance\n");
          inorder(root);
        // printf("%d is height \n",h);
          return root;
}
int main()
{
          int n,i;
          printf("enter the no. of elements\n ");
          scanf("%d",&n);
          int a[n];
          printf("enter elements of array\n");
          for(i=0;i<n;i++)
             scanf("%d",&a[i]);
          bst* root=NULL;
          root=create_avl(root,a,n);
          printf("enter value of i\n");
          scanf("%d",&i);
          printf("\n%d is %dth order static",iton(root,i),i); 
}
