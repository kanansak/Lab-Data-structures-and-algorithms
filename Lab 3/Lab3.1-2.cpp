#include<stdio.h>
int a[4];
int b[4];
int c[4];
int topA = -1;
int topB = -1;
int topC = -1;
//==================isFull============================
int isFulla()
{
	if(topA==3){
		return 1;
	}
	return 0;	
}
int isFullb()
{
	if(topB==3){
		return 1;
	}
	return 0;	
}
int isFullc()
{
	if(topC==3){
		return 1;
	}
	return 0;	
}
//=============isEmpty=================================
int isEmptya()
{
	if(topA==-1){
		return 1;
	}
	return 0;
}
int isEmptyb()
{
	if(topB==-1){
		return 1;
	}
	return 0;
}
int isEmptyc()
{
	if(topC==-1){
		return 1;
	}
	return 0;
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
	if(isFulla()){
		return -1;
	}	
	int data = a[topA];
	topA = topA-1;
	return data;
}
int popb()
{
	if(isFullb()){
		return -1;
	}	
	int data = b[topB];
	topB = topB-1;
	return data;
}
int popc()
{
	if(isFullc()){
		return -1;
	}	
	int data = c[topC];
	topC = topC-1;
	return data;
}
//================Peek==============================
int peeka()
{
	if(isFulla()){
		return -1;
	}
	int data = a[topA];
	return data;
}
int peekb()
{
	if(isFullb()){
		return -1;
	}
	int data = b[topB];
	return data;
}
int peekc()
{
	if(isFullc()){
		return -1;
	}
	int data = c[topC];
	return data;
}
//================Show==============================
int showA()
{
	if (isFulla()){
		printf("   ||   \n");
		return 0;
	}
	for(int i=3;i>=0;i=i-1){	
		switch(a[i]){
			case 0:{
				printf("   |   \n");
				break;
			}
			case 1:{
				printf("   11   \n");
				break;
				}
			case 2:{
				printf("  2222  \n");
				break;
				}	
			case 3:{
				printf(" 333333 \n");
				break;
				}	
			case 4:{
				printf("44444444\n");
				break;
				}
		
		}
	}
}
/*void showB()
{
	for(int i=3;i>=0;i--){	
		switch(b[i]){
			case 4:
				printf("44444444\n");
				break;
			case 3:
				printf(" 333333 \n");
				break;
			case 2:
				printf("  2222  \n");
				break;
			case 1:
				printf("   11   \n");
				break;
			case 0:
				printf("   ||   \n");
				break;
		}
	}
}
/*void showC()
{
	for(int i=3;i>=0;i--){	
		switch(c[i]){
			case 4:
				printf("44444444\n");
				break;
			case 3:
				printf(" 333333 \n");
				break;
			case 2:
				printf("  2222  \n");
				break;
			case 1:
				printf("   11   \n");
				break;
			case 0:
				printf("   ||   \n");
				break;
		}
	}
}*/
//================Main==============================
int main()
{
	pusha(4);
	pusha(3);
	pusha(2);
	pusha(1);
	
	pushb(0);
	pushb(0);
	pushb(0);
	pushb(0);
	
	pushc(0);
	pushc(0);
	pushc(0);
	pushc(0);
	for(;;){
		showA();printf("\n");
	//	showB();printf("\n");
	//	showC();
	/*int key = getCommand();
	switch(key){
		case 0: return 0;
		case 12:
	}*/
		 
	}
}
