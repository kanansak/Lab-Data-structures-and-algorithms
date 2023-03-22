#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Node{
	char name[100];
	bool mark;
	struct node *next;
};

struct Edge{
	char node1[100];
	char ndoe2[100];
	struct Edge *next;
};

char stack[30][100];
int top = -1;

char queue[30][100];
int f = -1;
int r = -1;

struct Node *node = NULL;
struct Edge *edge = NULL;

bool isQFull(){
	if(f>=29){
		return true;
	}
	return false;
}

bool isQEmpty(){
	if(f==1){
		return true;
	}
	return false;
}

void enqueue(char data[100]){
	if(isQFull()){
		return;
	}
	if(f==-1){
		f = 0;
		r = 0;
	}
	else {
		f = f+1;
	}
	strcpy(queue[f],data);
}

char * dequeue(){
	static char data[100];
	if(isQEmpty()){
		strcpy(data, "");
		return data;
	}
	strcpy(data,queue[r]);
	if(f==r){
		f = -1;
		r = -1;
	}
	else {
		r = r+1;
	}
	return data;
}

bool isStackFull(){
	if(top>=29){
		if(top = -1){
			return true;
		}
		return false;
	}
}

bool isStackEmpty(){
	if(top==-1){
		return true;
	}
	return false;
}

void push (char data[100]){
	if(isStackFull()){
		return;
	}
	top = top+1;
	strcpy(stack[top],data);
}

char * pop(){
	static char data[100];
	if(isStackEmpty()){
		strcpy(data,"");
		return data;
	}
	strcpy(data,stack[top]);
	top = top -1;
	return data;;
}

void showMenu(){
	printf("\n\n<< Graph >> \n");
	printf("1. Add Vertex\n");
	printf("2. List node\n");
	printf("3. Add edge \n");
	printf("4. List edge \n");
	printf("5. Depth first search\n");
	printf("6. Breadth first search\n");
	printf("7. Exit \n\n");
	printf("Choice > ");
}

int getChoice(){
	int choice;
	scanf("%d",&choice);
	printf("\n");
	return choice;
}

void addNode(){
	struct Node *newnode = (struct Node*) malloc(sizeof(struct Node));
	printf("\nNode name > ");
	scanf("%s", &newnode->name);
	if(node==NULL){
		newnode->next = NULL;
	}
	else{
		newnode->next = node;
	}
	node = newnode;
}

void listNode(){
	struct Node *data = node;
	while(data != NULL){
		printf("Node : %s\n",data->name);
		data = data->next;
	}
	printf("\n");
}

bool chk(char name[100]){
	struct Node *data = node;
	while(data!=NULL){
		if(strcmp(data->name, name)==0){
			return true;
		}
		data = data->next;
	}
	return false;
}

void addEdge(){
	char node1[100];
	char node2[100];
	printf("node1 > ");
	scanf("%s,&node1");
	printf("node2 > ");
	scanf("%s,&node2");
	if(chk(node1)&&chk(node2)){
		struct Edge *newedge = (struct Edge*) malloc(sizeof(struct Edge));
		strcpy(newedge -> node1,node1);
		strcpy(newedge -> node2,node2);
		if(edge==NULL){
			newedge->next = NULL;
		}
		else{
			newedge->next = edge;
		}
		edge = newedge;
		printf("edge %s:%s iis making \n\n",newedge->node1,newedge->node2);
	}
	else{
		printf("can not make edge \n\n");
	}
}

void listEdge(){
	struct Edge *data = edge;
	while(data!=NULL){
		printf("Edge %s:%s\n",data->node1,data->node2);
		data = data->next;
	}
	printf("\n");
}

void clearMark(){
	struct Node *data = node;
	while(data!=NULL){
		data->mark = false;
		data = data->next;
	}
}

struct Node *getNode(char name[100]){
	struct Node *data = node;
	while(data != NULL){
		if(strcmp(name, data->name)==0){
			return data;
		}
		data = data->next;
	}
	return NULL;
}

char *getPath(char nodedata[100]){
	static char data[100];
	strcpy(data, " ");
	struct Edge *edgeData = edge;
	while(edgeData!=NULL){
		if(strcmp(edgeData -> node1 , nodedata)==0){
			struct Node *nodeTest = getNode(edgeData -> node2);
			if(!nodeTest -> mark){
				strcpy(data,edgeData->node2);
				break;
			}
		}
		else if(strcmp(edgeData->node2 , nodedata)==0){
			struct Node *nodeTest = getNode(edgeData->node1);
			if(!nodeTest->mark){
				strcpy(data, edgeData->node2)
				break;
			}
		}
		edgeData = edgeData->next;
	}
	return data;
}

void depthSearch(){
	clearMark();
	if(node==NULL){
		printf("No Graph\n\n");
		return;
	}
	struct Node *data = node;
	data->mark = true;
	printf("visit %s",data->name);
	push(data->name);
	while(!isStackEmpty()){
		char nodeName[100];
		strcpy(nodeName, stack[top]);
		char nodeNameNext[100];
		strcpy(nodeNameNext, getPath(nodeName));
		if(strcmp(nodeNameNext,"")==0){
			pop();
			continue;
		}
		push(nodeNameNext);
		struct Node *nodeNext = getNode(nodeNameNext);
		nodeNext -> mark = true;
		printf("%s ", nodeNameNext);
	}
}

bool isInQ(char dataname[100]){
	for(int i=r; i<=f;i++){
		if(strcmp(dataname,queue[i])==0){
			return true;
		}
	}
	return false;
}

void enqueuePath(char nodedata[100]){
	struct Edge *edgedata = edge;
	while (edgeData!=NULL){
		if(strcmp(edgeData->node1,nodedata)==0){
			struct Node *nodeTest = getNode(edgeData->node2);
			if(!nodeTest->mark){
				if(!isInQ(edgeData->node1)){
					enqueue(edgeData->node1);
				}
			}
		}
		edgeData = edgeData->next
	}
}

void breadthSearch(){
	clearMark();
	if(node==NULL){
		printf("No Grap\n\n");
		return;
	}
	struct Node *data=node;
	data->mark = true;
	printf("visit %s ",data->name);
	enqueuePath(data->name);
	while(!isQEmpty()){
		char data[100];
		strcpy(data,dequeue());
		struct Node *datanode = getNode(data);
		datanode->mark = true;
		printf("%s ",datanode->name);
		enqueuePath(datanode->name );
	}
}

int main(){
	for(;;){
		showMenu();
		switch(getChoice()){
			case 1 : 
				addNode();
				break;
			case 2 :
				listNode();
				break;
			case 3 :
				addEdge();
				break;
			case 4 :
				listEdge();
				break;
			case 5 :
				depthSearch();
				break;
			case 6 :
				breadthSearch();
				break;
			case 7 :
				return 0;
		}
	}	
}

