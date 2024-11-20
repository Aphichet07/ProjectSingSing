#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ItemOrder{
    char ID[99];
    char NameProduct[99];
    char price[99];
};

struct UserOrder{
    char IDorder[99];
};



struct ItemOrder AllOrder[99];
struct UserOrder userorder[99];
int n=0;
void splitData(char sen[99]){
    int i,j,k=0;
    j = strlen(sen);
    for(i=0;;i++){
        if(sen[i] == ','){
            AllOrder->ID[k++] = '\0';
            break;
        }
        AllOrder->ID[k++] = sen[i];
    }
    k=0;

    for(i=i+1;;i++){
        if(sen[i] ==','){
            AllOrder->NameProduct[k++] = '\0';
            break;
        }
        AllOrder->NameProduct[k++] = sen[i];
    }
    k=0;
    for(i=i+1;i<j;i++){
        if(sen[i] ==','){
            AllOrder->price[k++] = '\0';
            break;
        }
        AllOrder->price[k++] = sen[i];
    }

}

void ShowOrderItem(){
    FILE *fp;
    char buffer[99];
    int i,j=1,k=1;
    fp = fopen("Itim.txt","r");
    for(;;){
        fgets(buffer,255,fp);
        if (feof(fp)!=0){
            break;
        }
        splitData(buffer);
        n++;
        printf("%s%s%s\n",AllOrder->ID,AllOrder->NameProduct, AllOrder->price);
    }
    extern struct AllOrder;

}

void InputUserOrder(char id, int index){
    FILE *user;
    user = fopen("want.txt","wt");
    fprintf(user,"%s\n", id);
    userorder->IDorder[index] = id;
    fclose(user);
}


void ShowUserOrder(int index){
    FILE *user;
    char buffer[99];
    user = fopen("userOrder.txt","rt");
    fscanf(user,"%s", &buffer);
    printf("%s",buffer);
}

void ClearUserOrder(char path[]){
    FILE *file;
    int i =0;
    file = fopen(path, "wt");
    for(i ;;i++){
        if (feof(file)){
            break;
        }


    }
    printf("--------SUCCESS---------\n");
}




extern struct AllOrder;
extern struct UserOrder;
extern int n;
