#include<stdio.h>

int main(){
    int  a = -20;
    unsigned int b = 6;
    ( a+b > 6)? puts(">6") : puts("<6");
    printf("%u",(a+b));


    unsigned int i;
    for( i = 9; i >=0; i--){
        printf("%u\n",i);
    }

    return 0;

}
