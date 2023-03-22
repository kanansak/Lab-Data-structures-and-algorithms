#include<stdio.h>
#define MAX 10 //Max = final index
int cqueue_arr[MAX]; 
int front = -1;
int rear = -1;

void insert(int item) //Enqueue
{
	if((front == 0 && rear == MAX-1) || (front == rear+1)) //isFull? //check data overflow
	{
		printf("!!!!!! Queue Overflow !!!!!!\n");
		return;
	}
	if(front == -1) //check for move pointer
	{
		front = 0;
		rear = 0;
	}
	else
	{
		if(rear == MAX-1)
			rear = 0;
		else
			rear = rear+1; //change pointer
	}
	cqueue_arr[rear] = item ;
}

void deletion() //Dequeue
{
	if(front == -1) //check isEmpty?  // Queue Underflown
	{
		printf("!!!!!! Queue Underflow !!!!!!\n");
		return ;
	}
	printf("Deleted element : %d \n",cqueue_arr[front]);
	if(front == rear)
	{
		front=-1;
		rear =-1;
	}
	else
	{
		if(front == MAX-1)
			front = 0;
		else
			front = front+1; //Move Pointer
	}
	printf("==================================\n");
}

void display() //Peek
{
	int front_pos = front,rear_pos = rear;
	if(front == -1)
	{
		printf("!!!!!! Queue is emptyn !!!!!!\n"); //isEmpty?
		return;
	}
	printf("Front : %d\n",front_pos);
	printf("Rear  : %d\n",rear_pos);
	printf("Queue elements : ");
	
	if( front_pos <= rear_pos )
		while(front_pos <= rear_pos) //display data until rear > front
		{
			printf("%d ",cqueue_arr[front_pos]);
			front_pos++;
		}
	else
	{
		while(front_pos <= MAX-1) //display data until final Pos
		{
			printf("%d ",cqueue_arr[front_pos]);
			front_pos++;
		}
		front_pos = 0; //set 0 cuz , do the next loop after show all data
		while(front_pos <= rear_pos)
		{
			printf("%d ",cqueue_arr[front_pos]);
			front_pos++;
		}	
	}
	printf("\n==================================\n");
}

int main()
{
	int choice,item,front_pos,rear_pos;
	for(;;)
	{
		printf("\t1.Insert\n");
		printf("\t2.Delete\n");
		printf("\t3.Display\n");
		printf("\t4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		printf("==================================\n");
		switch(choice)
			{
			case 1 :
				printf("Input element : ");
				scanf("%d", &item);
				insert(item);
				break;
			case 2 :
				deletion();
				break;
			case 3:
				display();	
				break;
			case 4:
				return 0;
			default:
				printf("Wrong choice \n\n");
			}
	}
	return 0;
}
