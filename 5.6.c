/* TLPI - Chap 5.6 */

#define _FILE_OFFSET_BITS 64
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int fd1, fd2, fd3;

    fd1 = open("file", O_RDWR | O_CREAT | O_TRUNC, 0600);
    fd2 = dup(fd1);
    fd3 = open("file", O_RDWR);

    /* fd1 and fd2 are same fds. So the next 2 writes will be one after another in the file */
    write(fd1, "Hello,", 6);
    write(fd2, "world", 6);
    /* "Hello,world" will be the content of the file now */

    lseek(fd2, 0, SEEK_SET);
    /* Both fd1 and fd2 are at beginning of the file. So the next write() will overwrite  *
     * "Hello," --> "HELLO," file = "HELLO,world" */
    write(fd1, "HELLO,", 6);

    /* fd3 is independent of fd1 and fd2 and pointing at the beg. of file. *
     * So it'll overwrite "HELLO," --> "GIDDAY" */
    write(fd3, "GIDDAY",6);

}

