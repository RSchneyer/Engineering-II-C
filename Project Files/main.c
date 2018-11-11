#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//I'm saving myself from typing 5 letters each time. It adds up, I swear
#define OUTFILE_NAME "xactlog.txt"

void createFileHeader(){
    FILE * outfile;
    outfile = fopen(OUTFILE_NAME, "w");
    if(outfile == NULL){
        printf("An error occurred writing to the file");
    }
    fprintf(outfile, "Type  |  Amount  |  Current Balance\n");
    fclose(outfile);
}

void logDeposit(double depositAmount, double newBalance){
    if(depositAmount<0.0){
        return;
    }
    FILE * outfile;
    outfile = fopen(OUTFILE_NAME, "a");
    if(outfile == NULL){
        printf("\nCan't open logfile!\n");
    }
    fprintf(outfile, "deposit  |  %.2f  |  %.2f\n", depositAmount, newBalance);
    fclose(outfile);
}

void logWithdrawal(double withdrawal){}

void logInterest(double interest){}

void logFee(double fee){}

double changeBalance(int promptType, double currentBalance){
    double balanceChange = 0.0;
    if(promptType == 0){
        printf("Deposit how much? ");
        scanf("%lf", &balanceChange);
    } 
    else{
        do{
            printf("Withdraw how much? ");
            scanf("%lf", &balanceChange);
        } while((currentBalance-balanceChange)>0.0);
        balanceChange *= -1;
    }
    return balanceChange;
}

void printMenu(){
    printf("\n");
    printf("SYSTEM MENU\n");
    printf("1 - Make a deposit\n");
    printf("2 - Make a withdrawl\n");
    printf("3 - Calculate Interest?\n");
    printf("4 - Apply a fee\n");
    printf("5 - Close your account\n");
    printf("Please enter your choice: ");
}

int getMenuSelection(){
    int selection = 0;
    while(selection<1 || selection>5){
        printMenu();
        scanf("%d", &selection);
    }
    return selection;

}

int main(void){
    //Delete old log file
    //Might not be the best way to do this: https://stackoverflow.com/questions/19913446/why-should-the-system-function-be-avoided-in-c-and-c
    int status = system("rm xactlog.txt");
    if(status == 0){//If the file got deleted 
        createFileHeader();

        int actionSelection = 1;
        double balance, APR;

        printf("Welcome to Reid's Banking Simulator! Please enter your starting balance: ");
        scanf("%lf", &balance);
        logDeposit(balance, balance);

        while(actionSelection>0 && actionSelection<5){
            actionSelection = getMenuSelection();
            printf("Selected menu action: %d\n", actionSelection);
            double balanceChange;
            switch(actionSelection){
                case 1:
                    //Make a deposit
                    balanceChange = changeBalance(0, balance);

                    break;
                case 2:
                    //Make a withdrawl
                    break;
                case 3:
                    //Calculate interest
                    break;
                case 4:
                    //Apply a fee
                    break;
            }

        }




    }
    return 0; 
}


