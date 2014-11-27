#include <stdio.h>

#define IN  1
#define OUT 0
main(){
    int str,words_num,line_num,ch_num,state;
    state = OUT;
    words_num = line_num = ch_num = 0;
    while( (str = getchar()) != EOF){
        ++ch_num;
        if(str == '\n'){
            ++line_num;
        }
        if(str == '\n' || str == '\t' || str == ' '){
            state = OUT;
        }else if(state == OUT){
            state = IN;
            ++words_num;
        }
    }
    printf("\n%d:%d:%d\n",words_num,line_num,ch_num);
}
