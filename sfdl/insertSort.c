#include<stdio.h>

int main(){
    int inputArr[] = {3,2,5,1,6};
    int inputArrLen = sizeof(inputArr)/sizeof(int);
    int i,j,temp;
    

    for( i = 1 ;i < inputArrLen ;i++){
        temp = inputArr[i];
        for( j=i-1; j>=0; j-- ){
            if( inputArr[j] >= temp ){
                inputArr[j+1] = inputArr[j];
                inputArr[j]  = temp;
            }else{
                break;
            }
        }
    }

    for( i=0 ; i < inputArrLen; i++){
        printf("%d\n",inputArr[i]);
    }
    return 0;
}
