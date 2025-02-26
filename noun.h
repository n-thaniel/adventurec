#ifndef NOUN_H
#define NOUN_H

#include "object.h"
extern OBJECT *getVisible(const char *intention, const char *noun);
extern OBJECT *getPossession(OBJECT *from, const char *verb, const char *noun);

#endif /* NOUN_H */