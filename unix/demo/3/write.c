#include"apue.h"
#include<fcntl.h>
#include"error.c"

char buf1[] = "abcdefg";
char buf2[] = "hijklmn";

int main(){
    int fd ;
    if((fd = creat("test.file",FILE_MODE)) < 0 ){
        err_sys("creat error !");
    }
    if(write( fd, buf1, 10) != 10){
        err_sys("buf1 write error");
    }
    if(lseek(fd , 16484, SEEK_SET) == -1){
        err_sys("lseek error");
    }
    if(write(fd, buf2, 10) != 10){
        err_sys("buf2 write error!");
    }
    exit(0);
}
