#include<stdio.h>

int main(){
    char a[] = "abcdef";
    char *b = "abcdef";

    //printf("%d",sizeof(a));
    //printf("%d",sizeof(b));
    //printf("%d",sizeof(&a));
    printf("%d",sizeof(&a[0]));

    return 1;
}
