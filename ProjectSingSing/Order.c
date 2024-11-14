#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Order{
    char price[99];
    char ItimName[99];
};

static struct Order order[99];

int OrderMenu(){
    FILE *fp;
    char buffer[20];
    fp = fopen("OrderMenu.dat", "at");
    
    

    


}   