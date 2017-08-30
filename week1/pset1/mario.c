#include <cs50.h>
#include <stdio.h>
    
int main(void){ 
    
    printf("Height:");
    int h = get_int();
    int n = 1;

    
    if (h < 0){
        printf("Try a positive height!:");
        h = get_int();
    }
    if(h > 23){
        printf("Try a smaller Height:");
        h = get_int();
    }
    
    while (h > 0 && h < 24){
        
        for (int j = 1; j < h; j++){
            printf(" ");
        }
        
        for (int k = 0; k < n; k++){
            printf("#");
        }
        
        printf("  ");
        
        for (int k = 0; k < n; k++){
            printf("#");
        }
            
        /*for (int j = 0; j < h; j++){
            printf(".");
        }*/   
        /*this is not necessary, you just have to print space first, not later*/
        printf("\n");
        n++;
        h--;
    }


}
