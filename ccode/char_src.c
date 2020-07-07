#include "header/header.h"
character new_or_load_char()
{
    character data;
    char select[4];
    while (1)
    {
        printf("기존에 플레이하던 캐릭터가 있습니까? (yes or no) : ");
        scanf("%s", select);
        if ((0 == (strcmp(select, "yes"))) || (0 == (strcmp(select, "no"))))
        {
            break;
        }
        else
        {
            printf("잘못된 입력입니다.\n");
        }
    }
    if ((0 == strcmp(select, "no")))
    {

        printf("캐릭터 이름을 입력하시오 : ");
        scanf("%s", &data.name);
        while (userdata_name_test(data.name) == -1)
        {
            printf("할수 없는 이름입니다.\n");
            printf("캐릭터 이름을 입력하시오 : ");
            scanf("%s", &data.name);
        }
        data.id = userdata_id_gen();
        data.level = 1;
        //test
        data.type = 99;
        userdata_save(data);
    }
    else if ((0 == strcmp(select, "yes")))
    {
        printf("캐릭터 이름을 입력하시오 : ");
        scanf("%s", data.name);
        data = userdata_load_char(data.name);
        printf("id : %d\n", data.id);
        printf("name : %s\n", data.name);
        printf("level : %d\n", data.level);
        printf("type : %d\n", data.type);
        printf("변경할 레벨을 입력하시오 : ");
        scanf(" %d", &data.level);
        printf("debug : %d", data.level);
        userdata_save(data);
    }
    return data;
}