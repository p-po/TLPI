#define _FILE_OFFSET_BITS 64
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    /* 2>&1 */
    dup2(STDOUT_FILENO, STDERR_FILENO);
    fprintf(stderr, "printing to stderr \n");
    fprintf(stdout, "printing to stdout \n");

    /* >&2 */
    dup2(STDERR_FILENO, STDOUT_FILENO);
    fprintf(stderr, "printing to stderr \n");
    fprintf(stdout, "printing to stdout \n");

    return 0;
}
