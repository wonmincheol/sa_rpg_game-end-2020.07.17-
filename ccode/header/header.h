#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//전역변수///////////////////////
typedef struct{
    char name[20];
    unsigned int level;
    unsigned int type;
}character;
//char_src.c//////////////////////////
character new_or_load_char();
//header.h////////////////////////////
int userdata_save(character data);