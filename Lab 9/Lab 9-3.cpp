#include<stdio.h>
#include<stdbool.h>

int data[20];
int count = 0;
int i_input=0,i_cal=0,i_arr=1,temp=0,P=0,L=-1,search=0;
void sort();
void Qsort(int start,int end);

void showmenu(){
	printf("\nInput Choice\n");
	printf("1.Input Data\n");
	printf("2.Search Data\n");
	printf("3.Exit\n");
	printf("\nChoice > ");
}
int getChoice(){
	int choice;
	scanf("%d",&choice);
	printf("\n");
	return choice;
}
void swap(int a,int b){
	int t = data[a];
	data[a] = data[b];
	data[b] = t;
}

int inputdata(){
	while(count < 20){ 
		int input;
		printf("Input Data >> ");
		scanf("%d",&input);
		if(input == 0){
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
	
	return count;
	return data[];
}
void sort(){
	Qsort(0,count-1);
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

int InterpolationSearch(int A[], int n, int x){
	
    // search space is `A[low…high]`
    int low = 0, high = n - 1, mid;
 
    while (A[high] != A[low] && x >= A[low] && x <= A[high])
    {
        // estimate mid
        mid = low + ((x - A[low]) * (high - low) / (A[high] - A[low]));
 
        // target value is found
        if (x == A[mid]) {
            return mid;
        }
 
        // discard all elements in the right search space,
        // including the middle element
        else if (x < A[mid]) {
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }
 
    // if a target is found
    if (x == A[low]) {
        return low;
    }
 
    // `x` doesn't exist in the array
    else {
        return -1;
    }
}


int main(){
   for(;;){
   	showmenu();
   		switch(getChoice()){
   			case 1:
   				inputdata();
   				break;
   			case 2: 
   				int target;
   				int n = sizeof(data)/sizeof(data[0]);
   				printf("Search > ");
    			scanf("%d",&target);
				InterpolationSearch(data, n, target);
			   break;
			case 3:
				return 0;	   	
		   }
   }
}
