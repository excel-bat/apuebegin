//
// Created by 单颖博 on 2019/3/6.
// 查看文件类型
// 使用方式：./myfiletype  /etc/passwd /etc /dev/log /dev/tty /var/lib/oprofile/opd_pipe /dev/sr0 /dev/cdrom
// stat和lstat 使用可以参考man stat 得到结果

#include "apue.h"

int main(int argc,char const *argv[])
{

    int i;
    struct stat buf;
    char *ptr;

    for (int i = 0; i < argc ; ++i) {
        printf("%s: \n \t",argv[i]);
        if(lstat(argv[i],&buf)<0)
        {
            err_ret("lstat error");
            continue;
        }
        if(S_ISREG(buf.st_mode))
            ptr="regular file";
        else if(S_ISDIR(buf.st_mode))
            ptr="dir file";
        else if(S_ISFIFO(buf.st_mode))
            ptr="fifo file";
        else if(S_ISCHR(buf.st_mode))
            ptr="character special";
        else if(S_ISBLK(buf.st_mode))
            ptr="block special";
        else if(S_ISLNK(buf.st_mode))
            ptr="symbolic link";
        else if(S_ISSOCK(buf.st_mode))
            ptr="socket";
        else
            ptr="** unknown mode **";
        printf("%s\n", ptr);
    }
    return 0;
}