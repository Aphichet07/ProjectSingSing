#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"
int i;

struct user_insert
{
    char user_id[100];
    char user_tel[20];
    char user_exp[12];
    char user_exd[12];
};

struct order_insert
{
    char order_id[10];
    char order_name[30];
    char order_price[10];
};

int get_id_from_log(char *key) {
    FILE *file;
    file = fopen("DB/logDB.dat", "rt");
    if (file == NULL) {
        printf("Error opening log file.\n");
        return -1;
    }

    char line[50];
    while (fgets(line, sizeof(line), file)) {       
        char *pos = strstr(line, key);          //find substring(key) in line if not found return NULL
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

int update_id_in_log(const char *key, int value) {
    FILE *file = fopen("DB/logDB.dat", "rt");
    if (file == NULL) {
        printf("Error opening log file.\n");
        return -1;
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

char *get_current_date() {
    static char exp[11];
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    strftime(exp, sizeof(exp), "%d/%m/%Y", tm_info);

    return exp;
}

char *add_1year(const char *exp) {
    static char exd[11];
    struct tm tm_info = {0};
    int day, month, year;

    sscanf(exp, "%d/%d/%d", &day, &month, &year);

    tm_info.tm_mday = day;
    tm_info.tm_mon = month - 1;
    tm_info.tm_year = year - 1900;

    tm_info.tm_year += 1;

    strftime(exd, sizeof(exd), "%d/%m/%Y", &tm_info);

    return exd;
}

int insert_user(){
    struct user_insert uis[100];
    int user_id;
    char tel[20] = {0}, confirm[5] = {0}, chr_user_id[100];
    char *exp = get_current_date();
    char *exd = add_1year(exp);
    
    user_id = get_id_from_log("current_user_id");
    if (user_id == -1) {
        printf("Error reading current user id from log file.\n");
        return -1;
    }

    while (1)
    {
        printf("Current ID  : %d\n", user_id);
        printf("Enter Tel   : ");
        fgets(tel, sizeof(tel), stdin);
        tel[strcspn(tel, "\n")] = '\0';

        while ((strlen(tel) > 10) || (strlen(tel) < 8)){
            printf("Invalid!. Enter Tel   : ");
            fgets(tel, sizeof(tel), stdin);
            tel[strcspn(tel, "\n")] = '\0';
        }

        printf("confirm(y/n): ");
        fgets(confirm, sizeof(confirm), stdin);
        confirm[strcspn(confirm, "\n")] = '\0';

        printf("==============================================================\n");

        if (strcmp(confirm, "n") == 0) continue;
        if (strcmp(confirm, "c") == 0) break;
        
        if (strcmp(confirm, "y") == 0){
            itoa(user_id, chr_user_id, 10);
            strcpy(uis[user_id].user_id, chr_user_id);
            strcpy(uis[user_id].user_tel, tel);
            strcpy(uis[user_id].user_exp, exp);
            strcpy(uis[user_id].user_exd, exd);

            FILE *user_file;
            user_file = fopen("DB/userDB.dat", "at");
            if(user_file == NULL){
                printf("Error opening userDB.dat file for writing.\n");
                return -1;
            }
            fprintf(user_file, "%s,%s,%s,%s\n", uis[user_id].user_id, uis[user_id].user_tel, uis[user_id].user_exp, uis[user_id].user_exd);
            fclose(user_file);

            printf("Order added: ID :%s Tel :%s EXP :%s EXD :%s\n", uis[user_id].user_id, uis[user_id].user_tel, uis[user_id].user_exp, uis[user_id].user_exd);

            update_id_in_log("current_user_id", user_id+1);
            break;
        }
    }
    return 0;
}

int insert_order() {
    struct order_insert ois[100];
    int order_id;
    char order_name[30], order_price[10], confirm[5], chr_order_id[100];

    order_id = get_id_from_log("current_order_id");
    if (order_id == -1) {
        printf("Error reading current order id from log file.\n");
        return -1;
    }

    while (1)
    {
        printf("Current ID          : %d\n", order_id);
        printf("Enter Order Name    : ");
        fgets(order_name, sizeof(order_name), stdin);
        order_name[strcspn(order_name, "\n")] = '\0';

        printf("Enter Order Price   : ");
        fgets(order_price, sizeof(order_price), stdin);
        order_price[strcspn(order_price, "\n")] = '\0';

        printf("confirm (y/n)       : ");
        fgets(confirm, sizeof(confirm), stdin);
        confirm[strcspn(confirm, "\n")] = '\0';
        if (strcmp(confirm, "n") == 0) continue;
        if (strcmp(confirm, "c") == 0) break;
        
        if (strcmp(confirm, "y") == 0){
            itoa(order_id, chr_order_id, 10);
            strcpy(ois[order_id].order_id, chr_order_id);
            strcpy(ois[order_id].order_name, order_name);
            strcpy(ois[order_id].order_price, order_price);
        
        printf("==============================================================\n");

        FILE *file = fopen("DB/orderDB.dat", "at");
        if (file == NULL){
            printf("Error opening orderDB.dat file for writing.\n");
            return -1;
        }

        fprintf(file, "%s,%s,%s\n", ois[order_id].order_id, ois[order_id].order_name, ois[order_id].order_price);
        fclose(file);

        printf("Order added: ID :%s Name :%s Price :%s\n", ois[order_id].order_id, ois[order_id].order_name, ois[order_id].order_price);

        update_id_in_log("current_order_id", order_id+ 1);
        break;
        }
    }
    return 0;
}