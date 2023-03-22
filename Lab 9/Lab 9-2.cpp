#include<stdio.h>
int i_input=0,i_cal=0,i_arr=1,temp=0,P=0,L=-1,search=0;
int count=100;
int data[count];
int x_arr[count+1];

void showmenu(){
	printf("Input Choice");
	printf("1.Input Data");
	printf("2.Display Data");
	printf("3.Search Data");
	printf("4.Exit");
}
int getChoice(){
	int choice;
	scanf("%d",&choice);
	printf("\n");
	return choice;
}
void search(){
	do
    {
        if(i_cal < count-1 && data[i_cal] > data[i_cal+1])
        {
            temp = data[i_cal+1];
            data[i_cal+1] = data[i_cal];
            data[i_cal] = temp;
            i_cal = 0;
        }
        else
        {
            i_cal++;
        }
    }while(i_cal < count);
    printf("Sort : ");
    for(i_cal=0; i_cal<count; i_cal++)
    {
        printf("%d ", data[i_cal]);
    }
    printf("\n");
    //????????? Count
    printf("Count : %d\n",count);
    //??????
    printf("Search : ");
    scanf("%d",&search);
    while (data[P]!=search)
    {
        L++;
        if(L>count)
        {
            printf("Unknow Number In Array!!!\n\n");
            P=1;
            data[P]=search;
        }
        else
        {
            P=(L)+(((data[L])*(count-L))/(data[count+1]-L));
            L = P;
            if(data[P]==search)
            {
                P++;
                printf("Interpolation Search : %d\n\n",P);
                P--;
            }
        }
        
    }
    if(data[0]==search)
    {
        printf("Interpolation Search : 1\n\n");
    }
    }
}
int main()
{
   for(;;){
   		switch(getChoice()){
   			case 1:
   				
   				break;
   			case 2: 
			   
			   break;
			case 3:
				search();
				break;
			case 4:
			
				return 0;	   	
		   }
   }
}
