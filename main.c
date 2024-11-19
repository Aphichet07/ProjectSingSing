#include <stdio.h>
#include "header.h"
#include "createDB.c"


int main(){
    FILE *logC, *userC, *orderC;
    logC = fopen("DB/logDB.dat", "rt");
    userC = fopen("DB/userDB.dat", "rt");
    orderC = fopen("DB/orderDB.dat", "rt");

    if(logC == NULL) loger();
    if(userC == NULL) creat_user_db();
    if(orderC == NULL) creat_order_db(); 

    return 0;
}