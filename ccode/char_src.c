#include "header/header.h"
character new_or_load_char(){
    character data;
    char select[4];
    while(1){
        printf("�̹� �÷����� ĳ���Ͱ� �ֽ��ϱ�?(yes or no) : ");
        scanf("%s",select);
        if((0==(strcmp(select,"yes")))||(0==(strcmp(select,"no")))){
            break;
        }
        else{
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���\n");
        }
    }
    if((0==strcmp(select,"no"))){
        while(1){
            printf("ĳ���� �̸��� �Է��Ͻÿ� : ");
            if(scanf("%s",data.name)){
                break;
            }
        }
        
        
    }
    else if((0==strcmp(select,"yes"))){
        //�߰� �Ұ�
    }
    return data;
}