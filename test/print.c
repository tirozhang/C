#include <stdio.h>
#include <string.h>
char *msg[]={"Monday","Sunday"};

char *get_day(int index)
{
    static char buff[20];
    strcpy(buff,msg[index]);
    return buff;
}

int main()
{
   printf("%s %s\n",get_day(0),get_day(1));
   printf("%s\n",get_day(0));
   printf("%s\n",get_day(1));
    return 0;
}
