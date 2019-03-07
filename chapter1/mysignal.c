//
// Created by 单颖博 on 2019/2/19.
// 沿用exec1 函数，增加异常处理
// 注意：此函数使用时，不能直接用clion 的run mysignal，因为^c 键和 系统Edit copy 键冲突，，改用命令行执行
// cd ../cmake-build-debug
// ./mysignal 执行 ^c 执行中断
//
#include "apue.h"
#include <sys/wait.h>

static void sig_int(int); /**our signal catch */

int main(int argc,char const *argv[])
{

    char buf[MAXLINE];
    pid_t pid;
    int status;

    if(signal(SIGINT,sig_int)==SIG_ERR)
        err_sys("signal error");

    printf("%% ");
    while(fgets(buf,MAXLINE,stdin)!= NULL) {
        if ((buf[strlen(buf) - 1]) == '\n')
            buf[strlen(buf) - 1] = 0;
        if ((pid = fork()) < 0) {//  注意括号，不要把括号写成if ((pid = fork() < 0) {  这样是将fork()<0 的结果赋值给pid
            err_sys("fork error");
        } else if (pid == 0) {
            execlp(buf, buf, (char *) 0);
            err_ret("couldn't execute %s", buf);
            exit(127);
        }

        if ((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("waitpid error");

        printf("%%");



    }
    exit(0);
}

void sig_int(int signo)
{
    printf("interrupt\n %%");
}