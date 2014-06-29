#include<stdio.h>
#include<stdlib.h>

int compare_scores(const void *score_a,const void *score_b){
    int a = *(int*)score_a;
    int b = *(int*)score_b;
    return b-a;
}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    int i = 0;
    qsort(arr,10,sizeof(int),compare_scores);

    for(i=0;i<10;i++){
        printf("%d\n",arr[i]);
    }
    return 0;

}
