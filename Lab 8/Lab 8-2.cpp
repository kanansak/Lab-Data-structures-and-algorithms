#include<stdio.h>
#include<stdbool.h>
#define MAX 20
int data[MAX];
int count = 0;

void displayChoice(){
	printf("\nInput Choice \n");
	printf("1.Input \n");
	printf("2.Display  \n");
	printf("3.Exit Program \n\n");
}

int getChoice(){
	int data;
	printf("Enter your choice > ");
	scanf("%d",&data);
	return data;
}
void swap(int a,int b){
	int t = data[a];
	data[a] = data[b];
	data[b] = t;
}

void Qsort(int start,int end){
	if(end <= start){
		return;
	}
	int l = start;
	int h = end;
	bool dir = true;
	int pivot = data[h];
	while (l != h){
		if(dir){
			if(data[l] >= pivot){
				swap(l,h);
				h = h-1;
				dir = false;
			}
			else{
					l = l+1;
				}	
			}
			else{
				if(data[h] < pivot){
					swap(l,h);
					l = l+1;
					dir = true;
			}
			else{
				h = h-1;
			}
		}
	}
	Qsort(start, l-1);
	Qsort(l+1,end);
}

void sort(){
	Qsort(0,count-1);
}
void Input(){
	printf("Input '-1' to Stop Input \n");
	while(count < MAX){ 
		int input;
		printf("Input Data [%d] >> ",count);
		scanf("%d",&input);
		if(input == -1){
			break;
		}
		data[count] = input;
		count = count +1;
	}
}
void Display(){
	int count2 = 0;
	printf("\nData Input >> ");
	while(count2 < count){
		printf("%d ",data[count2]);
		count2 = count2 +1;
	}
	printf("\n");
	printf("Data Quick sort >> ");
	sort();
	count2 = 0;
	while(count2 < count){
		printf("%d ",data[count2]);
		count2 = count2 +1;
	}
	printf("\n");
	printf("Count >> %d\n",count);
}
int main(){
	for(;;){
		displayChoice();
		int choice = getChoice();
		switch(choice){
			case 1 : Input(); break;
			case 2 : Display(); break;			
			case 3 : return 0;
		}
	}
	
}
