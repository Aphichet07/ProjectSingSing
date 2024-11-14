#include <stdio.h>
void printUI(){
    int i,j,n=101;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==0 || i== 50){
                printf("#");
                continue;
            }
            if(j==0 || j== n-1) printf("#");
            else printf(" ");
            
        }
        printf("\n");
        if(i==50)   break;
    }
    
}