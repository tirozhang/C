#include<stdio.h>

int main(){
    int f[] = {1,3,5,7,9};
    int g[] = {2,4,6,8,10};
    int i,j,f_len,g_len,count;
    f_len = g_len = sizeof(f)/sizeof(int);
    count = 0;

    for( i= f_len - 1; i >= 0 ; i--){
        for( j = g_len - 1; j >= 0; j--){
            if(f[i]>g[j]){
                count += j+1;
                break;
            }
        }
    }
    printf("%d",count);
}
