#include<stdio.h>
#define MAX 100

int arr[MAX];


int main(){

    int c,i,j,maxlen,maxnum,nownum,nowlen;
    i = 0;

    while((c = getchar()) != EOF && c != '\n' ){
        arr[i++] = c - '0';
    }

    maxlen = 1;
    nowlen = 1;
    maxnum = arr[0];
    nownum = arr[0];
    for( j=1 ; j < i;j++){
        if(nownum == arr[j]){
            nowlen++; 
        }else{
            if(nowlen > maxlen){
                maxlen = nowlen;
                maxnum = nownum;
            }
            nownum = arr[j];
            nowlen = 1;
        }
    }
    printf("%d:%d",maxnum,maxlen);
    
}
