#include<iostream>
#include<stdlib.h>
using namespace std;

//求最大连续子序列和
int FindGreatestSumOfSubArray(int arry[],int len)
{
    if(arry==NULL||len<=0)
        return -1;
    int start=0,end=0;//用于存储最大子序列的起点和终点
    int currSum=0;//保存当前最大和
    int greatestSum=-10000;//保存全局最大和
    for(int i=0;i<len;i++)
    {
        if(currSum<0)//如果当前最大和为负数，则舍弃前面的负数最大和，从下一个数开始计算
        {
            currSum=arry[i];
            start=i;
        }
        else
            currSum+=arry[i];//如果当前最大和不为负数则加上当前数
        if(currSum>greatestSum)//如果当前最大和大于全局最大和，则修改全局最大和
        {
            greatestSum=currSum;
            end=i;
        }
    }
    cout<<"最大子序列位置:"<<start<<"--"<<end<<endl;
    return greatestSum;
}



int main()
{
    int arry[]={1,-2,3,10,-4,7,2,-5};
    int len=sizeof(arry)/sizeof(int);
    //cout<<len<<endl;
    int sum= FindGreatestSumOfSubArray(arry,len);
    cout<<"最大子序列和："<<sum<<endl;

    system("pause");
}
