#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 99

struct Vertex {
   char label;
   bool visited;
};

//queue variables

int queue[MAX];
int rear = -1;
int front = 0;
int queueItemCount = 0;

//stack variables

int stack[MAX]; 
int top = -1; 

//graph variables

//array of vertices
struct Vertex* lstVertices[MAX];

//adjacency matrix
int adjMatrix[MAX][MAX];

//vertex count
int vertexCount = 0;

//queue functions

void showMenu()
{
	printf("\n");
    printf("-----Graph-----\n");
    printf("1 Insert Vertices\n");
    printf("2 Insert Edges\n");
    printf("3 Display\n");
    printf("4 Exit\n\n");
    printf("choice -> ");
}
int getChoice(){
	int data;
	scanf("%d",&data);
	return data;
}
void insert(int data) {
   queue[++rear] = data;
   queueItemCount++;
}

int removeData() {
   queueItemCount--;
   return queue[front++]; 
}

bool isQueueEmpty() {
   return queueItemCount == 0;
}

//stack functions

void push(int item) { 
   stack[++top] = item; 
} 

int pop() { 
   return stack[top--]; 
} 

int peek() {
   return stack[top];
}

bool isStackEmpty() {
   return top == -1;
}

//graph functions

//add vertex to the vertex list
void addVertex() {
  	struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
   	printf("Input data > ");
	scanf("%s",&label);
   	vertex->label = label;  
   	vertex->visited = false;     
   	lstVertices[vertexCount++] = vertex;
}

//add edge to edge array
void addEdge(int start,int end) {
   adjMatrix[start][end] = 1;
   adjMatrix[end][start] = 1;
}

//display the vertex
void displayVertex(int vertexIndex) {
   printf("%s ",lstVertices[vertexIndex]->label);
}       

//get the adjacent unvisited vertex
int getAdjUnvisitedVertex(int vertexIndex) {
   int i;

   for(i = 0; i < vertexCount; i++) {
      if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
         return i;
      }
   }

   return -1;
}

void breadthFirstSearch() {
   int i;

   //mark first node as visited
   lstVertices[0]->visited = true;

   //display the vertex
   displayVertex(0);   

   //insert vertex index in queue
   insert(0);
   int unvisitedVertex;

   while(!isQueueEmpty()) {
      //get the unvisited vertex of vertex which is at front of the queue
      int tempVertex = removeData();   

      //no adjacent vertex found
      while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) {    
         lstVertices[unvisitedVertex]->visited = true;
         displayVertex(unvisitedVertex);
         insert(unvisitedVertex);               
      }
		
   }   

   //queue is empty, search is complete, reset the visited flag        
   for(i = 0;i<vertexCount;i++) {
      lstVertices[i]->visited = false;
   }    
}

void depthFirstSearch() {
   int i;

   //mark first node as visited
   lstVertices[0]->visited = true;

   //display the vertex
   displayVertex(0);   

   //push vertex index in stack
   push(0);

   while(!isStackEmpty()) {
      //get the unvisited vertex of vertex which is at top of the stack
      int unvisitedVertex = getAdjUnvisitedVertex(peek());

      //no adjacent vertex found
      if(unvisitedVertex == -1) {
         pop();
      } else {
         lstVertices[unvisitedVertex]->visited = true;
         displayVertex(unvisitedVertex);
         push(unvisitedVertex);
      }
   }

   //stack is empty, search is complete, reset the visited flag        
   for(i = 0;i < vertexCount;i++) {
      lstVertices[i]->visited = false;
   }        
}


int main() {
	for(;;){
		int i, j , e1,e2,r=0;
		char data[99];
		showMenu();
	
		switch(getChoice()){
			for(r=0;r<99;r++){
			case 1:  
				addVertex();
                break;
            case 2:
            	printf("Input edge1 > ");
	 			scanf("%d",&e1);
	 			printf("Input edge2 > ");
	 			scanf("%d",&e2);
	 			addEdge(e1,e2);  
                break;
            case 3:
            	printf("\nBreadth First Search: ");
			   	breadthFirstSearch();
			   	printf("\n");
			   
				printf("Depth First Search: ");
			   	depthFirstSearch();
			   	printf("\n");
			   	break;
			case 4 :   	
            	return 0;	
     		}
  		}
	   for(i = 0; i<MAX; i++){ // set adjacency {
	      for(j = 0; j<MAX; j++) // matrix to 0
	         adjMatrix[i][j] = 0;
	
		}
	}	   
}

