#include<stdio.h>
int main()
{
    int a,b,s;
    while(scanf("%d%d",&a,&b)!=EOF){
        if( a <=1000 ){
            printf("%d\n",a);
            s=a+b;
            printf("%d",s);
        }else{
            printf("error");
        }
    }
    return 0;
}

/*
 *if(0<= a <= 100) 错误写法 
 */
