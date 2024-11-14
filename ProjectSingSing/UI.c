#define Max 31

void Login(){
    for(int i=0;i<Max;i++){
        for (int j=0;j<Max;j++){
            if (i==0 || i == Max-1){
                printf("#");
            }

            if (j==0||j==Max-1){
                printf("#");
            }else{
                printf("");
            }
        }
        printf("\n");
    }
}