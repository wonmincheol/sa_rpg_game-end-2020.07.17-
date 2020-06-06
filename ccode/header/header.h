#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//유저 데이터///////////////////////
#define name_length 20
typedef struct
{
    unsigned int id;
    char name[name_length];
    unsigned int level;
    unsigned int type;
} character;
//database.c
#define user_id_bit_size 8
//최대 수용 가능 캐릭터 2^8 = 256개
#define user_size 3
#define data_type_number 4
//id(bit), name(string), level(int), type(int)

//char_src.c//////////////////////////
character new_or_load_char();
//header.h////////////////////////////
int userdata_save(character data);