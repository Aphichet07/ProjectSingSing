#include <stdio.h>
#include "header.h"

int loger(void){
    FILE *log;
    log = fopen("DB/logDB.dat", "wt");
    fclose(log);
    if(log == NULL) printf("\ninvalid File");
    else printf("\ncreat logDB success");
    log = fopen("DB/logDB.dat", "at");
    fprintf(log, "current_user_id:1");
    fclose(log);
}

int creat_user_db(void){
    FILE *user;
    user = fopen("DB/userDB.dat", "wt");
    fclose(user);
    if(user == NULL) printf("\ninvalid File");
    else printf("\ncreat userDB success");
}

int creat_order_db(void){
    FILE *order;
    order = fopen("DB/orderDB.dat", "wt");
    fclose(order);
    if(order == NULL) printf("\nInvalid File");
    else printf("\ncreat orderDB success");
}
