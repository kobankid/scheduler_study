#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define DEVNAME "/dev/mem"

int main() {
    int fd;
    unsigned long from, num, port;
    volatile unsigned char *iomap;

    printf("this is IOmemory test program 2023-01-14\n");

    /* open physical memory device */
    fd = open(DEVNAME, O_RDWR);
    if (fd <= 0) {
        perror(DEVNAME);
        exit(1);
    }

    from = 0xfb000000;
    num  = 0x400;

    iomap = mmap(0, num, PROT_READ|PROT_WRITE, MAP_SHARED, fd, from);
    if (iomap < 0) {
        perror(DEVNAME);
        exit(1);
    }

    printf("IOmem mmapped at %p\n", iomap);

    munmap((void *)iomap, num);

    close(fd);
    
    return 0;
}
