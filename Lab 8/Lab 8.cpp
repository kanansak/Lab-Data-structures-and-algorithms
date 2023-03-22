#include<stdio.h>
#include<stdbool.h>
#define MAX 20
int data[MAX];
int count = 0;

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

int main(){
	printf("Input '-1' to End Program\n");
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
