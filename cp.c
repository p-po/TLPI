/* Barebone implementation of 'cp' command */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int rd, wd;
    ssize_t n;
    char buf[1024];

    if( argc != 3 ) {
        printf("usage: %s src dest\n", argv[0]);
        exit(1);
    }
   
    rd = open(argv[1], O_RDONLY);
    wd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0666);

    if( rd == -1 ) {
        printf("Error opening %s\n", argv[1]);
        exit(1);
    }
  
    if( wd == -1 ) {
        printf("Error opening %s\n", argv[2]);
        exit(1);
    }

    while( (n=read(rd, buf, sizeof buf)) > 0 ) {
        write(wd, buf, n); 
    }

    return 0;
}
