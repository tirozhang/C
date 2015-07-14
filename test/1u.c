#include<stdio.h>

int main(){
    int nSize = 10;
    int i = 3;
    while ((1U << i) < nSize) {
        i++;
    }
    printf("%d",i);
    printf("%d",1<<i);
    return 0;
}


