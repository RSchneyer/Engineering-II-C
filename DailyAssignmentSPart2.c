//Reid Schneyer
// 11-2-18
//Daily Assignment S Part 2
//Read data file

#include <stdio.h>

int main(void){
    int sum, count, currVal, minVal, maxVal, fifteens, fourtyTwos;
    double avg;

    FILE * inFile;
    inFile = fopen("fifteen.txt", "r");
    if(inFile == NULL){
        printf("ERROR: File not found");
    }

    count = 0;
    sum = 0;
    minVal = 116;
    maxVal = 0;
    fifteens = 0;
    fourtyTwos = 0;

    while(fscanf(inFile, "%d", &currVal)==1){
        sum += currVal;
        count++;
        if(currVal>maxVal){
            maxVal = currVal;
        }
        if(currVal<minVal){
            minVal = currVal;
        }
        if(currVal % 15 == 0){
            fifteens++;
        }
        if(currVal == 42){
            fourtyTwos++;
        }
    }
    avg = ((double) sum)/count;
    printf("Mean Val: %f\n", avg);
    printf("Largest Val: %d\n", maxVal);
    printf("Smallest Val: %d\n", minVal);
    printf("Amount of numbers divisible by 15: %d\n", fifteens);
    printf("Occurances of 42: %d\n", fourtyTwos);

    return 0;
}