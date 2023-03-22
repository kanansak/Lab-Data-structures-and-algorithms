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
	int N[4],i,Ans;
	printf("Input Data [L0 i L c]\n"); // L0=[0]  i=[1]  L=[2]  c=[3]
	for(i=0;i<4;i++)
	{	
		scanf("%d",&N[i]);
	}
		Ans=N[0] + (N[1]-N[2])*N[3]; //Ans=L0 + (i-L)*c;
		printf("Array 1D = %d\n",Ans);
		printf("=======================\n");	
		
}
int Array2DRow()
{
	int N[7],i,Ans;
	printf("Input Data L0 L1 L2 u2 c i j\n"); // L0=N[0]  L1=N[1]  L2=N[2]  u2=N[3]  c=N[4]  i=N[5]  j=N[6]
	for(i=0;i<7;i++)
	{	
		scanf("%d",&N[i]);
	}
	Ans= N[0]+N[4]*(N[3]-N[2]+1)*(N[5]-N[1])+N[4]*(N[6]-N[2]); // Ans=L0+c*(u2-L2+1)*(i-L1)+c*(j-L2);
	printf("Array 2D = %d\n",Ans);
	printf("=======================\n");
}
int Array2DColumn()
{
	int N[7],i,Ans;
	printf("Input Data L0 L1 L2 u1 c i j\n");//L0=N[0]  L1=N[1]  L2=N[2]  u1=N[3]  c=N[4]  i=N[5]  j=N[6]
	for(i=0;i<7;i++)
	{	
		scanf("%d",&N[i]);
	}
	Ans = N[0]+N[4]*(N[3]-N[1]+1)*(N[6]-N[2])+N[4]*(N[5]-N[1]);//Ans = L0+c*(u1-L1+1)*(j-L2)+c*(i-L1);
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
					{
						Array2DRow();
					}
					else if (type==2)
					{
						Array2DColumn();
					}
			}
			else if (number==3)
			{ 
				printf("End Program\n");return 0;
			}		
	}
}
