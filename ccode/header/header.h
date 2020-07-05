#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
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
#define databit_size 8
//최대 수용 가능 캐릭터 2^8 = 256개
//데이터 크기 = 2^8 =255까지 수용
#define user_size 256
//id(int), name(string), level(int), type(int)
//초기 데이터 베이스 생성
void userdata_new_txt();

void userdata_save(character data);
//중복이름 테스트 return 접촉오류 0, 성공 1, 실패 -1
int userdata_name_test(char name[name_length]);
//중복없는 아이디 생성 return 아이디
int userdata_id_gen();
//인풋 이름, 아웃풋 character
character userdata_load_char(char name[name_length]);
//현재 데이터베이스의 id목록 입력 return 중복없는 id
unsigned int random_id(unsigned int array[user_size]);

void remove_data(character data);

//char_src.c//////////////////////////
character new_or_load_char();

//start.c//////////////////////////////
void start_setting();

//scene.c//////////////////////////////

//신 선택 화면(character)
void choice_scene(character data);
//여관 화면(character)
void motel_scene(character data);
//잡화점 화면(character)
void variety_store_scene(character data);
//전투 화면(character)
void stage_scene(character data);
//종료 화면(character)
void exit_scene(character data);

//inventory.c
typedef struct _itemlist
{
    int item_id;
    unsigned int amount;
    struct _itemlist *next;
} itemlist;
void add_list(itemlist **head, itemlist **tail, itemlist data);
void delete_list(itemlist **head, unsigned int pos);
void between_add_list(itemlist **head, itemlist data, unsigned int pos);
void all_list_delete(itemlist **head, itemlist **tail);
void all_print(itemlist **head, itemlist **tail);
