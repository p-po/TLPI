/* TLPI - Chap. 5.1 */
#define _FILE_OFFSET_BITS 64
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int fd;
    off_t off;

    fd = open(argv[1], O_RDWR|O_CREAT, S_IRUSR | S_IWUSR);
    off = atoll(argv[2]);

    lseek(fd, off, SEEK_SET);

    write(fd, "test", 4);
    return 0;
}
