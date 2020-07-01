#include "header/header.h"

typedef struct _itemlist
{
    int id;
    int amount;
    struct _itemlist *next;
} itemlist;

void additem(itemlist)