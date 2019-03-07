//
// Created by 单颖博 on 2019/2/18.
//

#include "apue.h"
#include <errno.h>
int main(int argc,char const *argv[])
{

    fprintf(stderr,"EACCESS : %s\n",strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    return 0;
}