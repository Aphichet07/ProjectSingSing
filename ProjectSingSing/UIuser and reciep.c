#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void split(char buff[50]);
struct ICEKEEN{
    char price[20],userID[50],userName[50];
}user;
void displayReceipt() {
    printf("\n============================================================================\n");
    printf("|                   |                                                      |\n");
    printf("|   Ice Keen Magic  |            ** Receipt **                             |\n");
    printf("|___________________|  --------------------------------                    |\n");
    printf("|                     |      Name: ___________________ |                   |\n");
    printf("|                     |     Receipt No:                |                   |\n");
    printf("|                      --------------------------------                    |\n");
    printf("|                                                                          |\n");
    printf("|     Item Name                      Quantity            Price             |\n");
    printf("|     -------------------------------------------------------------------  |\n");
    printf("|     1. Ice Cream Cone                 2                $0.00             |\n");
    printf("|     2. Chocolate Bar                  1                $0.00             |\n");
    printf("|     3. Soft Drink                     3                $0.00             |\n");
    printf("|     4. Cookies                        1                $0.00             |\n");
    printf("|     5. Sprinkles                      1                $0.00             |\n");
    printf("|     6. Waffle                         2                $0.00             |\n");
    printf("|     -------------------------------------------------------------------  |\n");
    printf("|                                                                          |\n");
    printf("|                          Total Amount: $Free                             |\n");
    printf("|                                                                          |\n");
    printf("|     _________________________________________________________________    |\n");
    printf("============================================================================\n");
}
void memberLogin() {
    FILE *id;
    char uid[10];
    char buff[50];
    int flag  = 0;
    for (;;)
    {
        printf("\n=========================================================\n");
        printf("|                   *Member - Login*                    |\n");
        printf("=========================================================\n");
        printf("| Enter User ID: ");
        scanf("%s", &uid);
        id = fopen("id-name.text","rt");
            for (;;)
            {
                fgets(buff,50,id);
                if(feof(id) != 0)break;
                split(buff);
                if (strcmp(user.userID,uid)== 0){
                    printf("\nLogin successful!\n");
                    break;
                }
            }
        printf("\n!You entered the wrong ID!\n");
        printf("userid  : %s\n",user.userID);
        fclose(id);
        
    }
}
void memberRegistration() {
    FILE *id;
    id = fopen("id-name.text","at");
    printf("\n=========================================================\n");
    printf("|                      *Register*                       |\n");
    printf("=========================================================\n");
    printf("| Enter ID: ");
    scanf("%s",user.userID);
    fflush(stdin);
    printf("| Enter Name: ");
    scanf("%s",user.userName);
    fprintf(id,"%s,%s",user.userID,user.userName);
    printf("\nRegistration successful! Welcome, %s!\n", user.userName);
    fclose(id);
    memberLogin();
}
void mainFlow() {
    char response;
    int flag=0;
    
    for (;;)
    {
        if (flag == 0)
        {
            printf("\n=====================================================\n");
            printf("|  |ICE KEEN|                               _\\_     |\n");
            printf("|  |________|                              / K \\    |\n");
            printf("|                                          \\___/    |\n");
            printf("|             DO YOU HAVE A MEMBER  ???             |\n");
            printf("|                                                   |\n");
            printf("|      / \\                                          |\n");
            printf("|    / / \\ \\    [ Y ] Yes*   [ N ] No*              |\n");
            printf("|   |_______|                                       |\n");
            printf("|    | ICE |                                        |\n");
            printf("|     |___|                                         |\n");
            printf("=====================================================\n");
            printf("|Do you have a membership? (Y/N):  ");
            scanf(" %c", &response);
            if (response == 'Y' || response == 'y') {
                    flag = 1;
                    memberLogin();
                    displayReceipt();
                    break;  
            } else if (response == 'N' || response == 'n') {
                    flag = 1;
                    memberRegistration(); 
                    displayReceipt();
                    break; 
            } else {
                    printf("\nInvalid input. Please enter Y or N.\n");
                    break;
            }
            printf("\n");
                
        }        
    }
    
}
void split(char buff[50])
{
    int len,i,j=0;
    len = strlen(buff);
    for ( i = 0;; i++)
    {
        if (buff[i] == ','){user.userID[j++] = '\0';
        break;}
        user.userID[j++] = buff[i];
    }
    j = 0;
    for ( i = i + 1;; i++)
    {
        if (buff[i]==',')
        {
            user.userName[j++] = '\0';
            break;
        }
        user.userName[j++] = buff[i];
    }
}
int main() {
    for (;;)
    {
        mainFlow();
    }
    return 0;
}
