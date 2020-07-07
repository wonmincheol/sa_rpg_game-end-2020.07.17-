#include "ccode/header/header.h"

int main()
{
    system("chcp 65001");
    system("cls");
    //test
    int direct = 0;
    unsigned int pos = 0;
    itemlist *head = NULL;
    itemlist *tail = NULL;
    itemlist data;
    //test_end
    void start_setting();
    character main_character;
    main_character = new_or_load_char();
    system("pause");
    system("cls");
    while (1)
    {
        printf("모드를 선택하시오(1 : 일반추가 2 : 중간추가 3 : 삭제 4: 전부삭제 5 : 전부출력 6 : 끝) : ");
        scanf(" %d", &direct);

        if (direct == 1)
        {
            printf("id : ");
            scanf(" %d", &data.item_id);
            printf("amount : ");
            scanf(" %d", &data.amount);
            add_list(&head, &tail, data);
        }
        if (direct == 2)
        {
            printf("id : ");
            scanf(" %d", &data.item_id);
            printf("amount : ");
            scanf(" %d", &data.amount);
            printf("pos : ");
            scanf(" %u", &pos);
            between_add_list(&head, data, pos);
        }
        if (direct == 3)
        {
            all_print(&head, &tail);
            printf("삭제번호 : ");
            scanf(" %u", &pos);
            delete_list(&head, &tail, pos);
        }
        if (direct == 4)
        {
            all_list_delete(&head, &tail);
        }
        if (direct == 5)
        {
            all_print(&head, &tail);
        }
        if (direct == 6)
        {
            break;
        }
        system("pause");
        system("cls");
    }
    system("pause");
    return 0;
}
