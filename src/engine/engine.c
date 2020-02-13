#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "core.h"
#include "maccro.h"

#define USR_CMD "ls -la"

void puutchar(char c) {
    write(1, &c, 1);
}

void putstr(char *str) {
    int index = 0;

    if (str == NULL)
        return;
    while ((unsigned int) index < strlen(str)) {
        putchar(str[index]);
        index++;
    }
}

static int read_input(struct core *core) {
    char *usr_cmd = NULL;
    size_t size;

    getline(&usr_cmd, &size, stdin);
    usr_cmd[strlen(usr_cmd) -1] = '\0';
    core->usr_cmd = usr_cmd;
    free(usr_cmd);
    return (0);
}

int engine(struct core *core) {
    //char *usr_cmd = "ls -la";

    while (NON_STOP) {
        putstr(core->prompt);
        read_input(core);
        parse_cmd(core);
        //break;
    };
    return (OK);
}