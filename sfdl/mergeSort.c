#include<stdio.h>
/*
	归并排序c语言实现
	by zhangtao 20150128
	参考书: 算法导论
	测试环境：CentOS utf8 cc
*/
//输入数列及数组长度
int inputArr[] = {3,2,5,1,6};
int inputArrLen = sizeof(inputArr)/sizeof(int);

/*
	合并函数，复杂度O(n)
	注：未采用《算法导论》中填充数组末位哨兵值（即最大整数）page/17
*/
void merge(int arr[], int start, int mid, int end){
    int i,j,k;
    int leftLen = mid - start + 1;
    int rightLen = end - mid;
    
    int rightArr[leftLen];
    int leftArr[rightLen];
    
    for( i=0; i<leftLen; i++){
        leftArr[i] = arr[start + i];
    }
    
    for( i=0; i<rightLen; i++){
        rightArr[i] = arr[mid + i +1];
    }

    i=0;
    j=0;

    for( k = start ; k <= end && i <leftLen && j<rightLen ; k++){
        if( leftArr[i] <= rightArr[j] ){
            arr[k] = leftArr[i];
            i++;
        }else{
            arr[k] = rightArr[j];
            j++;
        }    
    }

    while( i < leftLen){
        arr[k] = leftArr[i];
        i++;
    }
    while( j < rightLen){
        arr[k] = rightArr[j];
        j++;
    }
}
/*
	归并函数，复杂度O(nlgn)
*/
void mergeSort(int arr[],int start,int end){
    if( end > start){
        int mid = (end + start)/2;
        mergeSort( arr, start, mid);
        mergeSort( arr, mid+1, end);
        merge( arr, start, mid, end);
    }
}
int main(){
    int i;
    mergeSort(inputArr,0,inputArrLen-1);
    
    for( i=0 ; i < inputArrLen; i++){
        printf("%d\t",inputArr[i]);
    }

    return 0;
}
