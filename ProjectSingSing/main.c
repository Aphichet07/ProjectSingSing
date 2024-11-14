#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 31

void Login(){
    for(int i=0;i<Max;i++){
        for (int j=0;j<Max;j++){
            if (i==0 || i==Max-1 ||j==0||j==Max-1){
                printf("#");
            }
            printf(" ");
            
        }
        printf("\n");
    }
}
int main(){
    Login();
}