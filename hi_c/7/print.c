#include<stdio.h>
#include<stdarg.h>

void print_int(int args,...){
    va_list ap;
    va_start(ap,args);
    int i;
    for( i = 0 ; i < args ; i++){
        printf("%d",va_arg(ap,int));
    }
    va_end(ap);
}
int main(){
    print_int(3,4,5,6);
    return 0;
}
