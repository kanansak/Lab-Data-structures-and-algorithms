#include<stdio.h>
#include<stdbool.h>
int a[10];
int f,r,n;
int data;

bool isFull()
{
	if(f==r+1){
		return true;
	}
	return false;
}
bool isEmpty()
{
	if (r==0){
		return true;
	}
	return false;
}
int Enqueue(int data)
{
	if(isFull()){
		printf("queue overflow error\n");
	}
	else if (isEmpty()){
		f=1;
		r=1;
	}
	else if(r==n)
		r=1; 
	else 
		r = r+1;
	a[r]=data;
}
int Dequeue()
{
	if(isEmpty()){
		printf("queue underflow error\n");
		return -1;
	}
	else 
		data=a[f];
		if (f==r){
			f=0;
			r=0;
		}
		else if (f==n){
			f=1;
		}
		else 
			f=f+1;
		return data;	
}
int peek()
{
	if(isEmpty()){
		printf("queue underflow error\n");
		return -1;
	}
	else 
		data=a[f];
		return data;
}
int input()
{
	printf("Input Number \n");
	for(int i=0;i<10;i++)
	{
		printf("%d.= ",i+1);	
		scanf("%d",&a[i]);	
	}	
	printf("\n");
	for(int i=0;i<10;i++)
	{
		printf("%d.[%d] ",i+1,a[i]);
	}
}	
int Selectmenu()
{
	int n;
	printf("1.Push data\n");
	printf("2.Pop data\n");
	printf("3.Peek data\n");
	printf("00.undo\n");
	printf(">");
	scanf("%d",&n);
	return n;
}	
int main()
{
	for(;;){
		int N=Selectmenu();
		switch(N){
			case 1 : 
				Enqueue(input());
			
				break;
			case 2 : 
				Dequeue();
				break;
			case 3 : 
				peek();
				break;
		}
	}
	
	
}
