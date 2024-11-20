#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
    int ID[100];
} Customer;

typedef struct {
    char Name[100][255];
    double price[100];
} Name;

typedef struct {
    int ID;
    char name[255];
    double price;
} Item;
float total=0;

void splitOrderDataVerBank(char *sen, Item *itim) {
    sscanf(sen, "%d,%254[^,],%lf", &itim->ID, itim->name, &itim->price);
}


void displayReceipt() {
    FILE *order, *find;
    char buffer1[99], buffer2[255];
    int i = 0, j = 0, number;
    Customer customer = {0};
    Name name = {0};
    Item itim;


    order = fopen("want.dat", "r");
    if (!order) {
        perror("Error opening want.txt");
        return;
    }

    while (fgets(buffer1, sizeof(buffer1), order) != NULL) {
        if (sscanf(buffer1, "%d", &number) == 1) {
            customer.ID[i++] = number;
        }
    }
    fclose(order);


    find = fopen("itim.dat", "r");
    if (!find) {
        perror("Error opening OrderMenu.dat");
        return;
    }

    while (fgets(buffer2, sizeof(buffer2), find) != NULL) {
        splitOrderDataVerBank(buffer2, &itim);

        for (int k = 0; k < i; k++) {
            if (itim.ID == customer.ID[k]) {
                strcpy(name.Name[j], itim.name);
                name.price[j] = itim.price;
                total += itim.price;
                j++;
                break;
            }
        }
    }
    fclose(find);


    for (int k = 0; k < j; k++) {
        printf("|         %-20s      %59.f                        |\n", name.Name[k], name.price[k]);
    }
}

    //--------- display name{struct}--------------------

void display(){
    printf("\n=======================================================================================================================\n");
    printf("|                   |                                                                                                  |\n");
    printf("|   Ice Keen Magic  |                                ** Receipt **                                                     |\n");
    printf("|___________________|                       --------------------------------                                           |\n");
    printf("|                                          |      Name: ___________________ |                                          |\n");
    printf("|                                          |     Receipt No:                |                                          |\n");
    printf("|                                           --------------------------------                                           |\n");
    printf("|                                                                                                                      |\n");
    printf("|         Item Name                                                                        Price                       |\n");
    printf("|      -----------------------------------------------------------------------------------------------------           |\n");
    displayReceipt();
    printf("|     ------------------------------------------------------------------------------------------------------           |\n");
    printf("|                                                                                                                      |\n");
    printf("|                                                                             Total Amount:  $%.f                       |\n",total);
    printf("|                                                                                                                      |\n");
    printf("|                           _________________________________________________________________                          |\n");
    printf("=======================================================================================================================\n");
}

