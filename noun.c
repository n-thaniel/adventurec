#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "object.h"
#include "misc.h"

static bool objectHasTag(OBJECT *obj, const char *noun)
{
    return noun != NULL && *noun != '\0' && strcmp(noun, obj->tag) == 0;
}

static OBJECT *getObject(const char *noun, OBJECT *from, DISTANCE maxDistance)
{
    OBJECT *obj, *res = NULL;
    for (obj = objs; obj < endOfObjs; obj++)
    {
        if (objectHasTag(obj, noun) && getDistance(from, obj) <= maxDistance)
        {
            res = obj;
        }
    }
    return res;
}

OBJECT *getVisible(const char *intention, const char *noun)
{
    OBJECT *obj = getObject(noun, player, distOverThere);
    if (obj == NULL)
    {
        if (getObject(noun, player, distNotHere) == NULL) 
        {
            printf("I don't understand %s.\n", intention);
        }
        else 
        {
            printf("You don't see any %s here.\n", noun);
        }
        
    }
    return obj;
}

OBJECT *getPossession(OBJECT *from, const char *verb, const char *noun)
{
    OBJECT *obj = NULL;
    if (from == NULL)
    {
        printf("I don't understand who you want to %s.\n", verb);
    }
    else if ((obj = getObject(noun, from, distHeldContained)) == NULL)
    {
        if (getObject(noun, player, distNotHere) == NULL) 
        {
            printf("I don't understand what you want to %s.\n", verb);
        }
        if (from == player)
        {
            printf("You are not holding any %s\n", noun);
        }
        else 
        {
            printf("There appears to be no %s you can get from %s.\n", noun, from->description);
        }
    }
    else if (obj == from)
    {
        printf("You should not be doing that to %s.\n", obj->description);
        obj = NULL;
    }
    return obj;
}