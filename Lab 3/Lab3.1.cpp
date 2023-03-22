#include<stdio.h>
#include<stdbool.h>
int a[4];
int b[4];
int c[4];
int topA = -1;
int topB = -1;
int topC = -1;

int isFull(int topA , int topB , int topC )
{
	if(topA==3)
		return topA;
	else if (topB==3)
		return topB;
	else if(topC==3)
		return topC;
	else return 0;			
}
int isEmpty(int topA , int topB , int topC )
{
	if(topA==-1)
		return topA;
	else if (topB==-1)
		return topB;
	else if(topC==-1)
		return topC;
	else return 0;
}
void push(int dataA,int dataB, int dataC)
{
	if(isFull(topA ,topB ,topC)){
		return ;
	}
	topA = topA+1;
	a[topA]=dataA;
	
	topB = topB+1;
	b[topB]=dataB;
	
	topC = topC+1;
	c[topC]=dataC;
}
int pop()
{
	if(isEmpty(topA ,topB ,topC)){
		return -1;
	}	
	int dataA = a[topA];
	topA = topA-1;
	int dataB = b[topB];
	topB = topB-1;
	int dataC = c[topC];
	topC = topC-1;
	return dataA,dataB,dataC;
}
int peek()
{
	if(isEmpty(topA ,topB ,topC)){
		return -1;
	}
	int dataA = a[topA];
	int dataB = b[topB];
	int dataC = c[topC];
	return dataA,dataB,dataC;
}
int main()
{
	//int dataA ,dataB , dataC ;
	push(20,dataB,dataC);
	push(40,50,0);
//	printf("%d\n",peek());
	if(isFull(topA,topB,topC))
		printf("Full");
	else printf("Not")	;
}
