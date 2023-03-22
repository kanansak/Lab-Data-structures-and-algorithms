#include<stdio.h>
main()
{
    int choice,i_d=0,i_0=0,i_f=0,i_n=-1,i_e=-1,i_s=0,i_b=0,n=-1,full_i=0,full_j=-1,i_x=0,m_node=0,ii,i_df;
    char s_node;
    char node[100][100],depth[100],breadth[100],i[100],j[100];
    int ID=0;
    char DF[100]={};
    int I_DF=0;
    for(;;)
    {
    printf("Menu\n[ 1 ]Insert Vertices\n[ 2 ]Insert Edges\nYour Choice : ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("<---Insert Vertices--->\n");
        i_n++;
        printf("Insert Vertices : ");
        scanf("%s",&node[i_n][0]);
        DF[I_DF]=node[i_n][0];
        printf("Node : ");
        for(i_0=0;i_0<=i_n;i_0++)
        {
            printf("[%c] ",node[i_0][0]);
        }
        printf("\n\n");
        break;
    case 2:
        printf("<---Insert Edge--->\n");
        n=-1;
        printf("Select Node : ");
        scanf("%s",&s_node);
        while(s_node!=node[n][0])
        {
            n++;
        }
        printf("Connet [%c] To : ",node[n][0]);
        scanf("%s",&s_node);
        i_0=3;
        while(node[n][i_0]!=0)
            {
                i_0++;
            }
        node[n][i_0]=s_node;
        //?????????------------------------------------------------->
        printf("Adjacency List\nDirected Unweighted Graph\n");
        i_b=0;
        i_s=0;
        i_d=0;
        full_i=0;
        full_j=0;
        breadth[0]=node[i_b][0];
        while(node[i_s][0]!=0)
        {
            printf("[%c] ",node[i_s][0]);
            i[full_i]=node[i_s][0];
            full_i++;
            i_0=3;
            while(node[i_s][i_0]!=0)
            {
                printf("---> [%c] ",node[i_s][i_0]);
                j[full_j]=node[i_s][i_0];
                full_j++;
                if(node[i_s][i_0]!=breadth[i_b])
                {
                    i_b++;
                    breadth[i_b]=node[i_s][i_0];
                }
                
                i_0++;
            }
            i_s++;
            printf("\n");
        }
        //?????????------------------------------------------------->
        printf("Breadth First Search : ");
        for(i_0=0;i_0<99;i_0++)
        {
            printf("%c ",breadth[i_0]);
        }
        printf("\n");
        printf("Depth First Search : ");
        
        
        
        
        printf("\n");
        break;
    }
    }
}
