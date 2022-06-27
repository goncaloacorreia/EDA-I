#include<stdio.h>

int main(){
    
    int disp[3][3] = {
        {1, 2, 2,},
        {2, 1, 2,},
        {2, 2, 1,}
    };
    
    int i, j;
    int newdisp[3][3]={};
    for(i=0; i<3; i++) { 
        for(j=0;j<3;j++) {
        newdisp[j][i] = disp[i][j];
        }
    }

    int s = 1;
    for(i=0; i<3; i++) { 
        for(j=0;j<3;j++) {
            if(disp[i][j] != newdisp[i][j]){
                s = 0;
                break;
            }
        }
    }

    if(s == 1){
        printf("É simétrica\n");
    } 
    else{
        printf("Não é simétrica\n");
    }
    

    return 0 ;
}
