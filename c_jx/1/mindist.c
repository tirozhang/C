#include<stdio.h>
#include<limits.h>

int min_distance(int a[],int b[],int m,int n){
    int index_a,index_b,min;
    index_a = index_b = 0;
    min = INT_MAX;

    while( index_a < m && index_b < n ){
        if( a[index_a] > b[index_b] ){
            min = min < (a[index_a] - b[index_b])? min : (a[index_a] - b[index_b]) ;
            index_b++;
        }else if(a[index_a] < b[index_b]){
            min = min < (b[index_b] - a[index_a])? min : (b[index_b] - a[index_a]) ;
            index_a++;
        }else{
            min = 0;
            break;
        }
    }
    return min;

}

int main(){
   int x[] = {1,3,5,7,9};
   int y[] = {2,6,8};

   printf("%d\n",min_distance(x,y,5,3));
}
