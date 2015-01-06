#include<stdio.h>

int main(){
    int a[100],input_num,i,j,temp;

    scanf("%d",&input_num);
    for( i=0; i<input_num; i++)
    {
        scanf("%d",&a[i]);
    }

    for( i=0; i<input_num; i++)
    {
        for( j=(i+1); j<input_num; j++)
        {
            if( a[i] > a[j] ){
               temp = a[i];
               a[i] = a[j];
               a[j] = temp;
            }
        }
        //printf("%d%d%d%d%d\n",a[0],a[1],a[2],a[3],a[4]);
    }

    for( i=0; i<input_num; i++ )
    {
        printf("%d",a[i]);
    }

    getchar();getchar();
    return 0;

}
