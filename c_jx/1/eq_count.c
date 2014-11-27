#include<stdio.h>

int eq_count(int a[],int b[],int m,int n){
    int index_a,index_b,count;
    index_a = index_b = count = 0;

    while( index_a < m && index_b < n){
        if( a[index_a] == b[index_b]){
            count++;
            index_a++;
            index_b++;
        }else if(a[index_a] > b[index_b]){
            index_b++;
        }else if(a[index_a] < b[index_b]){
            index_a++;
        }
    }
    return count;
}

int main(){
    int f[] = {1,3,5,7,9};
    int g[] = {2,3,6,8,9};
    printf("%d",eq_count(f,g,5,5));
    return 1;
}

