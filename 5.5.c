/* TLPI - Chap 5.5 */
#define _FILE_OFFSET_BITS 64
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int fd1, fd2;
    fd1 = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
//    fd2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0666);

    fd2 = dup(fd1);
    
    /* perform a write using fd1 and then fd2. Then compare offsets */
    write(fd1, "r1\n", 3);
    printf("%ld %ld\n", (long)lseek(fd1, 0, SEEK_CUR), lseek(fd2, 0, SEEK_CUR));

    write(fd2, "r2\n", 3);
    printf("%ld %ld\n", (long)lseek(fd1, 0, SEEK_CUR), lseek(fd2, 0, SEEK_CUR));
    
    return 0;
}
