#include<stdio.h>

//求最大连续子序列和
int FindGreatestSumOfSubArray(int arry[],int len)
{
    int i,j,max,max_start,max_end,maxCurrent,maxCurrent_start;
    max = arry[0];
    maxCurrent = arry[0];
    max_start = 0;
    maxCurrent_start = 0;
    max_end = 0;

    for( i=1; i<len ; i++ ){
        if( maxCurrent  > 0 ){
            if( max < maxCurrent ){
                max = maxCurrent;
                max_start = maxCurrent_start;
                max_end = i;
            }
            maxCurrent += arry[i];
        }else{
            maxCurrent = arry[i];
            maxCurrent_start = i;
        }
    }
    return max;
}



int main()
{
    int arry[]={1,-2,3,10,-4,7,2,-5};
    int len=sizeof(arry)/sizeof(int);
    int sum = FindGreatestSumOfSubArray(arry,len);
    printf("%d",sum);
}
