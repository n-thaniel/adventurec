#ifndef INVENTORY_H
#define INVENTORY_H

extern void executeGet(const char *noun);
extern void executeDrop(const char *noun);
extern void executeAsk(const char *noun);
extern void executeGive(const char *noun);
extern void executeInventory(const char *noun);

#endif