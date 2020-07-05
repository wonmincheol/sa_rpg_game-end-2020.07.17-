#include "header/header.h"

void add_list(itemlist **head, itemlist **tail, itemlist data)
{
    if ((*head) == NULL)
    {
        *head = (itemlist *)malloc(sizeof(itemlist));
        *tail = *head;
    }
    else
    {
        (*tail)->next = (itemlist *)malloc(sizeof(itemlist));
        *tail = (*tail)->next;
    }
    (*tail)->amount = data.amount;
    (*tail)->item_id = data.item_id;
    (*tail)->next = NULL;
}
//pos는 1이상이여야 한다.
void delete_list(itemlist **head, unsigned int pos)
{
    itemlist *target;
    itemlist *head_res = *head;
    while (pos - 2)
    {
        head_res = head_res->next;
        pos--;
    }
    target = head_res->next;
    head_res->next = (target)->next;
    free(target);
}
//pos는 1이상이여야 한다.
void between_add_list(itemlist **head, itemlist data, unsigned int pos)
{
    itemlist *res;
    itemlist *head_res = *head;
    while (pos - 2)
    {
        head_res = (head_res)->next;
        pos--;
    }
    res = (itemlist *)malloc(sizeof(itemlist));

    (res)->amount = data.amount;
    (res)->item_id = data.item_id;

    (res)->next = (head_res)->next;
    (head_res)->next = res;
}
void all_list_delete(itemlist **head, itemlist **tail)
{
    itemlist *target;
    while (1)
    {
        if ((*head) == (*tail))
        {
            free(*head);
            *head = NULL;
            *tail = NULL;
            break;
        }
        target = (*head)->next;
        free(*head);
        *head = target;
    }
}

void all_print(itemlist **head, itemlist **tail)
{
    int count = 1;
    itemlist *temp = *head;
    while ((temp != NULL))
    {
        printf("%3d번     id : %4d\n", count, temp->item_id);
        printf("%3d번 amount : %4d\n", count, temp->amount);
        if (temp->next == NULL)
        {
            break;
        }
        count++;
        temp = temp->next;
    }
}