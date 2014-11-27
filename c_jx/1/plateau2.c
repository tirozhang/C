#include<stdio.h>
#define MAX 100

int arr[MAX];


int main(){

    int c,i,j,maxlen,maxnum;
    i = 0;

    while((c = getchar()) != EOF && c != '\n' ){
        arr[i++] = c - '0';
    }

    maxlen = 1;
    for( j=1 ; j < i && (j+maxlen) < i; j++){
        if(arr[j] == arr[j+maxlen]){
            //error 此处不对
            maxlen++;
        }
    }
    printf("%d",maxlen);
    
}
