#include "header/header.h"
char database_name[] = "userdata.txt";
FILE *f;

int userdata_save(character data){
    if((f=fopen(database_name,"w"))==NULL){
        return -1;
    }
    int cnt=0;
    fprintf(f,"%d %s %d %d\n",++cnt, data.name, data.level, data.type);
    fclose(f);
    return 0;
}
