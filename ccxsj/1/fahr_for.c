#include <stdio.h>
main(){
    int fahr ;
    for(fahr = 0 ; fahr <= 300 ; fahr += 20){
        printf("%d\t%3.1f\n",fahr, (5.0/9.0)*(fahr-32));
    }
}
