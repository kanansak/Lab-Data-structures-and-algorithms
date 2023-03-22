#include<stdio.h>
#include<stdbool.h>
int a[10];
int f,r,n;
int data;

/*int input()
{
	int n1,n2,n3,n4,n5,n6,n7,n8,n9,n10;
	printf("Input Number \n");
		printf("1. = %d\n");	scanf("%d",&n1);
		printf("2. = %d\n");	scanf("%d",&n2);
		printf("3. = %d\n");	scanf("%d",&n3);
		printf("4. = %d\n");	scanf("%d",&n4);
		printf("5. = %d\n");	scanf("%d",&n5);
	
}*/
void push(int data)
{
	if(isFull()){
		return;
	}
	r = r+1;
	a[r]=data;
}
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
		printf("queue overflow error");
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
		printf("queue underflow error");
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
		printf("queue underflow error");
		return -1;
	}
	else 
		data=a[f];
		return data;
}
int main()
{

	//isFull();
	//input();
		int n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0,n10=0;
	printf("Input Number \n");
		printf("1. = %d\n");	scanf("%d",&n1);
		printf("2. = %d\n");	scanf("%d",&n2);
		printf("3. = %d\n");	scanf("%d",&n3);
		printf("4. = %d\n");	scanf("%d",&n4);
		printf("5. = %d\n");	scanf("%d",&n5);
}
