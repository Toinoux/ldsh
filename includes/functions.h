#pragma once
#include <stdio.h>
//#include "core.h"

struct core;


/*
 *  container/container.c 
*/

int launcher();

/*
 *  functions_check/input.c
*/

char read_(int fd, void *buf, size_t nbyte);

/*
 *  engine/engine.c
*/

int engine(struct core *core);

/*
 * parsing/parser_cmd.c
*/

int parse_cmd(struct core *core);