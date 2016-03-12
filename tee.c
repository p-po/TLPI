/* Barebone implementation of 'tee' command */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int append, opt, fd;
    const char *file = 0;
    ssize_t n;
    char buf[1024];

    while ((opt = getopt(argc, argv, "a:")) != -1) {
        switch (opt) {
        case 'a':
            append = 1;
            file = optarg;
            break;
        default: 
            fprintf(stderr, "Usage: %s [-a] file\n",
                    argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    if(!file) {
        file = argv[1];
        fd = open(file, O_CREAT | O_WRONLY, 0664);
    } else {
        fd = open(file, O_APPEND | O_WRONLY | O_CREAT, 0664);
    }

    if(fd == -1) {
        perror("open");
        exit(1);
    }
  
    dup2(fd, fileno(stdout)); 
    
    while( (n=read(fileno(stdin), buf, sizeof buf)) > 0) {
        if(write(fd, buf, n) !=n ) {
            perror("write");
            exit(2);
        }
    }

    close(fd);
    return 0;
}
