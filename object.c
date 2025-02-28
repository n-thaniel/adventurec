#include <stdio.h>
#include "object.h"

OBJECT objs[] = {
    {"an open field", "field", NULL, NULL},
    {"a cave", "cave", NULL, NULL},
    {"a silver coin", "silver", field, NULL},
    {"a gold coin", "gold", cave, NULL},
    {"a mean guard", "guard", field, NULL},
    {"yourself", "yourself", field, NULL},
    {"an ugly bat", "bat", cave, NULL},
    {"a cave entrance", "entrance", field, cave},
    {"an exit", "exit", cave, field},
};