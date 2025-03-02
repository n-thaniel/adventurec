#include <stdio.h>
#include <stdbool.h>
#include "object.h"
#include "misc.h"
#include "noun.h"
#include "move.h"

void executeGet(const char *noun)
{
    OBJECT *obj = getVisible("what you want to get", noun);
    switch (getDistance(player, obj)) 
    {
     case distSelf:
        printf("You try to collect yourself, but that is not possible in this dimension.\n");
        break;
    case distHeld:
        printf("You already have %s.\n", obj->description);
        break;
    case distOverThere:
        printf("Too far away, move closer.\n");
        break;
    case distUnknownObject:
        // already handled by GetVisible
        break;
    default:
        if (obj->location == guard)
        {
            printf("You should ask %s nicely.\n", obj->description);
        }
        else
        {
            moveObject(obj, player);
        }
    }
}

void executeDrop(const char *noun)
{
    moveObject(getPossession(player, "drop", noun), player->location);
}

void executeAsk(const char *noun)
{
    moveObject(getPossession(actorHere(), "ask", noun), player);
}

void executeGive(const char *noun)
{
    moveObject(getPossession(player, "give", noun), actorHere());
}

void executeInventory(void)
{
    if (listObjectsAtLocation(player) == 0)
    {
        printf("You are empty-handed.\n");
    }
}