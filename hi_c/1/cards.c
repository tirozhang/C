#include<stdio.h>
int main(){
    char cart_name[3];
    puts("输入牌名：");
    scanf("%2s",cart_name);
    int val = 0;
    if( cart_name[0] == 'K' || cart_name[0] == 'Q' || cart_name[0] == 'J' ){
        val = 10;
    }else if(cart_name[0] == 'A'){  
        val = 11;
    }else{
        val = atoi(cart_name);
    }
    if((val > 2) && (val < 7)){
        puts("计数增加");
    }else if( val == 10){
        puts("计数减少");
    }
    return 0;
}

