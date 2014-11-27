/******************************************
 * Author: Li Fei
 * Email: lifei_job@yeah.net
 *****************************************/
#include<stdio.h>

int main(){
    int f[] = {1,3,5,7,9};
    int g[] = {2,4,6,8,10};
    int i,j,f_len,g_len,count;
    f_len = g_len = sizeof(f)/sizeof(int);
    count = 0;
    j = g_len - 1;

    for( i= f_len - 1; i >= 0 ; i--){
        for( ; j >= 0; j--){
            if(f[i]>g[j]){
                count += j+1;
                break;
            }
        }
    }
    printf("%d",count);
}

int dominace_count(int f[],int g[],int m ,int n){
    int index_f,index_g;
    int count;
    index_f = index_g = count = 0;
    while(index_f < m && index_g <n){
        if(f[index_f] > f[index_g]){
            count += m - index_f ;
            index_g++;
        }else{
            index_f++;
        }
    }
}
