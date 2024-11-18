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

int log_id_to_int(void){
    int current_id;
    char Floger[30];
    FILE *log;
    log = fopen("DB/logDB.dat", "rt");
    fscanf(log, "%s", &Floger);
    fclose(log);
    char *ptr = strchr(Floger, ':');
    if(ptr != NULL){
        current_id = atoi(ptr + 1);
    }
    return current_id;
}

int update_log_id(int new_id){ 
    FILE *log; 
    if((log = fopen("DB/logDB.dat", "wt")) == NULL){
        printf("Error opening log file for writing\n"); 
        return 1; 
        } 
    fprintf(log, "current_user_id:%d", new_id); 
    fclose(log);
}
int main(){
    struct user_insert uis[100];
    int log;
    char tel[20] = {0}, confirm[5] = {0}, chr_log[100];
    
    log = log_id_to_int();
    if(log < 0) printf("Error at log file!");

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
            fprintf(user_file, "%s,%s,%s,%s", uis[log].user_id, uis[log].user_tel, uis[log].user_exp, uis[log].user_exd);
            fclose(user_file);

            log++;
            update_log_id(log);
            break;
        }
    }
    return 0;
}

int insert_order(){
    
}