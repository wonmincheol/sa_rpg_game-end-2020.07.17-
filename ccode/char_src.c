#include "header/header.h"
character new_or_load_char(){
    character data;
    char select[4];
    while(1){
        printf("이미 플레이한 캐릭터가 있습니까?(yes or no) : ");
        scanf("%s",select);
        if((0==(strcmp(select,"yes")))||(0==(strcmp(select,"no")))){
            break;
        }
        else{
            printf("잘못된 입력입니다. 다시 입력하세요\n");
        }
    }
    if((0==strcmp(select,"no"))){
        while(1){
            printf("캐릭터 이름을 입력하시오 : ");
            if(scanf("%s",data.name)){
                break;
            }
        }
        
        
    }
    else if((0==strcmp(select,"yes"))){
        //추가 할것
    }
    return data;
}