//
// Created by 单颖博 on 2018/12/8.
//

#include <apue.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    struct DIR *dp;
    struct dirent *dirp;

    if (argc != 2)
        err_quit("usage: ls directory_name");

    if ((dp = opendir(argv[1])) == NULL)
        err_sys("can't open %s", argv[1]);
    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);

    closedir(dp);

    return 0;
}

