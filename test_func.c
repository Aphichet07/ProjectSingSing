#include <stdio.h>
#include "insertIntoDB.c"
#include "createDB.c"
#include "header.h"

int main() {
    FILE *logC, *userC, *orderC;
    int inp;

    logC = fopen("DB/logDB.dat", "rt");
    if (logC == NULL) loger();
    else fclose(logC);

    userC = fopen("DB/userDB.dat", "rt");
    if (userC == NULL) creat_user_db();
    else fclose(userC);

    orderC = fopen("DB/orderDB.dat", "rt");
    if (orderC == NULL) creat_order_db();
    else fclose(orderC);

    while (1) {
        printf("\n===== MENU =====\n");
        printf("1. Insert User\n");
        printf("2. Insert Order\n");
        printf("0. Exit\n");
        printf("================\n");
        printf("Enter your choice: ");
        printf("Enter option (1 for user, 2 for order): ");
        scanf("%d", &inp);
        while (getchar() != '\n'); //clear buffer

        if (inp == 0) {
            printf("Exiting program. Goodbye!\n");
            break;
        }
        if (inp == 1) {
            insert_user();
        }
        if (inp == 2) {
            insert_order();
        } 
        
    }

    return 0;
}
