#include <stdio.h>
#define MAX 1000

int getline(char line[],int max);
int strindex(char source[],char searchfor[]);

char parten[] = "ould";

int main(){
    char line[MAX];
    int found = 0;

    while(getline(line,MAX) > 0){
        if(strindex(line,parten) >= 0){
            printf("%s",line);
            found++;
        }
    }
    return found;

}

int getline(char s[],int max){
    int c,i=0;
    while( max >0 && ((c = getchar()) != EOF) && c != '\n' ){
        s[i++] = c;
        max--;
    }
    if(c == '\n'){
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}
int strindex(char s[],char t[]){
    int i,j,k;

    for(i=0;s[i]!='\0';i++){
        for(j=0;t[j]!='\0';j++){
            if(s[i] == t[j]){
                return i;
            }
        }
    }
    return -1;
}

