#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void diedie( int sig ){
    puts("BYE\n");
    exit(1);
}

int catch_signal( int sig, void(*handler)(int)){
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig,&action,NULL);
}

int main(){
    if(catch_signal(SIGALRM,diedie) == -1){
        fprintf(stderr,"cannot map the handler");
        exit(2);
    }
    alarm(10);
    char name[30];
    printf("Enter your name:\n");
    fgets(name,30,stdin);
    printf("hello %s\n",name);
    return 0;
}
