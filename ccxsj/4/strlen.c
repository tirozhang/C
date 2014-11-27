#include <stdio.h>

int strlen(char *s){
    char *p  = s;
    while( *p != '\0'){
        p++;
    }
    return p-s;
}

int main(){
   char a[] = "abcdef";
   printf("%d",strlen(a));
}
