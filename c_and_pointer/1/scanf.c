#include<stdio.h>

int main(){
    int a[100];
    int num = 0;
    int ch ;
    while( scanf("%d", &a[num]) == 1 && a[num] > 0 ){
        num++;
    }

    while( (ch = getchar()) != EOF && ch != '\n' ){
        printf("%d",ch);
    }
    

}
