#include "header/header.h"

typedef struct _itemlist
{
    int item_id;
    int item_amount;
    struct _itemlist *next;
} itemlist;

void item_add(itemlist **main_item, itemlist **next_item)
{
}