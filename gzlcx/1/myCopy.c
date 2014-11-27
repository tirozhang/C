#include<stdio.h>
int main(int argCount,char* argValue[]){
    FILE *srcFile = 0,*destFile = 0;
    int ch = 0;
    if(argCount != 3){
        printf("Usage:%s src dest\n",argValue[0]);
    }else if( (srcFile = fopen(argValue[1],"rb")) == NULL){
        printf("Cant open \"%s\" file",argValue[1]);
    }else if( (destFile = fopen(argValue[2],"wb")) == NULL){
        printf("Cant write \"%s\" file",argValue[2]);
        fclose(srcFile);
    }else{
        while( (ch = fgetc(srcFile)) != EOF){
            fputc(ch,destFile);
        }
        printf("copy ok!");
        fclose(srcFile);
        fclose(destFile);
        return 0;
    }
    return 1;
}
