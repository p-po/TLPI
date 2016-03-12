#define _FILE_OFFSET_BITS 64
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int fd;
    int flags, end = 0;

    flags = O_CREAT | O_WRONLY | O_APPEND;

    fd = open(argv[1], flags, 0666);
    if( fd == -1 ) {
        perror("open");
        exit(1);
    }

    /* dup(2) */
    int newfd = fcntl(fd, F_DUPFD);
    write(fd, "kane\n", 5);
    write(newfd, "UD\n", 3);

    /* thread unsafe - dup2(2) */
    int somefd = open(argv[2], flags, 0666);
    write(somefd, "bc\n", 3);
    close(somefd);
    int fd2 = fcntl(fd, F_DUPFD, somefd);
    /* Now both fd2 and fd are for argv[1] */
    write(fd2, "ac\n", 3);
        
    return 0;
}
