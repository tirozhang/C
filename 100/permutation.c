#include<stdio.h>

void premutation( char *pStr, char *begin ){
    
    if( pStr == NULL || begin == NULL ){
        return;
    }

    if( *begin == '\0' ){
        printf("%s\n",pStr);
        return;
    }else{
        char *temp;
        for( temp = begin; *temp != '\0'; temp++ ){
            char ch = *begin;
            *begin = *temp;
            *temp = ch;
            premutation( pStr, begin+1 );
            ch = *begin;
            *begin = *temp;
            *temp = ch;
        }
        
    }

}

int main(){
    char pStr[] = "abc";
    premutation(pStr,pStr);
    return 0;
}
