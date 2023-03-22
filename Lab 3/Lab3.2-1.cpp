#include<stdio.h>

int main()
{	
	int a[10];
	printf("Input Number \n");
	for(int i=0;i<10;i++)
	{
		printf("%d.= ",i+1);	
		scanf("%d",&a[i]);	
	}	
	printf("\n");
	for(int i=0;i<10;i++){
		printf("%d.[%d] ",i+1,a[i]);
	}

}
