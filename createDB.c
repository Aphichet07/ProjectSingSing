#include <stdio.h>
#include "header.h"

int loger(){
    FILE *log;
    log = fopen("DB/logDB.dat", "wt");
    if(log == NULL){
        printf("\ncan't create logDB file!");
        return -1;
    }
    else printf("\ncreat logDB success");
    fclose(log);
    log = fopen("DB/logDB.dat", "at");
    if(log == NULL){
        printf("\ncan't open logDB file!");
        return -1;
    }
    fprintf(log, "current_user_id:1\ncurrent_order_id:1");
    fclose(log);
}

int creat_user_db(){
    FILE *user;
    user = fopen("DB/userDB.dat", "wt");
    fclose(user);
    if(user == NULL){
    printf("\ncan't create userDB file!");
    return -1;
    }
    else printf("\ncreat userDB success");
}

int creat_order_db(){
    FILE *order;
    order = fopen("DB/orderDB.dat", "wt");
    fclose(order);
    if(order == NULL){
        printf("\ncan't create orderDB file!");
        return -1;
    }
    else printf("\ncreat orderDB success");
}
