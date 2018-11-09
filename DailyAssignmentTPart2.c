// Reid Schneyer
// 11-7-18
// Daily Assignment T Part 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    int randArray[5];
    int occurances[] = {0,0,0,0};
    int i, x;
    for(i=0;i<5;i++){
        randArray[i] = (rand() % 4) + 1;
    }
    printf("\nThe Array is: ");

    for(i=0;i<5;i++){
        printf("%d ", randArray[i]);
        ++occurances[(randArray[i]-1)]; 
    }
    printf("\n");
    for(x=0;x<4;x++){
        // printf("%d", occurances[x]);
        if(occurances[x]>1){
            printf("The number %d occurred %d times\n", (x+1), occurances[x]);
        }
    }

    printf("\n");
    return 0;
}