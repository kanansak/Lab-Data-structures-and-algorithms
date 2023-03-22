#include<stdio.h>
int Select_menu()
{ 	
	int N;
	printf("Select Array\n");
	printf("\t1.Array 1D\n");
	printf("\t2.Array 2D\n");
	printf("\t3.Exit\n");
	printf("Select Number = ");	
	scanf("%d",&N);
	printf("=======================\n");
	return N;
}
int Array1D()
{
	int L0,i,L,c,Ans;
	printf("L0 = "); scanf("%d",&L0);
	printf("i [index] = ");  scanf("%d",&i);
	printf("L [Lower bound]= "); scanf("%d",&L);
	printf("c [Data Size]  = "); scanf("%d",&c);
	Ans=L0 + (i-L)*c;
	printf("Array [%d] = %d\n",i,Ans);
	printf("=======================\n");
}
int Array2D()
{
	int L0,L1,L2,u1,u2,c,i,j,AnsR,AnsC;
	printf("L0 = "); scanf("%d",&L0);
	printf("L1 [Lower Row]   = "); scanf("%d",&L1);
	printf("L2 [Lower Column]= "); scanf("%d",&L2);
	printf("u1 [Upper Row]   = "); scanf("%d",&u1);
	printf("u2 [Upper Column]= "); scanf("%d",&u2);
	printf("c  [Data Size]   = "); scanf("%d",&c);
	printf("i = ");  scanf("%d",&i);
	printf("j = ");  scanf("%d",&j);
	AnsR =L0+c*(u2-L2+1)*(i-L1)+c*(j-L2);//Row
	AnsC =L0+c*(u1-L1+1)*(j-L2)+c*(i-L1);//Column
	printf("Array Row Major = %d\n",AnsR);
	printf("Array Column Major = %d\n",AnsC);
	printf("=======================\n");
}
int main()
{
	for(;;)
	{
		int number = Select_menu();	
		if (number==1)	{
			printf("Array 1D\n");
			Array1D();
		}
		else if (number==2)	{
			printf("Array 2D\n");
			Array2D();
		}
		else if (number==3) { 
			printf("End Program\n");
			return 0;
		}		
	}
}
