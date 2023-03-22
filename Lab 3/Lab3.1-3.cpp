#include<stdio.h>
#include<stdbool.h>
#define Size 4
int a[Size];
int b[Size];
int c[Size];
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
void pusha(int data)
{
	if(isFull(topA ,topB ,topC)){
		return;
	}
	topA = topA+1;
	a[topA]=data;
}
void pushb(int data)
{
	if(isFull(topA ,topB ,topC)){
		return ;
	}
	topB = topB+1;
	b[topB]=data;
}
void pushc(int data)
{
	if(isFull(topA ,topB ,topC)){
		return ;
	}
	topC = topC+1;
	c[topC]=data;
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
void showA()
{
	if (isEmpty(topA ,topB ,topC)){
		printf("\t   ||   \n");
		return ;
	}
	for(int i=topA;i>=0;i--){	
		switch(a[i]){
			case 4:
				printf("\t44444444\n");
				break;
			case 3:
				printf("\t 333333 \n");
				break;
			case 2:
				printf("\t  2222  \n");
				break;
			case 1:
				printf("\t   11   \n");
				break;
			case 0:
				printf("\t   |    \n");
				break;
		}
	}
}
void showB()
{
	if (isEmpty(topA ,topB ,topC)){
		printf("\t   ||   \n");
		return ;
	}
	for(int i=topB;i>=0;i--){	
		switch(b[i]){
			case 4:
				printf("\t44444444\n");
				break;
			case 3:
				printf("\t 333333 \n");
				break;
			case 2:
				printf("\t  2222  \n");
				break;
			case 1:
				printf("\t   11   \n");
				break;
			case 0:
				printf("\t   |    \n");
				break;
		}
	}
}
void showC()
{
	if (isEmpty(topA ,topB ,topC)){
		printf("\t   ||   \n");
		return ;
	}
	for(int i=topC;i>=0;i--){	
		switch(c[i]){
			case 4:
				printf("\t44444444\n");
				break;
			case 3:
				printf("\t 333333 \n");
				break;
			case 2:
				printf("\t  2222  \n");
				break;
			case 1:
				printf("\t   11   \n");
				break;
			case 0:
				printf("\t   |    \n");
				break;
		}
	}
}
int getCommand()
{
	int data;
	scanf("%d",&data);
	return data;
}
int main()
{
	pusha(4);
	pusha(3);
	pusha(2);
	pusha(1);
	printf("First Number is Disc || Last Number is Row\n");
	for(;;)
	{
		showA();printf("\n");
		showB();printf("\n");
		showC();printf("\n");	
		printf("Command = ");
		int key = getCommand();
		int data,data2;
		switch(key)
		{
			case 0:
				return 0;
			case 12:	
				data = peek(topA ,topB ,topC);//cheak A Empty?
				if (data == -1){
					break;
				}
				data2 = peek(topA ,topB ,topC);//cheak B Empty? 
				if(data2 == -1){
					pushb(pop(topA ,topB ,topC));// pop data A ,push data to B
				}
				else if(data < data2){
					pushb(pop(topA ,topB ,topC));
				}
				break;
			case 13:	
				data = peek(topA ,topB ,topC);//cheak A Empty?
				if (data == -1){
					break;
				}
				data2 = peek(topA ,topB ,topC);//cheak C Empty?
				if(data2 == -1){
					pushc(pop(topA ,topB ,topC));//pop data A , push data to C
				}
				else if(data < data2){
					pushc(pop(topA ,topB ,topC));
				}
				break;	
			case 21:	
				data = peek(topA ,topB ,topC);//cheak B Empty?
				if (data == -1){
					break;
				}
				data2 = peek(topA ,topB ,topC);//cheak A Empty?
				if(data2 == -1){
					pusha(pop(topA ,topB ,topC));//pop data B , push data to A
				}
				else if(data < data2){
					pusha(pop(topA ,topB ,topC));
				}
				break;	
			case 23:	
				data = peek(topA ,topB ,topC);//cheak B Empty?
				if (data == -1){
					break;
				}
				data2 = peek(topA ,topB ,topC);//cheak C Empty?
				if(data2 == -1){
					pushc(pop(topA ,topB ,topC));//pop data B , push data to C
				}
				else if(data < data2){
					pushc(pop(topA ,topB ,topC));
				}
				break;
			case 31:	
				data = peek(topA ,topB ,topC);//cheak C Empty?
				if (data == -1){
					break;
				}
				data2 = peek(topA ,topB ,topC);//cheak A Empty?
				if(data2 == -1){
					pusha(pop(topA ,topB ,topC));//pop data C , push data to A
				}
				else if(data < data2){
					pusha(pop(topA ,topB ,topC));
				}
				break;		
			case 32:	
				data = peek(topA ,topB ,topC);//cheak C Empty?
				if (data == -1){
					break;
				}
				data2 = peek(topA ,topB ,topC);//cheak B Empty?
				if(data2 == -1){
					pushb(pop(topA ,topB ,topC));
				}
				else if(data < data2){
					pushb(pop(topA ,topB ,topC));
				}
				break;						
		}
		printf("\n");
	}
	return 0;
	
}
