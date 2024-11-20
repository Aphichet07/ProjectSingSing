#include <stdio.h>

struct UserManage{
    char log[99];
    char ID[99];
    char Date[99];
    char ExDate[99];
};
/*
    1,0822515946,19/11/2024,19/11/2025
*/
struct UserManage Ma[99];

void splitAData(char sen[99]){
    int i,j,k=0;
    j = strlen(sen);
    for(i=0;;i++){
        if(sen[i] == ','){
            Ma->log[k++] = '\0';
            break;
        }
        Ma->log[k++] = sen[i];
    }
    k=0;
    for(i=i+1;;i++){
        if(sen[i] == ','){
            Ma->ID[k++] = '\0';
            break;
        }
        Ma->ID[k++] = sen[i];
    }
    k=0;
    for(i=i+1;;i++){
        if(sen[i] == ','){
            Ma->Date[k++] = '\0';
            break;
        }
        Ma->Date[k++] = sen[i];
    }
    k=0;
    for(i=i+1;i<j;i++){
        if(sen[i] == ','){
            Ma->ExDate[k++] = '\0';
            break;
        }
        Ma->ExDate[k++] = sen[i];
    }
}


int checkUser(char sen[]){
    FILE *user;
    char buffer[99];
    int i=0;
    user = fopen("userDB.dat","r");
    while(!feof(user)){
        fgets(buffer,255,user);
        splitAData(buffer);
        if (strcmp(sen,Ma->ID)==0){
            return 1;
        }
        else{
            return 0;
        }
    }
}
