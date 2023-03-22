#include <stdio.h>
int main()
{
    int C1;
    int L,FIRSTSCORE,U,KNOW,KNOWSCORE,Csize,TARGET,TARGETSCORE;
    int LOC_L1,LOC_L2,LOC_U1,LOC_U2,C,LOC_M,LOC_N,LOC_I,LOC_J,I,J,L0,RowMajorOrder,ColumnMajorArray;
    while(C1!=3)
    {
        printf("Please select\n[ 1 ] Array 1D\n[ 2 ] Array 2D\n[ 3 ] Exit Program\nYou choose : ");
        scanf("%d",&C1);
        switch (C1)
        {
        case 1:
            printf("\nArray 1D\nPlease enter details\n");
            printf("First Location : ");
            scanf("%d",&L);
            printf("Last Location : ");
            scanf("%d",&U);
            printf("Target Location : ");
            scanf("%d",&TARGET);
            printf("Data Size : ");
            scanf("%d",&Csize);
            printf("Know Location : ");
            scanf("%d",&KNOW);
            printf("Know Score Location : ");
            scanf("%d",&KNOWSCORE);
            if (L == KNOW)
            {
                TARGETSCORE =KNOWSCORE + ((TARGET - L) * Csize);
                printf("Array [%d] : %d\n\n" ,TARGET ,TARGETSCORE);
            }else if (L != KNOW)
            {
                FIRSTSCORE = KNOWSCORE - ((KNOW - L) * Csize);
                TARGETSCORE = FIRSTSCORE + ((TARGET - L) * Csize);
                printf("Array [%d] : %d\n\n" , TARGET , TARGETSCORE);
            }
            break;
            case 2:
            printf("\nArray 2D\nPlease enter details\n");
            printf("Lower Row : ");
            scanf("%d",&LOC_L1);
            printf("Uper Row : ");
            scanf("%d",&LOC_U1);
            printf("Lower Column : ");
            scanf("%d",&LOC_L2);
            printf("Uper Column : ");
            scanf("%d",&LOC_U2);
            LOC_M=(LOC_U1 -  LOC_L1 + 1);
            LOC_N=(LOC_U2 - LOC_L2 + 1);
            C=(LOC_M * LOC_N);
            printf ("DATASIZE : %d\n" ,C);
            printf ("Choose I :");
            scanf("%d",&LOC_I);
            printf ("Choose J :");
            scanf("%d",&LOC_J);
            I=(LOC_I - LOC_L1 + 1);
            J= (LOC_J - LOC_L2 + 1);
            printf("Address :");
            scanf("%d" ,&C);
           RowMajorOrder=(L0+C*LOC_N *(LOC_I - LOC_L1)+(C*LOC_J - LOC_L2));
           printf("Row Major Order : %d \n" ,RowMajorOrder);
           ColumnMajorArray=(L0+C*LOC_M *(LOC_J - LOC_L2)+(C*LOC_I - LOC_L1));
           printf("Column Major Array : %d \n" ,ColumnMajorArray);
            break;
        default:
            printf("\nWhat?\n\n");
            break;
        }
    }
}
