#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;

void showMenu(){
	printf("\tBinary Search Tree \n");
	printf("\t 1.Add data \n");
	printf("\t 2.Pre order \n");
    printf("\t 3.In order\n");
    printf("\t 4.Post order\n");
    printf("\t 5.Exit\n\n");
	printf("choice > ");
}

void addNode(struct node *xnode, struct node *data){ // xnode = parent , data = child
	if(xnode->data > data->data){
		if(xnode->left==NULL){
			xnode->left=data;
			return;
		}
		addNode(xnode->left,data);
		return;
	}
	if(xnode->right==NULL){
		xnode->right=data;
	return;
		}
		addNode(xnode->right,data);
}

void addData(){
	struct node *data = (struct node*) malloc(sizeof(struct node));
	data->left = NULL;
	data->right = NULL;
	printf("Input Data > ");
	scanf("%d",&data->data);
	if(root==NULL){
		root = data;
		return;
	}
	addNode(root,data);
}

int getChoice(){
	int data;
	scanf("%d",&data);
	return data;
}

void pre_order(struct node *xnode){
	if(xnode == NULL){
		return;
	}
	printf("%d ",xnode->data);
	pre_order(xnode->left);
	pre_order(xnode->right);
}

void in_order(struct node *xnode){
	if(xnode == NULL){
		return;
	}
	in_order(xnode->left);
	printf("%d ",xnode->data);
	in_order(xnode->right);
}

void post_order(struct node *xnode){
	if(xnode == NULL){
		return;
	}
	post_order(xnode->left);
	post_order(xnode->right);
	printf("%d ",xnode->data);
}

int main(){
	for(;;){
		showMenu();
		switch(getChoice()){
			case 1:
                addData();
                break;
            case 2:
            	printf("Pre order > ");
                pre_order(root);
                printf("\n\n");
                break;
            case 3:
            	printf("In order  > ");
            	in_order(root);
                printf("\n\n");
                break;
            case 4:
            	printf("Post order > ");
            	post_order(root);
                printf("\n\n");
                break;
			case 5:
				return 0;
		}
	}
}
