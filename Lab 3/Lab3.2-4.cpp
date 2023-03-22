#include <stdio.h>
#include<stdbool.h>
#define SIZE 5
int items[SIZE];
int front = -1, rear = -1;

int input()
{
	printf("Input Number \n");
	for(int i=0;i<10;i++)
	{
		printf("%d.= ",i+1);	
		scanf("%d",&items[i]);	
	}	
}	
// Check if the queue is full
bool isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) {
	return true;
  }	
  return false;
}

// Check if the queue is empty
bool isEmpty() {
  if (front == -1) {
	return true;
  }
  return false;
}
// Adding an element
void enQueue(int element) {
  if (isFull())
    printf("\n Queue overflow error!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Inserted -> %d", element);
  }
}
// Removing an element
int deQueue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue underflow error !! \n");
    return -1;
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    // Q has only one element, so we reset the 
    // queue after dequeing it. ?
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}
int peek()
{
	int item,front,element;
	if(isEmpty()){
		printf("queue underflow error\n");
		return -1;
	}
	else 
		element=item[SIZE];
		return element;
}
// Display the queue
void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d \n", rear);
  }
}
int main()
{
	display();
	enQueue(input());
	
}

