//Reid Schneyer
//Daily Assignment Q Part 1
//10-24-18
// Number Sequence

#include <stdio.h>

int main(void){
    int count;
    int num=757;
    printf("%d ",num);
    for(count = 0; count<7;count++){
        num -= 159;
        printf("%d ", num);
    }
    return 0;
}
