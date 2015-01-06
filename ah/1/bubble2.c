#include<stdio.h>

typedef struct std
{
    char name[10];
    char score;
} Std;

int main(){
    
    Std a[100],t;
    int i,j,n;

    scanf("%d",&n);
    for( i=0; i<n; i++)
    {
        scanf("%s %d", a[i].name,&a[i].score);
    }

    for( i=0; i<n; i++)
    {
        for( j=(i+1); j<n; j++)
        {
            if( a[i].score > a[j].score ){
               t = a[i];
               a[i] = a[j];
               a[j] = t;
            }
        }
        //printf("%d%d%d%d%d\n",a[0],a[1],a[2],a[3],a[4]);
    }

    for( i=0; i<n; i++ )
    {
        printf("%s\n",a[i].name);
    }

    getchar();getchar();
    return 0;

}
