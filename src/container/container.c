#include <stdlib.h>
#include "core.h"
#include "maccro.h"

int launcher() {
    struct core core;

    core.prompt = "[ceci est un prompt]: ";
    printf("\n%s\n", STR_START);
    engine(&core);
    return (OK);
}
