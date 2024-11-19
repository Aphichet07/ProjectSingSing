#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
int i;
struct user_insert
{
    char user_id[100];
    char user_tel[20];
    char user_exp[12]; // 01/01/0001
    char user_exd[12];
};

struct order_insert
{
    char order_id[10];
    char order_name[30];
    char order_price[10];
};

int get_id_from_log(const char *key) {
    FILE *file;
    file = fopen("DB/logDB.dat", "rt");
    if (file == NULL) {
        printf("Error opening log file.\n");
        return -1;
    }

    char line[50];
    while (fgets(line, sizeof(line), file)) {
        char *pos = strstr(line, key);
        if (pos != NULL) {
            char *value = strchr(line, ':');
            if (value != NULL) {
                fclose(file);
                return atoi(value + 1);
            }
        }
    }
    fclose(file);
    return 0;
}

void update_id_in_log(const char *key, int value) {
    FILE *file = fopen("DB/logDB.dat", "rt");
    if (file == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    char lines[2][50];
    int i = 0;
    while (fgets(lines[i], sizeof(lines[i]), file) && i < 2) {
        if (strstr(lines[i], key)) {
            sprintf(lines[i], "%s:%d\n", key, value);
        }
        i++;
    }
    fclose(file);

    file = fopen("DB/logDB.dat", "wt");
    if (file == NULL) {
        printf("Error opening log file for writing.\n");
        exit(1);
    }

    for (int j = 0; j < i; j++) {
        fputs(lines[j], file);
    }
    fclose(file);
}

int main(){
    struct user_insert uis[100];
    int log;
    char tel[20] = {0}, confirm[5] = {0}, chr_log[100];
    
    log = get_id_from_log("current_user_id");
    if(log < 0) printf("Error at log file!\n");



    while (1)
    {
        printf("Current ID  : %d\n", log);
        printf("Enter Tel   : ");
        fgets(tel, sizeof(tel), stdin);
        tel[strcspn(tel, "\n")] = '\0';

        while ((strlen(tel) > 10) || (strlen(tel) < 8)){
            printf("Invalid!. Enter Tel   : ");
            fgets(tel, sizeof(tel), stdin);
            tel[strcspn(tel, "\n")] = '\0';
        }

        printf("confirm     : ");
        fgets(confirm, sizeof(confirm), stdin);
        confirm[strcspn(confirm, "\n")] = '\0';

        printf("=========================\n");

        if (strcmp(confirm, "n") == 0) continue;
        if (strcmp(confirm, "c") == 0) break;
        
        if (strcmp(confirm, "y") == 0){
            itoa(log, chr_log, 10);
            strcpy(uis[log].user_id, chr_log);
            strcpy(uis[log].user_tel, tel);
            strcpy(uis[log].user_exp, "01/01/0001");
            strcpy(uis[log].user_exd, "01/01/0002");

            FILE *user_file;
            user_file = fopen("DB/userDB.dat", "at");
            if(user_file == NULL){
                printf("Error open user file!");
                return 1;
            }
            fprintf(user_file, "%s,%s,%s,%s\n", uis[log].user_id, uis[log].user_tel, uis[log].user_exp, uis[log].user_exd);
            fclose(user_file);

            log++;
            update_id_in_log("current_user_id", log);
            break;
        }
    }
    return 0;
}

/* void insert_order() {
    struct order_insert ois[100];

    int current_order_id = get_id_from_log("current_order_id");
    if (current_order_id == -1) {
        printf("Error reading current_order_id from log.\n");
        return;
    }

    sprintf(ois[current_order_id].order_id, "%d", current_order_id);

    printf("Enter Order Name : ");
    fgets(new_order.order_name, sizeof(new_order.order_name), stdin);
    new_order.order_name[strcspn(new_order.order_name, "\n")] = '\0';

    printf("Enter Order Price: ");
    fgets(new_order.order_price, sizeof(new_order.order_price), stdin);
    new_order.order_price[strcspn(new_order.order_price, "\n")] = '\0';

    FILE *file = fopen("DB/orderDB.dat", "at");
    if (file == NULL) {
        printf("Error opening orderDB.dat file for writing.\n");
        return;
    }

    fprintf(file, "%s,%s,%s\n", new_order.order_id, new_order.order_name, new_order.order_price);
    fclose(file);

    printf("Order added: ID=%s, Name=%s, Price=%s\n", new_order.order_id, new_order.order_name, new_order.order_price);


    update_id_in_log("current_order_id", current_order_id + 1);
} */