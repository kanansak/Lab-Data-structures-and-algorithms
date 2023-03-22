#include<stdio.h>
#include<stdbool.h>

int data[20];
int count = 0;
int i, j,  temp;

void showmenu(){
	printf("\nInput Choice\n");
	printf("1.Input Data\n");
	printf("2.Display Data\n");
	printf("3.Search Data\n");
	printf("4.Exit\n");
	printf("\nChoice > ");
}
int getChoice(){
	int choice;
	scanf("%d",&choice);
	printf("\n");
	return choice;
}

int getElement(){
	printf("Enter Number of Element >  ");
   scanf("%d",&count);
   for(i=0;i<count;i++){
   	printf("Enter Element [%d] > ",i+1);
   	scanf("%d",&data[i]);
	}
   //Insertion Sort
	for(i=1;i<count;i++){
      temp=data[i];
      j=i-1;
      while((temp<data[j])&&(j>=0)){
         data[j+1]=data[j];
         j=j-1;
      }
      data[j+1]=temp;
   }
   printf("\n\n");
}
void displayElement(){
	printf("Order of Sorted elements: ");
   for(i=0;i<count;i++){
   	printf("%d  ",data[i]);
	}
	printf("\n\n");
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
   				getElement();
   				break;
   			case 2: 
   				displayElement();
			   break;
			case 3:
				
				break;
			case 4:	
				return 0;	   	
		   }
   }
}
