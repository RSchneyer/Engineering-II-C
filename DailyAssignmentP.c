//Reid Schneyer
//Daily Assignment P
//10-22-2018
//Number Game

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    //Seed the random number generator with the UNIX timestamp (I think)
    srand(time(NULL));
    //Set a random int between 10 and 40
    int r = (rand() % 40 ) + 10;
    int g;
    printf("Thinking of a number between 10 and 40...");


    if(r % 2 == 0){
        printf("\nHint: It is even.");
    }
    if(r%3==0){
        printf("\nHint: It is a multiple of 3.");
    }
    if(r%5==0){
        printf("\nHint: It is a multiple of 5.");
    }
    if(r%7==0){
        printf("\nHint: It is a multiple of 7.");
    }

    printf("\nWhat's your guess? ");
    scanf("%d", &g);

    if(g == r){
        printf("\nHey! You cheated!");
    }
    else{
        printf("\nlol get gud kiddo");
    }

//    printf("\n(it was %d)", r);



    return 0;
}
