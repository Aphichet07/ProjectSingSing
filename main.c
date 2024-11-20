#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

#include "insertIntoDB.c"
#include "createDB.c"
#include "userManage.c"
#include "receipt.c"
#include "Order.c"
#include "UI.c"

struct Uorder{
    char ID[99];
};

pid_t child_id;



void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}



int main(){
    FILE * fb;
    FILE *logC, *userC, *orderC;
    struct Uorder u[99];
    int index =0,userState=0,loginState=1;
    char buffer[99],Norder[99],LQ,member[99],getOption,reState;
    logC = fopen("logDB.dat", "rt");
    if (logC == NULL) loger();
    else fclose(logC);

    userC = fopen("userDB.dat", "rt");
    if (userC == NULL) creat_user_db();
    else fclose(userC);

    orderC = fopen("orderDB.dat", "rt");
    if (orderC == NULL) creat_order_db();
    else fclose(orderC);
    intro2();
    Sleep(1000);
    clear();
    ShowOrder();
    fb = fopen("want.dat","wt");
    for(int i=0;;i++){
        printf("Enter your order (press '0' to pay): ");
        scanf("%d",&Norder[i]);
        if (Norder[i] == 0){
            break;
        }
        fprintf(fb,"%d\n" ,Norder[i]);
        index++;
        clear();
        ShowOrder();
    }
    clear();
    Sleep(1000);
    ways();
    printf("Enter : ");
    scanf("%s",&LQ);
    while(loginState){
    switch (LQ){
        case 'y':
            a:
                clear();
                memberLogin();
                printf("Enter your number ID :");
                scanf("%s",&member);
                if (checkUser(member)){
                    loginState = 0;
                    printf("-----------Login Successful-----------");
                    getch();
                    clear();
                    Sleep(1000);
                    display();
                }else{
                    printf("------Member not found------\n");
                    printf("Would you like to register?(y/n)\n");
                    printf("Enter : ");
                    scanf("%s",&reState);
                    if (reState == 'y'){
                        clear();
                        memberRegistration();
                        insert_user();
                    }else{
                        display();
                        }
                }
                break;
        case 'n':
                clear();
                memberRegistration();
                insert_user();
                goto a;
                break;
        }
    }
    fclose(fb);
    return 0;
}
