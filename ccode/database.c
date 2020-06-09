#include "header/header.h"
//데이터 유형
//id, 이름, level, type
char database_name[] = "userdata.txt";
FILE *f;
int id = -1;

void *int_to_bit(int value, char array[]);

void userdata_save(character data)
{
    if ((f = fopen(database_name, "a")) == NULL)
    {
        //파일 접촉 오류
        printf("error");
    }
    //게임 중도 저장시 변경방안 추가
    fprintf(f, "%d %s %d %d\n", data.id, data.name, data.level, data.type);
    fclose(f);
}
int userdata_name_test(char name[name_length])
{
    if ((f = fopen(database_name, "r")) == NULL)
    {
        //파일 접촉 오류
        return 0;
    }
    character res;
    while (!feof(f))
    {
        fscanf(f, "%d %s %d %d", &res.id, &res.name, &res.level, &res.type);
        if ((strcmp(name, res.name)) == 0)
        {
            return -1;
        }
    }
    return 1;
}
int userdata_id_gen()
{
    if ((f = fopen(database_name, "r")) == NULL)
    {
        //파일 접촉? 오류, 파일 생성
        srand(time(NULL));
        return rand() % user_size + 1;
    }
    int target = 0;
    int id_array[user_size] = {0};
    character res;
    unsigned int pos = 0;
    while (!feof(f) && (pos < 256))
    {
        fscanf(f, "%d %s %d %d", &res.id, &res.name, &res.level, &res.type);
        id_array[pos] = res.id;
        pos++;
    }
    target = random_id(id_array);
    return target;
}
character userdata_load_char(char name[name_length])
{
    character data, res;
    if ((f = fopen(database_name, "r")) == NULL)
    {
        //파일 접촉 오류
        strcpy(data.name, "error_open");
        return data;
    }
    while (!feof(f))
    {
        fscanf(f, "%d %s %d %d", &res.id, &res.name, &res.level, &res.type);
        if ((strcmp(res.name, name) == 0))
        {
            data.id = res.id;
            strcpy(data.name, res.name);
            data.level = res.level;
            data.type = res.type;
        }
    }
    fclose(f);
    //데이터 로드 실패
    if (strcmp(data.name, name) != 0)
    {
        strcpy(data.name, "not_load");
        return data;
    }
    //데이터 로드 성공
    if (strcmp(data.name, name) == 0)
    {
        return data;
    }
}
unsigned int random_id(unsigned int array[user_size])
{
    srand(time(NULL));
    unsigned int num = rand() % user_size + 1;
    for (int i = 0; i < user_size; i++)
    {
        if (num == array[i])
        {
            i = 0;
            num = rand() % user_size + 1;
        }
        if (array[i] == 0)
        {
            break;
        }
    }
    return num;
}

// void *int_to_bit(int value, char res[databit_size + 1])
// {
//     int pos = 0;
//     for (int i = 0; i < databit_size + 2; i++)
//     {
//         if (i == (databit_size + 1))
//         {
//             res[i] = '\0';
//         }
//         else
//         {
//             res[i] = '0';
//         }
//     }
//     while (value)
//     {
//         if ((value % 2) == 1)
//         {
//             res[databit_size - 1 - pos] = '1';
//         }
//         else
//         {
//             res[databit_size - 1 - pos] = '0';
//         }
//         value = value / 2;
//         pos++;
//     }
//     //return res;
// }