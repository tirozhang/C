#include<stdio.h>
#include<stdlib.h>

enum response_type {DUMP,SECOND_CHANGE,MARRIAGE};

typedef struct {
    char *name;
    enum response_type type;
} response;

void dump(response r){
    printf("dump");
}
void second_change(response r){
    printf("SECOND_CHANGE");
}
void marriage(response r){
    printf("marriage");
}

void (*replies[])(response) = {dump,second_change,marriage};
int main(){
    response r[] = {
        {"MIKE",DUMP},{"aa",SECOND_CHANGE},{"ccc",MARRIAGE}
    };
    int i;
    for( i = 0 ; i < 3 ; i++ ){
        replies[r[i].type](r[i]);
    }
    return 0;
}
