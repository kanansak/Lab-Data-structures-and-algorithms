#include "stdio.h"
int main()
{
    int money = 1;
    while (money > 0){
        printf("Input Money = ");
        scanf("%d",&money);
        int bmoney = money;
        int b10 =bmoney/10;
        bmoney=bmoney%10;
        int b5 =bmoney/5;
        bmoney=bmoney%5;
        int b2 =bmoney/2;
        bmoney=bmoney%2;
        int b1 =bmoney;
        printf("10 Bath = %d coins\n 5 Bath = %d coins\n 2 Bath = %d coins\n 1 Bath = %d coins\n",b10 ,b5,b2,b1);
    }
}