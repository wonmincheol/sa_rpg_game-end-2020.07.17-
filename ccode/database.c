#include "header/header.h"
//데이터 유형
//id, 이름, level, type
char database_name[] = "userdata.txt";
FILE *f;
int id = -1;

void remove_data(character data);

void userdata_save(character data)
{
    character res;
    int swit = 0;
    long ptr = 0;
    FILE *fileres = 0;
    if ((f = fopen(database_name, "r+")) == NULL)
    {
        //파일 접촉 오류
        if ((fileres = fopen(database_name, "w+")) == NULL)
        {
            printf("gene_error");
        }
        fclose(fileres);
        if ((f = fopen(database_name, "r+")) == NULL)
        {
            printf("gene_error2");
        }
    }
    //게임 중도 저장시 변경방안 추가
    fseek(f, 0, SEEK_SET);
    while (!feof(f))
    {
        ptr = ftell(f);
        fscanf(f, "%d %d %d %s\n", &res.id, &res.level, &res.type, &res.name);
        if (res.id == data.id)
        {
            ptr = ftell(f) - ptr;
            swit = 1;
            printf("out");
            break;
        }
        printf("in\n");
    }
    if (swit == 1)
    {
        fseek(f, -ptr, SEEK_CUR);
        fprintf(f, "%d %d %d %s\n", data.id, data.level, data.type, data.name);
    }
    else
    {
        fseek(f, 0, SEEK_END);
        fprintf(f, "%d %d %d %s\n", data.id, data.level, data.type, data.name);
    }
    fclose(f);
}

void remove_data(character data)
{
    character res;
    if ((f = fopen(database_name, "r+")) == NULL)
    {
        return;
    }
    while (!feof(f))
    {

        if (data.id == res.id)
        {
            break;
        }
    }
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
        fscanf(f, "%d %d %d %s", &res.id, &res.level, &res.type, &res.name);
        if ((strcmp(name, res.name)) == 0)
        {
            return -1;
        }
    }
    fclose(f);
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
        fscanf(f, "%d %d %d %s", &res.id, &res.level, &res.type, &res.name);
        id_array[pos] = res.id;
        pos++;
    }
    target = random_id(id_array);
    fclose(f);
    return target;
}
character userdata_load_char(char name[name_length])
{
    character data, res;
    if ((f = fopen(database_name, "r")) == NULL)
    {
        //파일 접촉 오류
        strcpy(data.name, "error_open");
        fclose(f);
        return data;
    }
    while (!feof(f))
    {
        fscanf(f, "%d %d %d %s", &res.id, &res.level, &res.type, &res.name);
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
        fclose(f);
        return data;
    }
    //데이터 로드 성공
    if (strcmp(data.name, name) == 0)
    {
        fclose(f);
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

// char *int_to_bit(int value)
// {
//     static char array[databit_size + 1] = {0};
//     int pos = 0;
//     for (int i = 0; i < databit_size + 2; i++)
//     {
//         if (i == databit_size)
//         {
//             array[i] = '\0';
//         }
//         else
//         {
//             array[i] = '0';
//         }
//     }
//     while (value)
//     {
//         if ((value % 2) == 1)
//         {
//             array[databit_size - 1 - pos] = '1';
//         }
//         else
//         {
//             array[databit_size - 1 - pos] = '0';
//         }
//         pos++;
//         value /= 2;
//     }
//     return array;
// }