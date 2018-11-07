
#include <stdio.h>
#include <time.h>

//I'm saving myself from typing 5 letters each time. It adds up, I swear
#define OUTFILE_NAME "xactlog.txt"

void logClosure(int num){
    FILE * outFile;
    //Use "a" to append to file, instead of overwriting it
    outFile = fopen(OUTFILE_NAME, "a");
    if(outFile == NULL){
        printf("CANT OPEN FILE");
    }
    fprintf(outFile, "your number is: %d\n", num);
    fclose(outFile);
}

void logDeposit(double deposit){}

void logWithdrawal(double withdrawal){}

void logInterest(double interest){}

void logFee(double fee){}


int main(void){
    double balance, APR;

    
    return 0; 
}


