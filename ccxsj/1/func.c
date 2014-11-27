#include <stdio.h>
#define MAX 100

int max;
char line[MAX];
char longest[MAX];

int getline(void);
void copy(void);

main(){
    int len;
    extern int max;
    extern char longest[];

    max = 0 ;
    while( (len = getline()) > 0 ){
        if(len > max){
            max = len;
            copy();
        }
    }
    if( max > 0 ){
        printf("%s",longest);
    }
    return 0;
}

int getline(void){
    int c,i;
    extern char line[];
    for( i = 0 ; i < MAX - 1 && (c =getchar()) != EOF && c != '\n'; ++i ){
        line[i] = c;      
    }
    if( c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return  i;
}
void copy(){
    int  i ;
    extern char line[],longest[];

    for( i = 0 ; line[i] != '\0' ; ++i){
        longest[i] = line[i];
    }
}

