#include<stdio.h>

int inputArr[] = {3,2,5,1,6};
int inputArrLen = sizeof(inputArr)/sizeof(int);


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
        arr[k] = leftArr[j];
        j++;
    }
}

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
        printf("%d\n",inputArr[i]);
    }

    return 0;
}
