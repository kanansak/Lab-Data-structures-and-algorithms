#include <stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 12

int h[TABLE_SIZE]={NULL};
void displayChoice(){
	printf("\nInput Choice \n");
	printf("1.Insert  \n");
	printf("2.Display  \n");
	printf("3.Search \n");
	printf("4.Exit  \n");
}
int getChoice(){
	int data;
	printf("\nEnter your choice > ");
	scanf("%d",&data);
	return data;
}
void insert(){
	int key,index,i,flag=0,hkey,hash2;
	printf("\nenter a value to insert into hash table > ");
	scanf("%d",&key);
	hkey=key%TABLE_SIZE; //h(x) = x mod 30
	hash2 = 3-(key %3); //h2(x) = 7 - ( x mod 7 
	for(i=0;i<TABLE_SIZE;i++){
    	index=(hkey+i*hash2)%TABLE_SIZE;
    	if(h[index] == NULL){
        	h[index]=key;
        	break;
    	}
 	}
	if(i == TABLE_SIZE)
    	printf("\nelement cannot be inserted\n");
}
void search(){
	int key,index,i,flag=0,hash2,hkey;
	printf("\nenter search element > ");
	scanf("%d",&key);
	hkey=key%TABLE_SIZE;
	hash2 = 7-(key %7);
	for(i=0;i<TABLE_SIZE; i++){
    	index=(hkey+i*hash2)%TABLE_SIZE;
    	if(h[index]==key){
      		printf("value is found at index %d",index);
      		break;
    	}
  	}
	if(i == TABLE_SIZE)
    	printf("\n value is not found\n");
}
void display(){
	int i;
	printf("\nelements in the hash table are \n");
	for(i=0;i< TABLE_SIZE; i++)
		printf("\nindex [%d]   value > %d",i,h[i]);
}
main(){
    for(;;){
    	displayChoice();
        switch(getChoice()){
            case 1: insert(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4:return 0;
        }
    }
}
