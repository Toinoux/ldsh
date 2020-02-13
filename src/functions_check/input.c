#include <unistd.h>
#include "string.h"
#include "maccro.h"

char read_(int fd, void *buf, size_t nbyte) {
    //char buf[1];
    //char *str = NULL;

    if (read(fd, buf, nbyte) < 0) {
        return (-1);
    }
    //putchar(((char*)buf)[0]);
    return (((char *) &buf)[0]);
}