// Reid Schneyer
// 11-7-18
// Daily Assignment T Part 1

#include <stdio.h>

int main(void){
    int numz[10] = {1,0,5,0,3,0,5,0,1,9000};
    int newArray[10] = {100,1,9,2,8,3,7,4,6,5};
    int i1, i2, i3;
    
    printf("The initial array: \n");
    
    for(i1=0; i1<10; i1++){
        printf("%d ",numz[i1]);
        numz[i1] = newArray[i1];
    }




    printf("\n");
    return 0;
}