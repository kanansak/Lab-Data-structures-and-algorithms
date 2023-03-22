#include<stdio.h>
int main()
{
	int money,n=1;
	while(n!=0){
		printf("Input Money = ");
		scanf("%d",&money);
		int b10,b5,b2,b1;
			b10=money/10;
			money=money%10;
			b5=money/5;
			money=money%5;
			b2=money/2;
			money=money%2;
			b1=money;
	}
	printf("%d\n%d\n%d\n%d",b10,b5,b2,b1);	
}

