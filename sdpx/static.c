#include <stdio.h>

static int i;

void test(){
    static int j = 0;
    j++;
    printf("%d\n",j);
}

void test2(){
    int i = 0;
    i++;
    printf("%d\n",i);
}

int main(){
    int k;
    for( k=0 ; k<10 ; k++){
        test(); 
        test2(); 
    }
}
