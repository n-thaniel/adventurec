#ifndef OBJECT_H
#define OBJECT_H

typedef struct object {
    const char *description;
    const char *tag;
    struct object *location;
    struct object *destination;
} OBJECT;

extern OBJECT objs[];

#define field   (objs + 0)
#define cave    (objs + 1)
#define silver  (objs + 2)
#define gold    (objs + 3)
#define guard   (objs + 4)
#define player  (objs + 5)
#define bat     (objs + 6)
#define intoCave (objs + 7)
#define exitCave (objs + 8)

#define endOfObjs   (objs + 9)

#endif