#include "header/header.h"
character new_or_load_char()
{
    character data;
    char select[4];
    while (1)
    {
        printf("�̹� �÷����� ĳ���Ͱ� �ֽ��ϱ�?(yes or no) : ");
        scanf("%s", select);
        if ((0 == (strcmp(select, "yes"))) || (0 == (strcmp(select, "no"))))
        {
            break;
        }
        else
        {
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���\n");
        }
    }
    if ((0 == strcmp(select, "no")))
    {
        printf("ĳ���� �̸��� �Է��Ͻÿ� : ");
        scanf("%s", &data.name);
        while (userdata_name_test(data.name) == -1)
        {
            printf("�̹� �ִ� �̸��Դϴ�.\n");
            printf("ĳ���� �̸��� �Է��Ͻÿ� : ");
            scanf("%s", &data.name);
        }
        data.id = userdata_id_gen();
        data.level = 1;
        //�� ����? ���� �߰�
        //�ӽ� �׽�Ʈ
        data.type = -1;
        userdata_save(data);
    }
    else if ((0 == strcmp(select, "yes")))
    {
        printf("ĳ���� �̸��� �Է��Ͻÿ� : ");
        scanf("%s", data.name);
        data = userdata_load_char(data.name);
        printf("���̵� : %d\n", data.id);
        printf("�̸� : %s\n", data.name);
        printf("���� : %d\n", data.level);
        printf("���� : %d\n", data.type);

        //�߰� �Ұ�
    }
    return data;
}