/* TLPI - Chap. 5.2 */
#define _FILE_OFFSET_BITS 64
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int fd;
    fd = open("file", O_WRONLY | O_APPEND);

    if(lseek(fd, 0, SEEK_SET) == -1) {
        perror("perror");
        exit(1);
    }

    printf("%ld\n", (long)write(fd, "test", 4));

    return 0;
}
