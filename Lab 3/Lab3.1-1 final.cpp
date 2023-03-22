#include<stdio.h>
#include <stdbool.h>
int a[4];
int b[4];
int c[4];
int topA = -1;
int topB = -1;
int topC = -1;
//==================isFull============================
bool isFulla()
{
	if(topA==3){
		return true;
	}
	return false;	
}
bool isFullb()
{
	if(topB==3){
		return true;
	}
	return false;	
}
bool isFullc()
{
	if(topC==3){
		return true;
	}
	return false;	
}
//=============isEmpty=================================
bool isEmptya()
{
	if(topA==-1){
		return true;
	}
	return false;
}
bool isEmptyb()
{
	if(topB==-1){
		return true;
	}
	return false;
}
bool isEmptyc()
{
	if(topC==-1){
		return true;
	}
	return false;
}
//================Push==============================
void pusha(int data)
{
	if(isFulla()){
		return;
	}
	topA = topA+1;
	a[topA]=data;
}
void pushb(int data)
{
	if(isFullb()){
		return ;
	}
	topB = topB+1;
	b[topB]=data;
}
void pushc(int data)
{
	if(isFullc()){
		return ;
	}
	topC = topC+1;
	c[topC]=data;
}
//================Pop==============================
int popa()
{
	if(isEmptya()){
		return -1;
	}	
	int data = a[topA];
	topA = topA-1;
	return data;
}
int popb()
{
	if(isEmptyb()){
		return -1;
	}	
	int data = b[topB];
	topB = topB-1;
	return data;
}
int popc()
{
	if(isEmptyc()){
		return -1;
	}	
	int data = c[topC];
	topC = topC-1;
	return data;
}
//================Peek==============================
int peeka()
{
	if(isEmptya()){
		return -1;
	}
	int data = a[topA];
	return data;
}
int peekb()
{
	if(isEmptyb()){
		return -1;
	}
	int data = b[topB];
	return data;
}
int peekc()
{
	if(isEmptyc()){
		return -1;
	}
	int data = c[topC];
	return data;
}
//================Show==============================
void showA()
{
	if (isEmptya()){
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
	if (isEmptyb()){
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
	if (isEmptyc()){
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
//===============Main==============================
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
				data = peeka();//cheak A Empty?
				if (data == -1){
					break;
				}
				data2 = peekb();//cheak B Empty? 
				if(data2 == -1){
					pushb(popa());// pop data A ,push data to B
				}
				else if(data < data2){
					pushb(popa());
				}
				break;
			case 13:	
				data = peeka();//cheak A Empty?
				if (data == -1){
					break;
				}
				data2 = peekc();//cheak C Empty?
				if(data2 == -1){
					pushc(popa());//pop data A , push data to C
				}
				else if(data < data2){
					pushc(popa());
				}
				break;	
			case 21:	
				data = peekb();//cheak B Empty?
				if (data == -1){
					break;
				}
				data2 = peeka();//cheak A Empty?
				if(data2 == -1){
					pusha(popb());//pop data B , push data to A
				}
				else if(data < data2){
					pusha(popb());
				}
				break;	
			case 23:	
				data = peekb();//cheak B Empty?
				if (data == -1){
					break;
				}
				data2 = peekc();//cheak C Empty?
				if(data2 == -1){
					pushc(popb());//pop data B , push data to C
				}
				else if(data < data2){
					pushc(popb());
				}
				break;
			case 31:	
				data = peekc();//cheak C Empty?
				if (data == -1){
					break;
				}
				data2 = peeka();//cheak A Empty?
				if(data2 == -1){
					pusha(popc());//pop data C , push data to A
				}
				else if(data < data2){
					pusha(popc());
				}
				break;		
			case 32:	
				data = peekc();//cheak C Empty?
				if (data == -1){
					break;
				}
				data2 = peekb();//cheak B Empty?
				if(data2 == -1){
					pushb(popc());
				}
				else if(data < data2){
					pushb(popc());
				}
				break;						
		}
		printf("\n");
	}
	return 0;
}
