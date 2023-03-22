#include<stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	char data[100];
	struct node *next;
};
struct edges {
	char data2;
	struct node *left;
	struct node *right;
};
struct node *root = NULL;
struct edges *root = NULL;

void showMenu()
{
	printf("\n");
    printf("-----Graph-----\n");
    printf("1 Insert Vertices\n");
    printf("2 Insert Edges\n");
    printf("3 Exit\n\n");
    printf("choice -> ");
}
int getChoice(){
	int data;
	scanf("%d",&data);
	return data;
}

void addData()
{
    struct node *data = (struct node*) malloc(sizeof(struct node));
    printf("Insert Vertices -> ");
    scanf("%s", &data->data);
    if(root == NULL){
        data->next = NULL;
    }else{
        data->next = root;
    }
    root = data;
}
int main(){
	for(;;){
		showMenu();
		switch(getChoice()){
			case 1:
                addData();
                break;
            case 2:
            	
                break;
            case 3:
            	return 0;	
  		}
 	}
}
