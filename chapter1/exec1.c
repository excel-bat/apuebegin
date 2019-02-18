//
// Created by 单颖博 on 2019/2/18.
//

#include "exec1.h"
#include <apue.h>
#include <sys/wait.h>


int main(void)
{
    char buf[MAXLINE]; /**from apue.h*/
    pid_t pid;
    int status;

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



