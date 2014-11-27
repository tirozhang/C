#include <stdio.h>

int power( int m , int n );

main(){
    int m = 5;
    int n = 2;
    printf("%d",power(m,n));
}

int power( int base , int n){
    int i;
    int sum = 1 ;
    for( i = 0  ; i < n ; ++i ){
        sum = sum * base;
    }
    return sum;
}
