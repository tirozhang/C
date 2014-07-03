#include<stdio.h>
/*
	插入排序c语言实现
	by zhangtao 20150128
	参考书: 算法导论
	测试环境：CentOS utf8 cc
*/
int main(){
	//测试数据
	//输入数列
    int inputArr[] = {3,2,5,1,6};
	//数组长度
    int inputArrLen = sizeof(inputArr)/sizeof(int);
    //临时变量
	int i,j,temp;
    
	//循环开始处，进行插入排序。复杂度O(n2)
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
	//打印排序后数据
    for( i=0 ; i < inputArrLen; i++){
        printf("%d\t",inputArr[i]);
    }
	
    return 0;
}
