// Reid Schneyer
// Daily Assignment Q Part 2
// 10-24-18

#include <stdio.h>

int main(void){
    int lineCount;
    int plusCount;
    int x;

    for(lineCount = 5; lineCount > 0; lineCount--){

        for(plusCount = 0; plusCount<lineCount; plusCount++){
            printf("+ ");
        }

        for(x = 0; x<5;x++){
            printf("* ");
        }

        printf("\n");
    }




    return 0;
}
