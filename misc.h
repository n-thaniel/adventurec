#ifndef MISC_H
#define MISC_H

#include "object.h"
extern OBJECT *getPassage(OBJECT *from, OBJECT *to);
extern OBJECT *actorHere(void);
extern int listObjectsAtLocation(OBJECT *location);

#endif /* MISC_H */