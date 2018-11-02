//Reid Schneyer
//Daily Assignment N
//10-12-2018
//Haiku program
//Assuming "zero" & "seven" are two syllables and "eleven" is three

#include <stdio.h>
#include <time.h>
int main(){
    time_t seconds;

    int userInput;
    printf("Zero One Two Three\nFour Five Six Seven Eight Nine\nTen Eleven Twelve\n");
    printf("Please enter your score: \n");
    scanf("%d", &userInput);
    printf("You rated the haiku: %d\n", userInput);

    seconds = time(NULL);
    printf("%ld", seconds);

}
