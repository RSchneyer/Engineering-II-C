//Reid Schneyer
// 10-30-18
// Daily Assignment R Part 2
//User input int between 1 and 6, print numbers they didn't pick

#include <stdio.h>

int main(void){
    int userInput = 0;
    int validNum = 0;
    int i;

    //While they haven't entered a validNumber
    while(validNum == 0){
        printf("Enter a number between 1 and 6: ");
        scanf("%d", &userInput);
        if(userInput <= 6 && userInput >= 1){
            //If they enter a valid number, set validNum != 0 to break out of while loop
            validNum = 1;
        }
    }

    printf("You didn't pick: \n");
    for(i = 1; i<7; i++){
        if(i!=userInput){
            printf("%d ", i);
        }
    }
    return 0;

}
