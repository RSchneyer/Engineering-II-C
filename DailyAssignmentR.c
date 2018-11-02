//Reid Schneyer
// 10-30-18
//Daily Assignment R Part 1
//Print a sequence of numbers with a while loop and a do while loop
#include <stdio.h>

int main(void){
    int count = 0;
    int val = -142;
    printf("Printing numbers with while loop:\n");
    while(count < 8){
        printf("%d ", val);
        val += 22;
        count++;
    }

    printf("\nPrinting numbers with do while loop:\n");
    count = 0;
    val = -142;
    do{
        printf("%d ", val);
        val += 22;
        count++;
    } while(count<8);

    return 0;
}
