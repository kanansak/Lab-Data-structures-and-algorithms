#include<stdio.h>
void Select_menu()
{
	printf("Select Array\n");
	printf("\t1.Array 1D\n");
	printf("\t2.Array 2D\n");
	printf("\t3.Exit\n");
	printf("Select = ");
}

int input_menu()
{
	int N;	
	scanf("%d",&N);
	return N;
}
void Menu_Type()
{
	printf("Select Type\n");
	printf("\t1.Row Major\n");
	printf("\t2.Column Major\n");
	printf("Select = ");
}
int Select_Type()
{
	int N;
	scanf("%d",&N);
	return N;
}
int Array1D()
{
	int L0,i,L,c,Ans;
	printf("Input Data L0 i L c\n");
	printf("L0 = "); scanf("%d",&L0);
	printf("i [index]  = ");  scanf("%d",&i);
	printf("L [Lower bound]= ");	 scanf("%d",&L);
	printf("c [Data Size]  = ");	 scanf("%d",&c);
	Ans=L0 + (i-L)*c;
	printf("Array 1D = %d\n",Ans);
	printf("=======================\n");
}
int Array2DRow()
{
	int L0,L1,L2,u2,c,i,j,Ans;
	printf("Input Data L0 L1 L2 u2 c i j\n");
	printf("L0 = "); scanf("%d",&L0);
	printf("L1 [Lower Row]   = "); scanf("%d",&L1);
	printf("L2 [Lower Column]= "); scanf("%d",&L2);
	printf("u2 [Uper Column] = "); scanf("%d",&u2);
	printf("c [Data Size]    = ");  scanf("%d",&c);
	printf("i = ");  scanf("%d",&i);
	printf("j = ");  scanf("%d",&j);
	Ans=L0+c*(u2-L2+1)*(i-L1)+c*(j-L2);
	printf("Array 2D = %d\n",Ans);
	printf("=======================\n");
}
int Array2DColumn()
{
	int L0,L1,L2,u1,c,i,j,Ans;
	printf("Input Data L0 L1 L2 u1 c i j\n");
	printf("L0 = "); scanf("%d",&L0);
	printf("L1 [Lower Row]   = "); scanf("%d",&L1);
	printf("L2 [Lower Column]= "); scanf("%d",&L2);
	printf("u1 [Uper Row]    = "); scanf("%d",&u1);
	printf("c [Data Size]    = ");  scanf("%d",&c);
	printf("i = ");  scanf("%d",&i);
	printf("j = ");  scanf("%d",&j);
	Ans = L0+c*(u1-L1+1)*(j-L2)+c*(i-L1);
	printf("Array 2D = %d\n",Ans);
	printf("=======================\n");
}
int main()
{
	for(;;)
	{
		Select_menu();	
		int number = input_menu();
		printf("\n");
			if (number==1)
			{
				printf("Array 1D\n");
				Array1D();
			}
			else if (number==2)
			{
				printf("Array 2D\n");
				Menu_Type();
					int type = Select_Type();	
					if (type==1)
						Array2DRow();
					else if (type==2)
						Array2DColumn();
			}
			else if (number==3)
			{ 
				printf("End Program\n");
				return 0;
			}		
	}
}
