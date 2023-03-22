#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Global Variable
int i, j, count, temp, number[20],val,pos;

void displayChoice(){
	printf("\nInput Choice \n");
	printf("1.Get elements  \n");
	printf("2.Display element  \n");
	printf("3.Search element\n");
	printf("4.Exit Program \n\n");
}

int getChoice(){
	int data;
	printf("Enter your choice > ");
	scanf("%d",&data);
	return data;
}

int getElement(){
	printf("Enter Number of Element >  ");
    scanf("%d",&count);
    for(i=0;i<count;i++){
   		printf("Enter Element [%d] > ",i);
   		scanf("%d",&number[i]);
	}
   //Insertion Sort
	for(i=1;i<count;i++){
      temp=number[i];
      j=i-1;
      while((temp<number[j])&&(j>=0)){
         number[j+1]=number[j];
         j=j-1;
      }
      number[j+1]=temp;
   }
   printf("\n\n");
   return count;
}

void displayElement(){
	printf("\nCount > %d \n",count);
	printf("Order of Sorted elements : ");
   for(i=0;i<count;i++){
   	printf("%d  ",number[i]);
	}
	printf("\n\n");
}

int Search(int number[], int low, int high, int val){
	int mid;
	while(low <= high)
	{
		mid=low + (high-low) * ((val - number[low]) / (number[high] - number[low]));
		if(val == number[mid])
			return mid;
		if(val < number[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
int main(){
	for(;;){
		displayChoice();
		int choice = getChoice();
		switch(choice){
			case 1 : getElement(); break;
				printf("\n");
			case 2 : displayElement(); break;
			case 3 : 
					printf("\nEnter the key element that has to be search : ");
					scanf("%d", &val);
					pos = Search(number,0,count-1,val);
					if(pos == -1)
						printf("\n %d is not found in the array\n", val);
					else
						printf("\n %d is found in the array at position array [%d]\n", val, pos);
					break;
			case 4 : return 0;
		}
	}
}
