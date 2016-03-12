/* TLPI - Chap. 5.3 */

#define _FILE_OFFSET_BITS 64
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int fd;
    int flags, end = 0;
    long long c = atoll(argv[2]);

    if(!argv[3]) {
        flags = O_CREAT | O_WRONLY | O_APPEND;
    } else {
        end = 1;
        flags = O_CREAT | O_WRONLY;
    }

    fd = open(argv[1], flags, 0666);

    if( fd == -1 ) {
        perror("open");
    }

    while(c>0) {
        if (end) lseek(fd, 0, SEEK_END);
        write(fd, "x", 1);
        c--;
    }

    return 0;
}
