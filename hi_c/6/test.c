#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct data_type {
     int age;
     char name[20];
} data;

int main(){
    data *bob;
    //error 开辟空间不足，但不报错，超出部分被覆盖
    bob = malloc(sizeof(bob));
    bob->age = 22;
    strcpy(bob->name,"Robert");
    printf("%i=%s",bob->age,bob->name);

}
