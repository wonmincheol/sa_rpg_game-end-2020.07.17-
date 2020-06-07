#include "header/header.h"
character new_or_load_char()
{
    character data;
    char select[4];
    while (1)
    {
        printf("이미 플레이한 캐릭터가 있습니까?(yes or no) : ");
        scanf("%s", select);
        if ((0 == (strcmp(select, "yes"))) || (0 == (strcmp(select, "no"))))
        {
            break;
        }
        else
        {
            printf("잘못된 입력입니다. 다시 입력하세요\n");
        }
    }
    if ((0 == strcmp(select, "no")))
    {
        printf("캐릭터 이름을 입력하시오 : ");
        scanf("%s", &data.name);
        while (userdata_name_test(data.name) == -1)
        {
            printf("이미 있는 이름입니다.\n");
            printf("캐릭터 이름을 입력하시오 : ");
            scanf("%s", &data.name);
        }
        data.id = userdata_id_gen();
        data.level = 1;
        //뱁세 전직? 선택 추가
        //임시 테스트
        data.type = -1;
        userdata_save(data);
    }
    else if ((0 == strcmp(select, "yes")))
    {
        printf("캐릭터 이름을 입력하시오 : ");
        scanf("%s", data.name);
        data = userdata_load_char(data.name);
        printf("아이디 : %d\n", data.id);
        printf("이름 : %s\n", data.name);
        printf("레벨 : %d\n", data.level);
        printf("전직 : %d\n", data.type);

        //추가 할것
    }
    return data;
}