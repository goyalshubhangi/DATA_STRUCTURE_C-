#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct TREE
{
	int data;
	struct TREE*left;
	struct TREE*right;
}TREE;
int heightoftree(TREE*root);
int main()
{
	int data,depth;
	TREE*tree=NULL;
	TREE*InsertTree(int data,TREE*p);
	TREE*PrintTreeTriangle(TREE*tree,int level);

	while(1)
	{
		cout<<"\nKey to insert|";
		cin>>data;
		if (data==0)
			  break;
		tree =InsertTree(data,tree);
		cout<<"\n Tree Display;\n";
		PrintTreeTriangle(tree,1);
		depth=0;
	}
cout<<heightoftree(tree);
	return(0);
}
TREE *InsertTree(int data,TREE *p) {
	if(!p) {
		p=(TREE*)malloc(sizeof(TREE));
		p->data=data;
		p->left=NULL;
		p->right=NULL;
		return(p);
	}
	if(data < p->data)
		p->left=InsertTree(data,p->left); else
		if(data > p->data)
		p->right=InsertTree(data,p->right);
	return(p);
}
int heightoftree(TREE* root)
{
	if(root==NULL)
		return 0;
	else
	{
		if(root->left==NULL&&root->right==NULL)
			return 0;

		int xl= heightoftree(root->left);
		int xr= heightoftree(root->right);

		return (max(xl,xr)+1);
	}
}

int max(int x, int y)
{
	return  x>y?x:y;
}
TREE *PrintTreeTriangle(TREE *tree, int level) {
	int i;
	if(tree) {
		PrintTreeTriangle(tree->right,level+1);
		cout<<"\n\t";
		for (i=0;i<level;i++)
				cout<<"    ";
		cout<<tree->data;
		PrintTreeTriangle(tree->left,level+1);
	}
	return(NULL);
}

