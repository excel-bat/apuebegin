//
// Created by 单颖博 on 2019/3/5.
// 执行方式在terminal中执行 ./myoffsetio < /etc/passwd
//

#include "apue.h"
#include <fcntl.h>


int main(int argc,char const *argv[])
{

    if(lseek(STDIN_FILENO,0,SEEK_CUR)== -1)
    {
        printf("cannot seek\n");
    }
    else {
        printf("seek ok\n");
    }
    return 0;
}