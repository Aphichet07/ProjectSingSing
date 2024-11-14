#include <stdio.h>

struct user
{
    char id[4];
    char name[50];
    char tel[10];
    char exp[10];
    char exd[10];
};

int insert_user(){

    struct user u[100];
    int mode;

    FILE *user;
    user = fopen("user.dat", "rt");
    if(user == NULL){
        mode = 1;
    }
    fclose(user);
    if(mode == 1){
        user = fopen("user.dat", "wt");
        printf("MODE : write");
    }
    if(mode != 1){
        user = fopen("user.dat", "at");
        printf("MODE : append");
    }
    fclose(user);

    
}