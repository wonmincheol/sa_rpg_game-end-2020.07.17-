#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
} NODE;

void add_node(NODE **head, NODE **tail, int data);
void add_between_node(NODE **head, NODE **tail, NODE **add, int num);
void delete_all_node(NODE **head, NODE **tail);
void delete_node(NODE **head, int num);

int main()
{
	NODE *head = NULL, *tail = NULL, *add, *p;
	int sum, temp, menu, num;

	while (1)
	{
		sum = 0;
		printf("????? ????????.\n");
		printf("1. ????  2. ???? ????  3.??? ????  4.????? ???  5.??? ????(????)\n");
		scanf("%d", &menu);
		if (menu == 1)
		{
			add = (NODE *)malloc(sizeof(NODE));
			printf("????? ????? ????? ????????(0?????? ????) : ");
			scanf("%d", &num);
			printf("????? ???????? : ");
			scanf("%d", &(add->data));
			add_between_node(&head, &tail, &add, num);
		}
		else if (menu == 2)
		{
			while (1)
			{
				printf("????? ????????(9999 ??? ?? ????) : ");
				scanf("%d", &temp);
				if (temp == 9999)
					break;
				add_node(&head, &tail, temp);
			}
		}
		else if (menu == 3)
		{
			printf("?????? ????? ????? ????????(0?????? ????) : ");
			scanf("%d", &num);
			delete_node(&head, num);
		}
		else if (menu == 4)
		{
			p = head;
			while (NULL != p)
			{
				if (p != head)
					printf(" + ");
				printf(" %d ", p->data);
				sum += p->data;
				p = p->next;
			}
			printf(" = %d\n", sum);
		}
		else if (menu == 5)
		{
			delete_all_node(&head, &tail);
			break;
		}
		else
		{
			printf("???? ??? ????? ?????.\n");
		}
	}

	return 0;
}

void add_node(NODE **head, NODE **tail, int data)
{
	if (NULL != *head)
	{
		(*tail)->next = (NODE *)malloc(sizeof(NODE));
		*tail = (*tail)->next;
	}
	else
	{
		*head = (NODE *)malloc(sizeof(NODE));
		*tail = *head;
	}
	(*tail)->data = data;
	(*tail)->next = NULL;
}

void add_between_node(NODE **head, NODE **tail, NODE **add, int num)
{
	NODE *pos = *head;

	if (NULL == *head)
	{
		*head = *add;
		*tail = *head;
		(*tail)->next = NULL;
	}
	else
	{
		for (int i = 0; i < num - 1; i++)
		{
			pos = pos->next;
		}
		(*add)->next = pos->next;
		pos->next = (*add);
	}
}

void delete_all_node(NODE **head, NODE **tail)
{
	while (*head != *tail)
	{
		NODE *del = *head;
		(*head) = (*head)->next;
		free(del);
	}
}

void delete_node(NODE **head, int num)
{
	NODE *pos = *head;
	NODE *temp;
	for (int i = 0; i < num - 1; i++)
	{
		pos = pos->next;
	}
	temp = pos->next;
	pos->next = pos->next->next;

	free(temp);
}
