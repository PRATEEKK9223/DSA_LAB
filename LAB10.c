#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *lchild,*rchild;
};

typedef struct node Treenode;

Treenode* getNode(int ele)
{
    Treenode *newnode;
    newnode=(Treenode*)malloc(sizeof(Treenode));
    newnode->data=ele;
    newnode->lchild=0;
    newnode->rchild=0;
    return newnode;
}

Treenode* insert(Treenode* root,int ele)
{
    if(root==0)
        root=getNode(ele);
    else if(ele < root->data)
        root->lchild=insert(root->lchild,ele);
    else
        root->rchild=insert(root->rchild,ele);

    return root;  
}

void preorder(Treenode *root)
{
    if(root==0)
        return ;
    else{
        printf("%d-",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void inorder(Treenode *root)
{
    if(root==0)
        return ;
    else{
        inorder(root->lchild);
        printf("%d-",root->data);
        inorder(root->rchild);
    }
}

int search(Treenode *root,int key)
{
    if(root==0)
        return 0;
    else if(root->data==key)
        return 1;
    else if(key<root->data) 
        search(root->lchild,key);
    else
        search(root->rchild,key);
}

void main()
{
    int ele,N,key;
    Treenode *root=NULL;
    printf("enter the number of nodes\n");
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        printf("enetr the data\n");
        scanf("%d",&ele);
        root=insert(root,ele);
    }

    printf("\npreorder\n");
    preorder(root);
    printf("inorder\n");
    inorder(root);
    printf("enter the key you want to search\n");
    scanf("%d",&key);
    if(search(root,key))
        printf("found");
    else
        printf("not found\n");

   
}