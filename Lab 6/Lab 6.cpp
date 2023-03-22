#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root = NULL;

void showmenu()
{
	printf("Binary Search Tree \n");
	printf("1.Add Data\n");
	printf("2.Pre order\n");
	printf("3.In order\n");
	printf("4.Post order\n");
	printf("5.Exit\n");
	printf(" > ");
}
void addNode(struct node *xnode , struct node *data)
{
	if(xnode->data > data->data){
		if(xnode->left == NULL){
			xnode->left = data;
			return ;
		}
		addNode(xnode->left,data);
		return;
	}
	if(xnode->right == NULL){
		xnode->right = data;
		return ;
	}
	addNode(xnode->right,data);
}
void adddata(){
	struct node *data = (struct node*) malloc(sizeof(struct node));
	data->left = NULL;
	data->right = NULL;
	printf("Input Data > ");
	scanf("%d",&data->data);
	if(root == NULL){
		root = data;
		return;
	}
	addNode(root,data);	
}
void preorder(struct node *xnode)
{
	if(xnode == NULL){
		return;
	}
	printf("%d",xnode->data);
	preorder(xnode->left);
	preorder(xnode->right);
}
int getchoice()
{
	int data;
	scanf("%d",&data);
	return data;
}
int main()
{
	for(;;){
		showmenu();
		switch(getchoice()){
			case 1:
				adddata();
				break;
			case 2: 
				preorder(root);	
				break;	
		}
	}	
}
