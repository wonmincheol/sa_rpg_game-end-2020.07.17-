#include "header/header.h"

char database_name[] = "userdata.txt";
FILE *f;
int id = -1;
int userdata_save(character data)
{
    unsigned char id_bit[user_id_bit_size] = {0};
    unsigned int id_pack[user_size] = userdata_load_id_pack();
    if (id == -1)
    {
        id = random_id(id_pack);
    }
    if ((f = fopen(database_name, "w")) == NULL)
    {
        return -1;
    }
    strcpy(id_bit, int_to_bit(id));
    fprintf(f, "%s %s %d %d\n", id, data.name, data.level, data.type);
    fclose(f);
    return 0;
}
int userdata_load(char name[name_length])
{
    int res_id = 0;
    if ((f = fopen(database_name, "r")) == NULL)
    {
        return -1;
    }
}

int *userdata_load_id_pack()
{
    int return_id_ary[user_size] = {0};
    unsigned char res[user_id_bit_size] = {0};
    int pos = 0;
    if ((f = fopen(database_name, "r")) == NULL)
    {
        return -1;
    }
    while (1)
    {
        if (!(feof(f)))
        {
            break;
        }
        fscanf(f, "%s", res);
        return_id_ary[pos] = bit_to_int(res);
        pos++;
        for (int i = 0; i < data_type_number - 1; i++)
        {
            f++;
            if (!(feof(f)))
            {
                break;
            }
        }
    }

    return return_id_ary;
}
unsigned char *int_to_bit(unsigned int num)
{
    unsigned char array[user_id_bit_size] = {0};
    int pos = 0;
    while (num)
    {
        array[pos] = num % 2;
        num /= 2;
        pos++;
    }
    return array;
}
unsigned int bit_to_int(unsigned char bit_array[user_id_bit_size])
{
    int pos = 0;
    unsigned int id = 0;
    while (user_id_bit_size > pos)
    {
        id += bit_array[pos] * pow(2, pos);
    }
    return id;
}
unsigned int random_id(unsigned int array[user_size])
{
    unsigned int num = rand() % user_size + 1;
    for (int i = 0; i < user_size; i++)
    {
        if (num == array[i])
        {
            i--;
            num = rand() % user_size + 1;
        }
    }
    return num;
}