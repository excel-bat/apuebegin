//
// Created by 单颖博 on 2019/3/6.
// 测试io效率
// 使用方式：./myeffectio
//          标准输入上随便填写东西，然后回车
#include "apue.h"
#define BUFFSIZE 4096

int main(int argc,char const *argv[])
{

    int n;
    char buf[BUFFSIZE];
    while((n= read(STDIN_FILENO,buf,BUFFSIZE))>0){
        if(write(STDOUT_FILENO,buf,n)!=n)
            err_sys("write error");
    }
    if(n<0)
        err_sys("read error");
    return 0;
}




