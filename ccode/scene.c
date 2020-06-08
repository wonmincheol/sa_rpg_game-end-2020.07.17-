#include "header/header.h"

void choice_scene(character data)
{
    system("cls");
    int select = 0;

    //분기 입력

    switch (select)
    {
    case 1:
        motel_scene(data);
        break;
    case 2:
        variety_store_scene(data);
        break;
    case 3:
        stage_scene(data);
        break;
    default:
        break;
    }
}

void motel_scene(character data)
{
    system("cls");

    choice_scene(data);
}
void variety_store_scene(character data)
{
    system("cls");

    choice_scene(data);
}
void stage_scene(character data)
{
    system("cls");

    choice_scene(data);
}
void exit_scene(character data)
{
    system("cls");
}